/**
 * @brief LCM(最小公倍数)
 * @docs docs/math/my_lcm.md
 */

#include "my_gcd.cpp"

template <typename T>
T my_lcm(T a, T b) {
    return a / my_gcd(a, b) * b;
}
