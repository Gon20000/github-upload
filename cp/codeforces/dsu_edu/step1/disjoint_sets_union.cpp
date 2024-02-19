#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
class UnionFind {
    vector<T> p{}; // parent
    vector<T> size{};

public:
    UnionFind(T n) {
        size.resize(n + 1, 1);
        p.resize(n + 1);
        for(int i{1}; i <= n; ++i)
            p[i] = i;
    }

    T get(T element) {
        T top{element};
        while (p[top] != top) {
            top = p[top];
        }

        while (element != p[element]) {
            T next{p[element]};
            p[element] = top;
            element = next;
        }

        return element;
    }

    void unify(T first, T second) {
        T x{get(first)};
        T y{get(second)};
        
        if (x == y) 
            return;

        if(size[x] >= size[y]) {
            p[y] = x;
            size[x] += size[y];
        }
        else {
            p[x] = y;
            size[y] += size[x];
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n{}, m{};
    cin >> n >> m;

    UnionFind<ll> x{n};

    while(m--) {
        string q{};
        ll u{}, v{};
        cin >> q >> u >> v;

        if(q == "get") {
            cout << ((x.get(u) == x.get(v)) ? "YES" : "NO") << '\n';
        }
        else {
            x.unify(u, v);
        }
    }

    return 0;
}