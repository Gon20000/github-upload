#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n{};
    cin >> n;

    vector<pair<int, int>> arr(n);
    for (pair<int, int> &x : arr)
        cin >> x.first >> x.second;

    sort(arr.begin(), arr.end(), [](pair<int, int> &first, pair<int, int> &second)
         { return second.second == first.second ? first.first > second.first : first.second < second.second; });

    int curr{}, res{};
    for(auto& x : arr) {
        if(curr <= x.first) {
            ++res;
            curr = x.second;
        }
    }

    cout << res << '\n';
    return 0;
}