#include <bits/stdc++.h>

#include "../../../../../structure/segment_tree/segment_tree_v1.cpp"

using namespace std;

int main() {
    int N;
    cin >> N;

    vi A(N);
    rep(i, N) cin >> A[i];

    SegmentTree<int> seg(N, [](int a, int b) { return a + b; }, 0);
    seg.build(A);

    vi B = seg.seg;
    rep(i, B.size()) {
        cout << i << ": " << B[i] << endl;
    }
    cout << endl;

    display(seg, 0);
    cout << endl;
    display(seg, 1);
}
