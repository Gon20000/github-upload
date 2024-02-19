#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cnt{};
string res{};

void solve(int pos, ll sum, string num) {
    if(sum > 10 || !res.empty()) 
        return;
    
    if(pos == 8) {
        if(sum == 10)
            --cnt;

        if(cnt == 0) {
            res = num;
        }
        return;
    }

    for(int i{}; i <= 9; ++i) {
        solve(pos + 1, sum + i, num == "" && i == 0 ? "" : num + to_string(i));
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    res = "";
    cin >> cnt;
    solve(0, 0, "");

    cout << res << '\n';
    return 0;
}