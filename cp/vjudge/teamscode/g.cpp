#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n{}, q{};
    cin >> n >> q;

    set<int> shields{-1};

    for(int i{1}; i <= q; ++i) {
        int x{};
        cin >> x;

        shields.insert(x);

        bool work{true};
        int prev{}, res{};

        for(int curr{i}; work; curr = prev + i) {
            if(curr >= n) {
                res += n - prev;
                break;
            }

            auto g{shields.upper_bound(curr)};
            
            int below{g != shields.end() ? *(--g) : *(--shields.end())};
            if(below == prev)
                work = false;

            res += i;
            prev = below;
        }
        
        cout << (work ? res : -1) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{1};
    //cin >> t;
   
    while(t--)
        solve();
    
    return 0;
}