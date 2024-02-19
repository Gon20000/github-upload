#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
class UnionFind
{
    vector<T> p{}; // parent
    vector<T> size{};
    vector<T> mini{};
    vector<T> maxi{};

public:
    UnionFind(T n)
    {
        size.resize(n + 1, 1);
        p.resize(n + 1);
        mini.resize(n + 1);
        maxi.resize(n + 1);

        for (int i{1}; i <= n; ++i)
        {
            p[i] = i;
            mini[i] = i;
            maxi[i] = i;
        }
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

        if (size[x] >= size[y])
        {
            p[y] = x;
            size[x] += size[y];
            mini[x] = min(mini[x], mini[y]);
            maxi[x] = max(maxi[x], maxi[y]);
        }
        else
        {
            p[x] = y;
            size[y] += size[x];
            mini[y] = min(mini[x], mini[y]);
            maxi[y] = max(maxi[x], maxi[y]);
        }
    }

    T getSize(T element)
    {
        return size[get(element)];
    }

    T getMax(T element)
    {
        return maxi[get(element)];
    }

    T getMin(T element)
    {
        return mini[get(element)];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n{}, m{};
    cin >> n >> m;

    UnionFind<ll> x{n};

    while (m--)
    {
        string q{};
        cin >> q;

        if (q == "get")
        {
            ll a{};
            cin >> a;
            cout << x.getMin(a) << ' ' << x.getMax(a) << ' ' << x.getSize(a) << '\n';
        }
        else
        {
            ll u{}, v{};
            cin >> u >> v;
            x.unify(u, v);
        }
    }

    return 0;
}