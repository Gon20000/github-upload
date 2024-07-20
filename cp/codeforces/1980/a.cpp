#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int m{}, n{};
  cin >> n >> m;

  map<char, ll> mp{};
  string str{};
  cin >> str;

  for(char x{'A'}; x <= 'G'; ++x) {
    mp[x] = 0;
  }

  for(char chr : str)
      ++mp[chr];

  ll res{};

  for(auto& [x, y] : mp) {
    if(y < m)
      res += m - y;
  }

  cout << res << '\n';
  return;
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
