#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  vector<ll> arr(3);
  ll res{};
  for(ll& x : arr) {
    cin >> x;
    
    if(x < 18)
        res += 10;
    else if(x < 60)
        res += 20;
    else {
      res += 15;
    }
  }

  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  // cin >> t;
  while(t--)
    solve();

  return 0;
}
