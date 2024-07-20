#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll dp[1002][1002];
ll mod{static_cast<ll>(1e9) + 7};

ll modpow(ll x, ll n)  {
  if(n == 0)
    return 1 % mod;

  ll u{modpow(x, n / 2)};
  u = (u * u) % mod;

  if(n % 2)
    u = (u * x) % mod;

  return u;
}

ll mult(ll x, ll y) {
  return ((x % mod) * (y % mod)) % mod;
}

void addRow(int idx, int open) {
  for(int i{open == 1 ? 0 : 1}; i < 1000; ++i) {
    dp[idx][i + open] += dp[idx - 1][i];
    dp[idx][i + open] %= mod;
  }
}

void solve() {
  int n{};
  cin >> n;

  string str{};
  cin >> str;

  dp[0][1] = 1;
  ll cnt{str[0] == '?'};
  for(int i{1}; i < n; ++i) {
    if(str[i] == '(')
      addRow(i, 1);
    else if(str[i] == ')')
    addRow(i, -1);
    else {
      addRow(i, 1);
      addRow(i, -1);
      ++cnt;
    }
  }

  // probability is number of regular sequences / 2^(number of ?)
  // calculating modular inverse of 2^(? count)
  ll inv{modpow(2, cnt)};

  cout << mult(dp[n - 1][0], modpow(inv, mod - 2)) << '\n';
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

