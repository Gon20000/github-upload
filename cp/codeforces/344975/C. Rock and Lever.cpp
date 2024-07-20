#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n);
  map<ll, ll> mp{};
  ll res{};

  for(ll& x : arr) {
    cin >> x;
    for(ll i{63}; i >= 0; --i)  {
      if(x & (1ll << i)) {
        res += mp[i];
        mp[i]++;
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

