/**
 * @brief Cumulative Sum(累積和)
 * @docs docs/structure/cumulative_sum.md
 */

using namespace std;

template <typename T>
struct CumulativeSum {
    vector<T> cs;
    CumulativeSum(vector<T> A) {
        int n = A.size();
        cs.resize(n + 1);
        cs[0] = T();
        for (int i = 0; i < n; i++)
            cs[i + 1] = cs[i] + A[i];
    }

    // [l, r)
    T get(int l, int r) { return cs[r] - cs[l]; }
};