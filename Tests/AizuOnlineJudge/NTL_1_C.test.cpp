#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_C"
/**
 * @brief LCM(最小公倍数)
 */

#include <bits/stdc++.h>

#include "../../math/my_lcm.cpp"

using namespace std;
typedef long long ll;

int main() {
  ll N;
  cin >> N;

  ll lcm = 1;
  for (ll i = 0; i < N; i++) {
    ll a;
    cin >> a;
    lcm = my_lcm(lcm, a);
  }

  cout << lcm << endl;
}
