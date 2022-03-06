/**
 * @brief LCM(最小公倍数)
 * @docs docs/math/number_theory/my_lcm.md
 */

#include "../../math/number_theory/my_gcd.cpp"

template <typename T>
T my_lcm(T a, T b) {
    return a / my_gcd(a, b) * b;
}
