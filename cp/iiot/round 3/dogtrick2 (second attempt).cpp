#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int max_n{250001};

// an arr to store the parent of each component 
ll components[max_n];

// an arr to store the nodes according to their depth
vector<ll> depth_list{};

// main graph and reversed graph, look at cph chpater 17 images for more conclusions
set<ll> adj[max_n], adj_rev[max_n];
bool visited[max_n];

// adj after making SCCS
vector<vector<ll>> new_adj{};

// dfs on the sccs
bitset<max_n> done{};
vector<bitset<50001>> children{};


void dfs(ll idx, int pass, ll parent = 1) {
    visited[idx] = true;

    // are you dfs-ing the original graph or the reverse one?
    set<ll>& curr{ pass == 1 ? adj[idx] : adj_rev[idx] };
    for(ll node : curr) {
        if(!visited[node])
            dfs(node, pass, parent);
    }

    // this is as deep as you can go
    if(pass == 1)
        depth_list.push_back(idx);
    
    // set the new SCC
    else if(pass == 2)
        components[idx] = parent;
}

void init_check(int n) {
    children.resize(n + 1);
    for(int i{1}; i < n; ++i) {
        children[i].set(i);
    }
}

void dfs_check(size_t curr, size_t parent) {
    if(done[curr]) {
        if(parent != -1)
            children[parent] |= children[curr];
        return;
    }

    for(int child : new_adj[curr]) {
        if(!done[child]) {
            dfs_check(child, curr);
        }
        children[curr] |= children[child];
    }

    done[curr] = true;
}



bool check(ll left, ll right) {
    return children[left][right];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n{}, k{};
    cin >> n >> k;

    vector<ll> queries(n);
    vector<pair<ll, ll>> inps{};
    for(int i{}; i < n; ++i)
        cin >> queries[i];
    
    int m{};
    cin >> m;

    while(m--) {
        ll x{}, y{};
        cin >> x >> y;

        adj[x].insert(y);
        adj_rev[y].insert(x);
        inps.push_back({x, y});
    }

    for(int i{1}; i <= k; ++i) {
        if(!visited[i])
            dfs(i, 1);
    }

    // resetting visited
    memset(visited, false, sizeof(visited));

    int curr_component{1};
    for(int i{k - 1}; i >= 0; --i) {
        if(!visited[depth_list[i]])
            dfs(depth_list[i], 2, curr_component++);
    }

    new_adj.resize(curr_component);
    for(auto inp : inps) {
        if(components[inp.first] != components[inp.second])
            new_adj[components[inp.first]].push_back(components[inp.second]);
    }

    init_check(curr_component);
    for(int i{}; i < curr_component; ++i) {
        if(!done[i])
            dfs_check(i, -1);
    }

    ll curr{queries[0]}, res{2};
    for(int i{1}; i < n; ++i) {
        if(adj[curr].count(queries[i]) > 0)
            res += 2;
        else if(check(components[curr], components[queries[i]]))
            ++res;
        else
            break;

        curr = queries[i];
    }

    cout << res << '\n';

    return 0;
}

/*
4 7
1 3 2 5
10
1 2
2 1
1 4
5 4
6 5
3 2
3 7
7 6
6 3
2 5


2 7
4 1
4
1 2
2 3
3 2
4 2*/