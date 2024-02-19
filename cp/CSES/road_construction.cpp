#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
class UnionFind
{
    vector<T> p{}; // parent
    vector<T> size{};
    long long components_size{};
    ll res{1};

public:
    UnionFind(T n)
    {
        size.resize(n + 1, 1);
        p.resize(n + 1);
        components_size = n;
        for (int i{1}; i <= n; ++i)
            p[i] = i;
    }

    T get(T element)
    {
        T top{element};
        while (p[top] != top)
        {
            top = p[top];
        }

        while (element != p[element])
        {
            T next{p[element]};
            p[element] = top;
            element = next;
        }

        return element;
    }

    void unify(T first, T second)
    {
        T x{get(first)};
        T y{get(second)};

        if (x == y)
            return;

        if (size[x] < size[y])
            swap(x, y);

        p[y] = x;
        size[x] += size[y];
        res = max(res, size[x]);
        --components_size;
    }

    void print() {
        cout << components_size << ' ' << res << '\n';
    }
};


int main() {
    int n{}, m{};
    cin >> n >> m;

    UnionFind<ll> x{n};

    while (m--) {
        ll a{}, b{};
        cin >> a >> b;
        
        x.unify(a, b);
        x.print();
    }
}