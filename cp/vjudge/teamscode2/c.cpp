#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n{};
    cin >> n;

    string inp{};
    cin >> inp;

    bool res{true};
    while(inp.size() > 1 && res) {
        string curr{};
        for(int i{}; i < inp.size(); i += 2) {
            string c{inp.substr(i, 2)};

            if (c == "RF" || c == "FR")
            {
                curr.push_back('G');
            }
            else if (c == "RR" || c == "RG" || c == "GR")
            {
                curr.push_back('R');
            }
            else if (c == "FF" || c == "FG" || c == "GF")
            {
                curr.push_back('F');
            }
            else if (c == "GG")
            {
                curr.push_back('G');
            }
            else if (c == "AR" || c == "RA")
            {
                res = false;
                break;
            }
            else if(c == "RF") {
                curr.push_back('G');
            }
            else {
                curr.push_back('A');
            }
       }

       inp = curr;
    }

    cout << (res && inp == "A" ? "Yes" : "No") << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{1};
    cin >> t;

    while ((t--) != 0)
    {
        solve();
    }

    return 0;
}