#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("div7.in", "r", stdin);
  freopen("div7.out", "w", stdout); 

  int n{};
  cin >> n;

  vector<ll> start(7, -1);
  start[0] = 0;

  ll curr{}, res{};
  for(ll i{1}; i <= n; ++i) {
    ll x{};
    cin >> x;

    curr += x;
    curr %= 7;
    if(start[curr] == -1)
      start[curr] = i;

    res = max(res, i - start[curr]);
  }

  cout << res << '\n';

  return 0;
}
