#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N{};
    set<int> cache{};
    cin >> N;

    for(int i{}; i < N; ++i) {
        int x{};
        cin >> x;
        cache.insert(x);
    }

    cout << cache.size();

    return 0;
}