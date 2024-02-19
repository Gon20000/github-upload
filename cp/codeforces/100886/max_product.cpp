#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// dp[n][above][under][started]
pair<ll, string> dp[19][2][2][2];
string l{}, r{};

void reset() {
    for(auto& w : dp) {
        for(auto& x : w) {
            for(auto& y : x) {
                for(auto& z : y) {
                    z = {-1, ""};
                }
            }
        }
    }
}

int digit(const string& str, int idx) {
    return str[idx] - '0';
}

// 1111 11

pair<ll, string> solve(size_t pos, bool above, bool under, bool started) {
    if(pos == r.size()) {
        if(!started)
            return {0, ""};
        
        return {1, ""};
    }

    if(dp[pos][above][under][started].first != -1)
        return dp[pos][above][under][started]; 

    int right{under ? 9 : digit(r, pos)};
    int left{above ? 0 : digit(l, pos)};

    pair<ll, string> res{-1, ""};
    for(; right >= left; --right) {
        /* 
        i > 0 -> started
        i < r[pos] -> under
        i > l[pos] -> above
        */
        
        bool newStarted{started || right > 0};
        bool newAbove{above || right > left};
        bool newUnder{under || right < digit(r, pos)};

        
        pair<ll, string> curr{solve(pos + 1, newAbove, newUnder, newStarted)};
        curr = {(newStarted ? right : 1) * curr.first, 
                (newStarted ? to_string(right) : "") + curr.second};
        if(curr.first > res.first) { 
            res = curr;
        }
    }

    return dp[pos][above][under][started] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    reset();

    cin >> l >> r;
    if(l == r) {
        cout << l << '\n';
        return 0;
    }

    while(l.size() < r.size()) {
        l = "0" + l;
    }

    cout << solve(0, false, false, false).second << '\n';

    return 0;
}