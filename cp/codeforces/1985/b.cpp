#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{};
  cin >> n;

  pair<ll, ll> res{0, 0};
  for(int i{2}; i <= n; ++i) {
    ll sum{};
    for(int j{1};;++j)  {
      if(i * j > n)
        break;

      sum += i * j;
    }

    if(sum > res.second)
      res = {i, sum};
  }

  cout << res.first << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{};
  cin >> t;
  while(t--)
    solve();

  return 0;
}

