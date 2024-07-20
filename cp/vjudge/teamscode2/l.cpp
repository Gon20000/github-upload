#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int check(const string& a, const string& b) {
    int res{};

    for (int i{}; i < a.size(); ++i)
    {
        if (a[i] != b[i])
        {
            ++res;
        }
    }
    return res;
}

void solve() {
    int n{};
    int q{};
    cin >> n >> q;

    string str{};
    cin >> str;

    while ((q--) != 0)
    {
        bool res{false};
        int x{};
        int y{};
        cin >> x >> y;
        --x;
        
        string a{str.substr(x, y-x)};

        for(int i{}; i <= str.size() - y + x; ++i) {
            if (i == x)
            {
                continue;
            }

            if(check(a, str.substr(i, y-x)) == 1) {
                cout << i + 1 << ' ' << i + y - x << '\n';
                res = true;
                break;
            };
        }

        if (!res)
        {
            cout << "0 0\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{1};

    while ((t--) != 0)
    {
        solve();
    }

    return 0;
}