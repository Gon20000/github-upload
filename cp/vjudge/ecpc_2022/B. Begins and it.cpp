#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  vector<vector<ll>> a(n);
  map<ll, ll> mp{};

  for(auto& vec : a) {
    ll x{};
    cin >> x;

    for(int i{1}; i * i <= x; ++i) {
      if(x % i)
        continue;

      vec.push_back(i);
      vec.push_back(x / i);
    }
  }

  for(int i{}; i < n; ++i) {
    ll x{};
    cin >> x;
    
    ++mp[x];
  }

  sort(a.begin(), a.end(), [&](const vector<ll>& a, const vector<ll>& b) {
    return a.size() < b.size();
  });

  ll res{};
  for(auto& vec : a) {
    for(ll node : vec) {
      if(mp[node]) {
        --mp[node];
        ++res;
        break;
      }
    }
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

