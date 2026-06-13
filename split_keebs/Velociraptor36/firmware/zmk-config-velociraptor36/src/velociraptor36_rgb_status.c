/*
 * Copyright (c) 2026
 *
 * SPDX-License-Identifier: MIT
 */

#include <stdint.h>

#include <zephyr/init.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/util.h>

#include <zmk/ble.h>
#include <zmk/event_manager.h>
#include <zmk/events/ble_active_profile_changed.h>
#include <zmk/rgb_underglow.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#define RGB_EFFECT_SOLID 0

static const struct zmk_led_hsb profile_colors[] = {
    {h : 0, s : 100, b : 80},   /* Profile 0: red */
    {h : 120, s : 100, b : 80}, /* Profile 1: green */
    {h : 240, s : 100, b : 80}, /* Profile 2: blue */
};

static const struct zmk_led_hsb power_color = {h : 0, s : 0, b : 80};
static const struct zmk_led_hsb paired_color = {h : 180, s : 100, b : 80};

static struct k_work_delayable flash_work;
static struct zmk_led_hsb flash_color;
static uint8_t flash_steps_remaining;
static uint8_t active_profile;
static uint8_t last_profile = UINT8_MAX;
static bool last_connected;
static bool last_open = true;

static bool profile_has_color(uint8_t profile) { return profile < ARRAY_SIZE(profile_colors); }

static struct zmk_led_hsb color_for_profile(uint8_t profile) {
    return profile_has_color(profile) ? profile_colors[profile] : power_color;
}

static void show_color(struct zmk_led_hsb color) {
    zmk_rgb_underglow_select_effect(RGB_EFFECT_SOLID);
    zmk_rgb_underglow_set_hsb(color);
    zmk_rgb_underglow_on();
}

static void show_active_profile(void) { show_color(color_for_profile(active_profile)); }

static void flash_handler(struct k_work *work) {
    if (flash_steps_remaining == 0) {
        show_active_profile();
        return;
    }

    if ((flash_steps_remaining % 2) == 1) {
        zmk_rgb_underglow_off();
    } else {
        show_color(flash_color);
    }

    flash_steps_remaining--;
    k_work_reschedule(&flash_work, K_MSEC(CONFIG_VELOCIRAPTOR36_RGB_STATUS_FLASH_MS));
}

static void start_flash(struct zmk_led_hsb color, uint8_t flashes) {
    k_work_cancel_delayable(&flash_work);

    flash_color = color;
    flash_steps_remaining = (flashes * 2) - 1;

    show_color(flash_color);
    k_work_reschedule(&flash_work, K_MSEC(CONFIG_VELOCIRAPTOR36_RGB_STATUS_FLASH_MS));
}

static int rgb_status_listener(const zmk_event_t *eh) {
    const struct zmk_ble_active_profile_changed *ev = as_zmk_ble_active_profile_changed(eh);

    if (ev == NULL) {
        return ZMK_EV_EVENT_BUBBLE;
    }

    const uint8_t profile = ev->index;
    const bool connected = zmk_ble_profile_is_connected(profile);
    const bool open = zmk_ble_profile_is_open(profile);
    const bool profile_changed = profile != last_profile;
    const bool paired = last_profile == profile && last_open && !open;
    const bool connected_now = last_profile == profile && !last_connected && connected;

    active_profile = profile;
    last_profile = profile;
    last_connected = connected;
    last_open = open;

    if (paired || connected_now) {
        start_flash(paired_color, 3);
    } else if (profile_changed && profile_has_color(profile)) {
        start_flash(color_for_profile(profile), 2);
    }

    return ZMK_EV_EVENT_BUBBLE;
}

ZMK_LISTENER(velociraptor36_rgb_status, rgb_status_listener);
ZMK_SUBSCRIPTION(velociraptor36_rgb_status, zmk_ble_active_profile_changed);

static int rgb_status_init(void) {
    k_work_init_delayable(&flash_work, flash_handler);

    active_profile = zmk_ble_active_profile_index();
    last_profile = active_profile;
    last_connected = zmk_ble_profile_is_connected(active_profile);
    last_open = zmk_ble_profile_is_open(active_profile);

    start_flash(power_color, 3);

    return 0;
}

SYS_INIT(rgb_status_init, APPLICATION, CONFIG_VELOCIRAPTOR36_RGB_STATUS_INIT_PRIORITY);
