#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
a =  [3, 5, 1, 6, 2, 14, 10]
a_sum = [3, 8, 9, 15, 17, 31, 41] 

a % 7 = [3, 5, 1, 6, 2, 0, 3]
a_sum % 7 = [3, 1, 2, 1, 3, 3, 6]    
*/

int main() {
/*     ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout); */
    
    int N{};
    cin >> N;
    
    vector<ll> sum{0};

    for(; N--;) {
        ll id{};
        cin >> id;


        sum.push_back((id + sum[sum.size() - 1])%7);
    }

    for (ll x : sum) {
        cout  << x << ' ';
    } 
    return 0;
}