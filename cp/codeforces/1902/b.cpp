#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  ll n{}, p{}, l{}, t{};
  cin >> n >> p >> l >> t;

  ld points{(ld)p};


  points -= t * ((n - 1) / 7 + 1);

  cout <<  n - ll(max(1.0l, ceil(points / l))) << '\n';
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

