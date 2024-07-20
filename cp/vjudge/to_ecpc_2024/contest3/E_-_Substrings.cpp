#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  string str{};
  cin >> str;

  map<char, ll> mp{};
  ll res{};
  for(int i{}; i < str.size(); ++i) {
    res += mp[str[i]]++;
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

