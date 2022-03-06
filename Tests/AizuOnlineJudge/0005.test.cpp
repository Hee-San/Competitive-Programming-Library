#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0005"
/**
 * @brief 最大公約数と最小公倍数
 */

#include <bits/stdc++.h>

#include "../../math/number_theory/my_gcd.cpp"
#include "../../math/number_theory/my_lcm.cpp"

using namespace std;
typedef long long ll;

int main() {
    ll a, b;
    while (cin >> a >> b) {
        cout << my_gcd(a, b) << " " << my_lcm(a, b) << endl;
    }
}
