#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
/**
 * @brief 区間和
 */

#include <bits/stdc++.h>

#include "../../../structure/cumulative_sum.cpp"

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

int main() {
    ll N, Q;
    cin >> N >> Q;

    vi A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    CumulativeSum<ll> sumA(A);

    for (ll i = 0; i < Q; i++) {
        ll l, r;
        cin >> l >> r;
        cout << sumA.get(l, r) << endl;
    }
}
