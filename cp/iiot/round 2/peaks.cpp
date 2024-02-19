#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* ll calc(int x, int y, const vector<ll>& a, const vector<ll>& b) {
    return a[x] * b[y];
}

bool check(int x, int y, const vector<ll>& a, const vector<ll>& b)  {
    ll curr{calc(x, y, a, b)};
    // left - right - top - bottom
    return !((y > 0 && calc(x, y - 1, a, b) >= curr) 
        || (y < b.size() - 1 && calc(x, y + 1, a, b) >= curr)
        || (x > 0 && calc(x - 1, y, a, b) >= curr)
        || (x < a.size() - 1 && calc(x + 1 , y, a, b) >= curr));
}
 */
int main() {
    int n{}, m{};
    cin >> n >> m;

    vector<ll> rows(n);
    vector<ll> cols(m);

    for(int i{}; i < n; ++i) {
        int x{};
        cin >> x;
        rows[i] = x;
    }

    for(int j{}; j < m; ++j) {
        int x{};
        cin >> x;
        cols[j] = x;
    }

    ll xes{}, yes{};
    for(int i{}; i < n; ++i) {
        if((i > 0 && rows[i - 1] >= rows[i]) || (i < n - 1 && rows[i] <= rows[i + 1]))
            continue;

        ++xes;
    }

    for(int i{}; i < m; ++i) {
        if((i > 0 && cols[i - 1] >= cols[i]) || (i < m - 1 && cols[i] <= cols[i + 1]))
            continue;

        ++yes;
    }

    cout << yes * xes << '\n';

    return 0;
}