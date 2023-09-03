#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int X{}, Y{}, M{};
    cin >> X >> Y >> M;
    int res{Y * (M / Y)};

    for(int i{X}; i < M; i += X) {
        int temp{M - i};
        res = max(res, i + Y * (temp / Y));
        
    }

    std::cout << res << '\n';

    return 0;
 }