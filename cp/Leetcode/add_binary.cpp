#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string a{}, b{};
    cin >> a >> b;

    ll res{};
    string ret{};
    for (int i{(int)a.size() - 1}; i >= 0; --i)
    {
        res += (a[i] == '1' ? pow(2, a.size() - i - 1) : 0);
    }
    for (int i{(int)b.size() - 1}; i >= 0; --i)
    {
        res += (b[i] == '1' ? pow(2, b.size() - i - 1) : 0);
    }

    int curr{static_cast<int>(log2(res))};
    for (int i{curr}; i >= 0; --i)
    {

        if (curr >= i)
        {
            ret += '1';
            res -= pow(2, curr);
            curr = static_cast<int>(log2(res));
        }
        else
            ret += '0';
    }
    cout << ret << '\n';
    // return ret;
    return 0;
}
