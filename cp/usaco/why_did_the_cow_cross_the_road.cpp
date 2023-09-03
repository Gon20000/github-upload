#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    int N{}, res{};
    cin >> N;
    std::pair<int, int> cows[N];
    for(int i{}; i < N; ++i) {
        cin >> cows[i].first >> cows[i].second;
    }
    sort(cows, cows + N);

    for(auto [x,y] : cows) {
        res = max(res, x) + y;
    }

    std::cout << res << '\n';
    return 0;
}