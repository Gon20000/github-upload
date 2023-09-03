#include <bits/stdc++.h>
using namespace std;

void solve(const string& str, const string& res, int ind, vector<bool> check, set<string>& resArray) {
    if (res.size() == str.size()) {
        resArray.insert(res);
        return;
    }
    
    if (ind >= 0)
        check[ind] = true;
    
    for(int i{}; i < str.size(); ++i) {
        if(i != ind && !check[i]) {
            solve(str, res + str[i], i, check, resArray);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    
    string input{};
    cin >> input;
    set<string> res{};

    solve(input, "", -1, vector<bool>(input.size()), res);

    cout << res.size() << '\n';
    for (const string& permutation : res) {
        cout << permutation << '\n';
    }

}