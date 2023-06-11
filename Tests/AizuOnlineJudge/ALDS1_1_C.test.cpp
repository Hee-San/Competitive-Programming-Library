#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C"
/**
 * @brief 素数判定
 */

#include <bits/stdc++.h>

#include "../../math/is_prime.cpp"

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

int main() {
  ll n;
  cin >> n;

  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    if (is_prime(x)) ans++;
  }

  cout << ans << endl;
}
