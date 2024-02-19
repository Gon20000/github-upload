#include <vector>
using namespace std;

template <typename T>
class UnionFind
{
    vector<T> p{}; // parent
    vector<T> size{};
    long long components_size{};

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
        --components_size;
    }
};