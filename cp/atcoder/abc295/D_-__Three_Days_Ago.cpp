#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  string str{};
  cin >> str;

  map<ll, ll> mp{};
  ll num{}, res{};
  ++mp[num];

  for(int i{}; i < str.size(); ++i) {
    num ^= (1 << (str[i] - '0'));
    res += mp[num]++;
  }

  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  /*cin >> t;*/

  while(t--)
    solve();

  return 0;
}

