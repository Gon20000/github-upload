#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(int x, int y, const vector<ll>& sum) {
    if (x > y + 1) 
        return 0;
    else if ((sum[y] - sum[x - 1]) % 7 == 0)
        return y - x + 1;
    
    return max(solve(x, y - 1, sum), solve(x + 1, y, sum));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    
    int N{};
    cin >> N;
    
    vector<ll> sum{0};

    for(; N--;) {
        ll id{};
        cin >> id;

        if(sum.size() == 0)
            sum.push_back(id);
        else {
            sum.push_back(id + sum[sum.size() - 1]);
        }
    }

    cout << solve(1, sum.size() - 1, sum) << '\n';
    return 0;
}