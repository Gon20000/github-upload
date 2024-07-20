#include <bits/stdc++.h>
#include <climits>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n), prefix(n), suffix(n);
  for(int i{}; i < n; ++i) {
    cin >> arr[i];
    prefix[i] = arr[i];

    if(i > 0)
      prefix[i] = gcd(prefix[i], prefix[i - 1]);
  }

  suffix[n - 1] = arr.back(); 
  for(int i{n - 2}; i >= 0; --i) {
    suffix[i] = gcd(suffix[i + 1], arr[i]);
  }

  ll res{0};
  for(int i{}; i < n; ++i)  {
    ll curr{};

    if(i > 0)
      curr = prefix[i - 1];
    if(i < n -  1) {
      if(curr == 0)
        curr = suffix[i + 1];
      else
        curr = gcd(curr, suffix[i + 1]);
    }

    res = max(res, curr);
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

