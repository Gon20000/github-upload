#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n{};
    cin >> n;

    string str{};
    cin >> str;

    bool done{false};
    int dup{}, cnt{};

    for(int i{2}; i  < n; ++i) {
        if(str[i - 1] == str[i] && str[i] == str[i - 2]) {
            if(!done) {
                ++cnt;
                done = true;
            }
            continue;
        }

        if(str[i + 1] == str[i - 2] && str[i - 1] == str[i -2])
            ++dup;
        ++cnt;
    }

    cout << cnt - dup << '\n';
}

int main()
{
    // your code goes here
    int t{};
    cin >> t;

    while (t--)
        solve();
}
