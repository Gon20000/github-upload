#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  string str{};
  cin >> str;

  vector<ll> arr(str.size());
  arr[0] = 1;

  for(int i{1}; i < str.size(); ++i) {
    arr[i] = arr[i - 1];
    if(str[i] == '(')
      ++arr[i];
    else {
      --arr[i];
    }
  }

  map<int, int> mp{};
  ll res{};

  for(int i{}; i < arr.size(); ++i) {
    if(arr[i] == 0)
      continue;

    if(mp[arr[i]] == 0) {
      ++mp[arr[i]];
    }
    else {
      res += mp[arr[i]];
      ++mp[arr[i]];
    }

    while(!mp.empty() && arr[i] > 2 * mp.begin()->first)
      mp.erase(mp.begin());
  }

  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  cin >> t;

  while(t--)
    solve();

  return 0;
}

