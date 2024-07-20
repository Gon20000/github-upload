#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;
  
  ll res{}, p{};
  map<ll, ll> mp{};
  ++mp[0];
  for(int x{1}; x <= n; ++x) {
    char chr{};
    cin >> chr;

    p += (chr - '0');
    res += mp[p - x]++;
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

