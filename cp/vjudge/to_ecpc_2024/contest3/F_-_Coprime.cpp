#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;
  
  vector<ll> arr(n);
  ll setwise{INT_MAX};
  map<ll, ll> factors{};
  bool pairwise{true};
  for(ll& x : arr) {
    cin >> x;
    ++factors[x];
    if(x != 1 && factors[x] > 1)
      pairwise = false;
    
    if(setwise == INT_MAX)
      setwise = x;
    else
      setwise = gcd(setwise, x);

    for(ll i{2}; pairwise && i <= (ll)ceil(sqrt(x)); ++i) {
      if(x % i == 0 && x / i >= i) {
        ++factors[i];
        if(x / i != i)
          ++factors[x / i];
        if(factors[i] > 1 || factors[x / i] > 1)
          pairwise = false;
      }
    }
  }

  cout << (pairwise ? "pairwise coprime" : (setwise == 1 ? "setwise coprime" : "not coprime")) << '\n';
  

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

