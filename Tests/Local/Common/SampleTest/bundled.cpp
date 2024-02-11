#line 1 "Tests/Local/verifyer/../Common/SampleTest/main.cpp"
// 2つの自然数を標準入力で受け取り、それらの和を標準出力する

#line 1 "common/common.cpp"
/**
 * @brief 共通設定
 * @docs docs/common/common.md
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
typedef vector<string> vs;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = (n)-1; i >= 0; i--)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); i++)
#line 4 "Tests/Local/verifyer/../Common/SampleTest/main.cpp"

int main() {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
}
