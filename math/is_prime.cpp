/**
 * @brief 素数判定
 * @docs docs/math/is_prime.md
 */

typedef long long ll;

bool is_prime(ll n) {
  if (n <= 1) return false;
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}
