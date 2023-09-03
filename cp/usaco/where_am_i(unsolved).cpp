#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int n{}, res{1};
    cin >> n;
    unordered_map<char, int> count{};
    //vector<char> road{};

    while(n--) {
        char x{};
        cin >> x;
        ++count[x];
        //road.push_back(x);        
    }

    for(auto it = count.begin(); it != count.end(); ++it) {
        if(it->second != 1)
            ++res;
    }

    cout << res << '\n';
    return 0;
}