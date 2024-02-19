#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int max_n{static_cast<int>(2e5 + 1)};
int sparse[22][max_n];
ll depth[max_n];

int k_step(int num, int k) {
    if(k == 0)
        return num;

    int cnt{}, curr{-INT_MAX};
    while(k > 0) {
        if(curr == -1)
            return -1;

        if(k & 1 == 1) {
            if(curr == -INT_MAX) {
                curr = sparse[cnt][num];
            }
            else
                curr = sparse[cnt][curr];
        }

        ++cnt;
        k >>= 1;
    }

    return curr;
}

pair<pair<int, int>> helper(int x, int y) {
    int cnt{};
    while(sparse[cnt][x] != sparse[cnt][y]) {
        ++cnt;
    }

    return {{x,y}, cnt};
}

int solve(int x, int y) {
    if(depth[y] > depth[x])
        swap(x, y);
    
    x = k_step(x, depth[x] - depth[y]);
    pair<int, int> prev{};

    int cnt{};
    do {
        prev = {x, y};

        if(sparse[cnt][x] == sparse[cnt][y]) {
            if(cnt == 0)
                return sparse[cnt][x];
        
            cnt = 0;
            x = prev.first;
            y = prev.second;
        }
        x = sparse[cnt][x];
        y = sparse[cnt][y];
    } while(++cnt);
    
    return -1;
}

int main() {
    int n{}, q{};
    cin >> n >> q;
    memset(sparse, -1, sizeof(sparse));
    depth[1] = 0;
    sparse[0][1] = 1;

    for(int i{2}; i <= n; ++i) {
        int x{};
        cin >> x;
        
        sparse[0][i] = x;
        depth[i] = depth[x] + 1;
    }

    for(int i{1}; i < 21; ++i) {
        for(int node{2}; node <= n; ++node) {
            int prev{sparse[i - 1][node]};
            
            if(prev != -1)
                sparse[i][node] = sparse[i - 1][prev];
        }
    }

    while(q--) {
        int x{}, y{};
        cin >> x >> y;

        cout << solve(x, y) << '\n';
    }

    return 0;
}