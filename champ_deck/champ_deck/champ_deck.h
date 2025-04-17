#pragma once

#include "quantum.h"

#define LAYOUT( \
    k00, k01, k02, k03, k04, \
         k11, k12, k13       \
) { \
    { k00, k01, k02, k03, k04 }, \
    { KC_NO, k11, k12, k13, KC_NO } \
}

