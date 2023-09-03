#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int N{};
    cin >> N;
    int res[26]{};   

    for(int i{}; i < N; ++i) {
        string a{}, b{};
        cin >> a >> b;
        unordered_map<char, vector<int>> m{};

        for(char x : a) {
            if(m.count(x) < 1)
                m[x] = vector<int>(2);
            
            m[x][0] += 1;
        }

        for(char x : b) {
            if(m.count(x) < 1)
                m[x] = vector<int>(2);
            
            m[x][1] += 1;
        }

        for(auto it{m.begin()}; it != m.end(); ++it) {
            res[it->first - 'a'] += *max_element(it->second.begin(), it->second.end()); 
        }
    }

    for(int x : res) {
        cout << x << '\n';
    }
}