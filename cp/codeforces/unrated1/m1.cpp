#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll modPow(ll x, ll n, ll k) {
  if(n == 0)
      return 1ll % k;

  ll u{modPow(x, n / 2, k)};
  u = (u*u) % k;

  if(n % 2 == 1)
      u = (u*x) % k;

  return u;
}

int main() {
  ll a{}, b{}, c{}, k{};
  cin >> a >> b >> c >> k;
  
  cout << modPow(a, pow(b, c), k) << '\n';

  return 0;
}

