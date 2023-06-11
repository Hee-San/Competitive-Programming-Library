/**
 * @brief change base(進数変換)
 * @docs docs/math/change_base.md
 */

#include <bits/stdc++.h>

using namespace std;

template <typename T>
string base_10_to_N(T n, int base) {
    if (n == 0) return "0";
    string s = "";
    while (n) {
        s += (n % base) + '0';
        n /= base;
    }
    reverse(s.begin(), s.end());
    return s;
}

template <typename T>
T base_N_to_10(string s, int base) {
    T n = 0;
    for (int i = 0; i < s.size(); i++) {
        n *= base;
        n += (s[i] - '0');
    }
    return n;
}

template <typename T>
string change_base(string s, int base_from, int base_to) {
    T n = base_N_to_10<T>(s, base_from);
    return base_10_to_N<T>(n, base_to);
}
