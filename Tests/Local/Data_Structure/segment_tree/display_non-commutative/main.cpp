#include <bits/stdc++.h>

#include "../../../../../structure/segment_tree/segment_tree_v1.cpp"

using namespace std;

int main() {
    int N;
    cin >> N;

    vs A(N);
    rep(i, N) cin >> A[i];

    SegmentTree<string> seg(N, [](string a, string b) { return a + b; }, "");
    seg.build(A);

    vs B = seg.seg;
    rep(i, B.size()) {
        cout << i << ": " << B[i] << endl;
    }
    cout << endl;

    function<string(string)> f = [](string a) { return a; };
    display(seg, f, 0);
    cout << endl;
    display(seg, f, 1);
}
