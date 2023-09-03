#include <bits/stdc++.h>
using namespace std;

int main() {
     ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int a{}, b{}, c{}, d{};
    cin >> a >> b >> c >> d;
    int res{};

    if (b < c || d < a)
        res = (b - a) + (d - c);
    else
        res = max(d,b) - min(a,c);
    cout << res;
    return 0;
}