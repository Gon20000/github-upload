#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

pll start{}, endC{};
vector<pll> psum{};
ll n{};

bool check(ll x) {
  pll res(start);

  res.first += psum.back().first * (x / n) + psum[x % n].first;
  res.second += psum.back().second * (x / n) + psum[x % n].second;

  return x >= abs(res.first - endC.first) + abs(res.second - endC.second);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> start.first >> start.second >> endC.first >> endC.second >> n;

  psum.clear();
  psum.resize(n + 1);

  for (size_t i = 1; i <= n; i++) {
    char x{};
    cin >> x;

    if(x == 'U')
      ++psum[i].second;
    else if(x == 'D')
      --psum[i].second;
    else if(x == 'R')
      ++psum[i].first;
    else 
      --psum[i].first;
    
    psum[i].first += psum[i - 1].first;
    psum[i].second += psum[i - 1].second;
  }

  ll l{}, r{(ll)1e18}, res{LLONG_MAX};

  while(l < r) {
    ll mid{l + (r - l) / 2};

    if(check(mid)) {
      res = mid;
      r = mid;
    }
    else {
      l = mid + 1;
    }
  }

  cout << (res == LLONG_MAX ? -1 : res) << '\n';
  return 0;
}
