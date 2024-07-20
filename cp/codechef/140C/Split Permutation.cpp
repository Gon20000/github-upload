#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  vector<ll> res{};
  if(n % 2) {
    res.push_back(n);
    --n;
  }

  int curr{n};
  while(curr > n / 2) {
    res.push_back(curr);
    res.push_back(n - curr + 1);
    --curr;
  }

  for(int i{}; i < res.size() - 1; ++i)
    cout << res[i] << ' ';
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

