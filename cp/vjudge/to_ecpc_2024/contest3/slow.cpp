#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n);
  for(ll& x : arr) 
    cin >> x;

  bool pairwise{true};
  ll setwise{arr[0]};
  for(int i{}; i < n; ++i) {
    setwise = gcd(arr[i], setwise);
    for(int j{}; pairwise && j < i; ++j) {
      if(gcd(arr[i], arr[j]) != 1)
        pairwise = false;
    }
  }

  if(pairwise)
    cout << "pairwise coprime\n";
  else if(setwise == 1)
    cout << "setwise coprime\n";
  else
    cout << "not coprime\n";
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

