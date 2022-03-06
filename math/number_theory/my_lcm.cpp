#include "my_gcd.cpp"
/**
 * @brief LCM(最小公倍数)
 * @docs docs/math/number_theory/my_lcm.md
 */

template <typename T>
T my_lcm(T a, T b) {
    return a / my_gcd(a, b) * b;
}
