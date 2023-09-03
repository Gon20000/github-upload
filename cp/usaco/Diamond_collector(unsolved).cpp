#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int N{}, K{}, res{};
    std::cin >> N >> K;
    map<int, int> diamonds{};
    for(int i{}; i < N; ++i) {
        int x{};
        std::cin >> x;
        diamonds[x]++;
    }

    auto start{diamonds.begin()};
    auto end{start};
    int temp{};
     while(end != diamonds.end()) {
        if(end->first - start->first <= K) {
            temp += end->second;
            ++end;
        }
        else {
            res = max(res, temp);
            ++start;
            temp = start->second;
            end = start;
            ++end;
        }
    }
    res = max(res, (--end)->second + start->second);

    std::cout << res << '\n';
    return 0;
}