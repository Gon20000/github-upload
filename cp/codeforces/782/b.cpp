#include <bits/stdc++.h>
using namespace std;
using ld =  long double;
using ll = long long;

bool check(ld x, const vector<ll>& pos, const vector<ll>& speed) {
  ld l{max(pos[0] - speed[0] * x, 0.0L)}, r{pos[0] + speed[0] * x};

  for(size_t i{1}; i < pos.size(); ++i) {
    ld a{pos[i] -  speed[i] * x}, b{pos[i] + speed[i] * x};

    if(b < l || a > r)
      return false;

    l = max(l, a);
    r = min(r, b);
  }

  return true;
}

int main() {
  size_t n{};
  cin >> n;

  vector<ll> pos(n), speeds(n);
  
  for(ll& x : pos)
    cin >> x;
  for(ll& x : speeds)
    cin >> x;

  ld l{}, r{1e18 + 1}, res{LLONG_MAX};
  while(r - l >= 1e-6) {
    ld mid{l + (r - l) / 2.0};

    if(check(mid, pos, speeds)) {
      res = min(res, mid);
      r = mid;
    }
    else {
      l = mid;
    }
  }

  cout << setprecision(10) << res << '\n';
  return 0;
}
