#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{};
  cin >> n;

  vector<ll> a(n), b(n + 1);
  for(ll& x : a)
    cin >> x;
  for(ll& x : b)
    cin >> x;

  ll res{}, low{LLONG_MAX};
  bool last{false};
  for(int i{}; i < a.size(); ++i) {
    res += abs(a[i] - b[i]);
    low =  min(low, min(abs(a[i] - b[n]), abs(b[i] -  b[n])));

    if(!last && ((b[i] >= b[n] && a[i] <= b[n]) || (b[i] <= b[n] && a[i] >= b[n]))) {
      last = true;
      ++res;
    }
  }

  if(!last) {
    res += low + 1;
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

