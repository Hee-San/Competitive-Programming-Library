/**
 * @brief LCM(最小公倍数)
 * @docs docs/math/number_theory/my_lcm.md
 */

#include <bits/stdc++.h>

template <typename T>
T my_lcm(T a, T b) {
    return a / gcd(a, b) * b;
}
