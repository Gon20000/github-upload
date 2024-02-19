#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string username{};
    set<string> usernames{};
    int n{};
    cin >> username >> n;
    while (n--) {
        string x{};
        cin >> x;

        usernames.insert(x);
    }

    if(usernames.count(username) == 0)
        cout << username << '\n';
    else {
        for(int i{1}; i <= 200000; ++i) {
            string x{username + to_string(i)};
            if(usernames.count(x) == 0) {
                cout << x << '\n';
                break;
            }
        }
    }

    return 0;
}