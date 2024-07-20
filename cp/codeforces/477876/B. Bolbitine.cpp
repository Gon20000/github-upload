#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll mod{static_cast<ll>(1e9) + 7};
void solve() {
  string s{}, s2{};
  cin >> s;

  ll res{1}, curr2{1};
  for(char x : s) {
    if(s2.back() != x) {
      res *= curr2;
      if(res > 2 * mod)
        res %= mod;
      curr2 = 1;
      s2.push_back(x);
    }
    else {
      ++curr2;
    }
  }
  res *= curr2;

  cout << s2.size() << ' ' << res % mod << '\n';
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

