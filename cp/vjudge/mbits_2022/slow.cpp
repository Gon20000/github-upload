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

  ll res{};


  for(int i{0}; i < n; ++i) {
    int j{i + 1};
    for(; j < n && arr[j] < ; ++j) {

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
