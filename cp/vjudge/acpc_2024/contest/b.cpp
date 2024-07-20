#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll helper(ll num) {
  if(num <= 0)
    return 0;

  ll l{0}, r{static_cast<ll>(1e6)};
  pair<ll, ll> res{LLONG_MAX, 0};

  while(l <= r) {
    ll mid{l + (r - l) / 2};
    ll sq{mid * mid};

    if(sq < num) {
      if(res.first > num - sq) {
        res = {num - sq, mid};
      }
      l = mid + 1;
    }
    else if(sq > num) {
      if(res.first > sq - num)
        res = {sq - num, mid};
      r = mid - 1;
    }
    else {
      res = {0, sq};
      break;
    }
  }

  return res.second;
}

ll calc(ll sq, ll n) {
  ll x{helper(n - sq)}, y{sq - n};
  if(y > 0)
    return y;
  
  if(x * x < y)
    ++x;
  return (sq + x * x - n);
}

ll calc2(ll sq, ll n) {
  ll x{n - sq};
  if(x < 0)
    return 
}

void solve() {
  ll res{LLONG_MAX}, n{};
  cin >> n;

  ll l{0}, r{static_cast<ll>(1e6)};

  while(l <= r && res) {
    ll mid{l + (r-l) / 2};
    ll sq{mid * mid};

    ll x{calc(sq, n)};
    res = min(res, x);

    if(x == 0) {
      break;
    }
    else if(x > calc((mid - 1) * (mid - 1), n)) {
      r =  mid - 1;
    }
    else {
      l = mid + 1;
    }
  }

  l = 0; r = static_cast<ll>(1e6);
  while(l <= r && res) {
    ll mid{l + (r-l) / 2};
    ll sq{mid * mid};

    ll x{calc2(sq, n)};
    res = min(res, x);

    if(x == 0) {
      break;
    }
    else if(x > calc2((mid - 1) * (mid - 1), n)) {
      r =  mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  cout << res << '\n';
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
