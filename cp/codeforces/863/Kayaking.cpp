#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N{}, res{}, highest{};
    cin >> N;
    N *= 2;

    int x[N];
    for(int& a : x) 
        cin >> a;
    
    sort(x, x+N);
    for(int i{1}; i < N; i += 2) {
        res += x[i] - x[i - 1];
        highest = max(highest, x[i] - x[i - 1]);
    }

    cout << res - highest;
    return 0;
}