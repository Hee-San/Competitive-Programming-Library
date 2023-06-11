/**
 * @brief GCD(最大公約数/ユークリッドの互除法)
 * @docs docs/math/my_gcd.md
 */
template <typename T>
T my_gcd(T a, T b) {
    if (a < b) return my_gcd(b, a);
    T r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}
