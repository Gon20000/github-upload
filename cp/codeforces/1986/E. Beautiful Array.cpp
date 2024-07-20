#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n{}, k{};
  cin >> n >> k;

  map<ll, ll> inp{};
  for(int i{}; i < n; ++i) {
    ll x{};
    cin >> x;

    ++inp[x];
  }

  map<ll, vector<ll>> mp{};
  for(auto it{inp.rbegin()}; it != inp.rend(); ++it) {
    if(it->second % 2 == 0)
      continue;
    mp[it->first % k].push_back(it->first);
  }

  ll off{};
  for(auto& [x, y] : mp) {
    if(y.size() % 2 != 0)
      ++off;
  }

  if(off > n % 2) {
    cout << -1 << '\n';
    return;
  }

  ll store{};
  ll res{};
  for(auto& [x, y] : mp) {
    ll curr{}, curr2{}, high{}, idx{};
  
    for(int i{}; i < y.size() - 1; i += 2) {
      ll c{(y[i] - y[i + 1]) / k};
      curr += c;
    }
    
    if(y.size() % 2 == 0) {
      res += curr;
      continue;
    }

    vector<ll> pref(y.size()), suff(y.size());
    for (size_t i = 0; i < y.size() - 1; i += 2) {
      pref[i] = (y[i] - y[i + 1]) / k;
      if(i > 0) {
        pref[i] += pref[i - 1];
      }
      pref[i + 1] = pref[i];
    }

    for (int i = y.size() - 1; i > 0; i-= 2) {
      suff[i] = (y[i - 1] - y[i]) / k;
      if(i < y.size() - 1)
        suff[i] += suff[i + 1];
      suff[i - 1] = suff[i];
    }
    
    for(int i{}; i < y.size(); ++i) {
      ll x{};
      if(i % 2 == 0) {
        if(i + 1 < y.size())
          x += suff[i + 1];
        if(i > 0)
          x += pref[i - 1];
      }
      else {
        x += y[i - 1];
        if(i + 1 < y.size())
          x -= y[i + 1];
        x /= k;
        if(i + 2 < y.size())
          x += suff[i + 2];
        if(i - 2 > 0)
          x += pref[i - 2];
      }
      curr = min(curr, x);
    }

    res += curr;
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


