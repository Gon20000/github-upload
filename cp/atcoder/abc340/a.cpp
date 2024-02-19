#include <bits/stdc++.h>
using namespace std;

int main() {
    int a{}, b{}, d{};
    cin >> a >> b >> d;

    vector<long long> res{};
    while(a <= b) {
        res.push_back(a);
        a += d;
    }
    
    for(int i{}; i < res.size() - 1; ++i)
        cout << res[i] << ' ';
    cout << res[res.size() - 1] << '\n';

    return 0;
}