#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll a{}, b{};
    cin >> a >>  b;
    
    while(a <= b) {
        ll mid{a + (b - a)/2};
        
        cout << mid <<  endl;
        
        string str{};
        getline(cin >> ws, str);
        if(str == "selamat")
            break;
        else if(str == "terlalu kecil")
            a = mid + 1;
        else
            b = mid - 1;
    }
    return 0;
}
