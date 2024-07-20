#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    int i{0}, j{s.size() - 1};
    while(i < j) {
        if(s[i] < s[j])
            return true;
        else if(s[i] > s[j])
            return false;

        ++i;
        --j;
    }

    return true;
}

int main() {
    int t{};
    cin >> t;

    freopen("a.out", "w", stdout);
    
    while(t--) {
        int n{};
        cin >> n;

        string s{};
        cin >> s;

        if(check(s))
            cout << s << '\n';
        else {
            string x{s};
            reverse(s.begin(), s.end());
            s += x;

            cout << s << '\n';
        }
    }
    return 0;
}