#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

// The number of integers between 0 and N (inclusive) whose j-th bit is set.
ll f(ll j, ll n) {
// There are exactly 2j integers between 0 (inclusive) and 2j+1 (exclusive) whose j-th bit is set.
ll p2{1ll << j}; // 2 ^ j
// how many 2 ^ (j + 1)s does n have?!
ll k{n / (2 * p2)};
  ll res{k * p2};

  // now there might be some extra numbers since n might not be a perfect square
  ll l{n % (2 * p2)};
  /*
  Let k be a non-negative integer and l be an integer strictly less than k×2^(j+1);
  then among the integers between k×2^(j+1) (inclusive) and k×2^(j+1)+l (exclusive), 
  the number of integers whose j-th bit is set is:
    0 if l is strictly less than 2^j;
    l−2^j+1 if l is greater than or equal to 2^j.

  For more info check the editorial on atcoder
  */

  if(l >= p2)
    res += l - p2 + 1;

  return res;
}

void solve() {
  ll n{}, m{};
  cin >> n >> m;

  ll res{}, mod{998244353}; 
  for(ll i{}; i < 60; ++i) {
    if(!(m & (1ll << i)))
      continue;

    res += f(i, n);
    res %= mod;
  }

  cout << res << '\n';
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

