#include <bits/stdc++.h>
using namespace std;

int main() {
    int n{};
    cin >> n;
    vector<long long> res{};

    while(n--) {
        int type{};
        cin >> type;

        long long num{};
        cin >> num;

        if(type == 1)
            res.push_back(num);
        else
            cout << res[res.size() - num] << '\n';
    }

    return 0;
}