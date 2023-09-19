#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll h1{}, h2{}, m1{}, m2{};
    double s1{}, s2{};
    char temp{}; 

    cin >> h1 >> temp >> m1 >> temp >> s1 >> h2 >> temp >> m2 >> temp >> s2;

    cout << static_cast<ll>((s2 - s1) * 1000 + (m2 - m1) * 60000 + (h2 - h1) * 60 * 60 * 1000) << '\n';
    
}