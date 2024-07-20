// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc267/tasks/abc267_f
// I use binary lifting instead of euler tour as i needed it in my solution.
// Solution:
// O(qlogn + nlogn)
// My idea:
// If we find diameter of a tree and its endpoints, then the answer on a query
// lies somewhere between vertice U and one of the endpoints.
// now we need to just find lca(U, endpoint).
// if dist(U, lca) >= k. 
//    then we need to jump k times from U;
// else if dist(endpoint, lca) > k - dist(U, lca). 
//	  then jump dist(endpoint, lca) - k + dist(U, lca) from endpoint.
// that's it!

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

void setIO(string File_name) {
    cin.tie(0)->sync_with_stdio(0);
    if (File_name.size()) {
        freopen((File_name + ".in").c_str(), "r", stdin);
        freopen((File_name + ".out").c_str(), "w", stdout);
    }
}

template <class U> class BinaryUPs {
private:
    vector<vector<U>> ancestors;
    vector<int> parent, depths;
    int n, h; 
    int r;
public:
    BinaryUPs(const vector<vector<U>> &tree, int root){
        r = root;
        n = tree.size();
        h = (int)log2(n);

        ancestors.resize(h + 1, vector<U>(n));
        parent.resize(n);
        depths.resize(n);

        auto dfs = [&](int u, int p, int depth, auto&& dfs) -> void {
            parent[u] = p;
            depths[u] = depth;
            for(auto v : tree[u]){
                if(v != p) {
                    dfs(v, u, depth + 1, dfs);
                }
            }
        }; dfs(root, 0, 0, dfs);
        
        for(int j = 0; j < n; j++){
            ancestors[0][j] = parent[j];
        }

        for(int i = 1; i <= h; i++){
            for(int j = 0; j < n; j++){
                ancestors[i][j] = ancestors[i - 1][ancestors[i - 1][j]];
            }
        }
    }
    int query(int u, int len){
        while(len){
            int next = (len & (-len));
            len -= next;
            u = ancestors[(int)log2(next)][u];
        }
        return u;
    }
    int lca(int u, int v){
        if(depths[u] > depths[v]){
            swap(u, v);
        }
        v = query(v, depths[v] - depths[u]);
        if(u == v){
            return u;
        }
        for(int i = h; i >= 0; i--){
            int ut = ancestors[i][u]; 
            int vt = ancestors[i][v];
            if(ut != vt) u = ut, v = vt;
        }
        return ancestors[0][u];
    }
    int getDepth(int u){
        return depths[u];
    }
    void debug(){
        for(auto vec : ancestors){
            for(auto el : vec){
                cout << el << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
};

void sol() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<pair<int, int>> endpoints(2);
    vector<int> depths(n);
    auto dfs = [&](int u, int p, int depth, auto&& dfs) -> void {
        for(auto v : tree[u]){
            if(v != p) dfs(v, u, depth + 1, dfs);
        }
        if(depth > endpoints[0].second){
            endpoints[0].second = depth;
            endpoints[0].first = u;
        }
    }; 
    dfs(0, -1, 0, dfs);
    swap(endpoints[0], endpoints[1]);
    dfs(endpoints[1].first, -1, 0, dfs);
    
    BinaryUPs<int> bups(tree, 0);

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int u, k;
        cin >> u >> k;
        u--;
        bool been = false;
        for(auto [v, d] : endpoints){
            int l = bups.lca(u, v);
            if(bups.getDepth(u) - bups.getDepth(l) >= k){
                cout << bups.query(u, k) + 1 << endl;
                been = true;
                break;
            }
            else if(k - (bups.getDepth(u) - bups.getDepth(l)) <= bups.getDepth(v) - bups.getDepth(l)){
                cout << bups.query(v, bups.getDepth(v) - bups.getDepth(l) - 
                                      (k - (bups.getDepth(u) - bups.getDepth(l)))) + 1 << endl;
                been = true;
                break;
            }
        }
        if(!been){
            cout << -1 << endl;
        }
    }
}

int main() {
    setIO("");
    int T = 1;
    //cin >> T;
    while (T--) sol();
    return 0;
}
