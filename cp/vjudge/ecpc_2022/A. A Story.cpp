#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  vector<ll> next(n + 1);
  for(int i{}; i <= n; ++i) {
    ll x{};
    cin >> x;

    next[x] = i;
  }

  ll curr{next[0]};
  vector<ll> res{};
  while(curr != 0) {
    res.push_back(curr);
    curr = next[curr];
  }

  for(int i{}; i < res.size() - 1; ++i) {
    cout << res[i] << ' ';
  }
  
  cout << res.back() << '\n';
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

