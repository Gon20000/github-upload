#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    /*cin.tie(nullptr);
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);*/
    int N{};
    std::cin >> N;

    map<int, int> ranges{};
    map<int, int> bursts{};

    for(int i{1}; i <= N; ++i) {
        int x{};
        cin >> x;

        ranges[x] = i;
        bursts[x] = 0;
    }

    for(auto it = bursts.begin(); it != bursts.end(); ++it) {
        int key = it->first;
        int index = ranges[key];
    }
}