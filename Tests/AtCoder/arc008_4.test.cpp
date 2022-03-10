#define PROBLEM "https://atcoder.jp/contests/arc008/tasks/arc008_4"
/**
 * @brief 非可換セグメント木、座標圧縮
 */

#include <bits/stdc++.h>

#include "../../structure/segment_tree/segment_tree.cpp"

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef long double ld;
typedef vector<ld> vd;
typedef pair<ld, ld> pld;

map<ll, int> press(vi a) {
    map<ll, int> m;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    for (int i = 0; i < a.size(); i++) m[a[i]] = i;
    return m;
}

int main() {
    ll N, M;
    cin >> N >> M;

    vi P(M);
    vd A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> P[i] >> A[i] >> B[i];
    }

    auto press_p = press(P);

    SegmentTree<pld> seg(
        press_p.size(),
        [](pld a, pld b) {
            return pld{a.first * b.first, a.second * b.first + b.second};
        },
        pld(1, 0));

    ld ans_min = 1;
    ld ans_max = 1;
    for (int i = 0; i < M; i++) {
        int p = press_p[P[i]];
        seg.update(p, pld(A[i], B[i]));
        pld res = seg.get(0, press_p.size());
        ld val = res.first + res.second;
        ans_min = min(ans_min, val);
        ans_max = max(ans_max, val);
    }

    cout << fixed << setprecision(10);
    cout << ans_min << endl;
    cout << ans_max << endl;
}
