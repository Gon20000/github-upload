#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{};
  cin >> n;

  ll prev{LLONG_MIN}, res{};
  while(n--) {
    ll x{};
    cin >> x;
  
    if(x < prev) {
      // calculate the highest power of 2 that we'll add
      // in order to make x = prev, as we won't benefit 
      // if x > prev
      res = max(res, 32ll - __builtin_clz(prev - x));
      x = prev;
    }

    prev = x;
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

