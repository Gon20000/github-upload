#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n);
  pair<ll, ll> high{0, 0};
  for(int i{}; i < n; ++i) {
    cin >> arr[i];
    if(arr[i] > high.second) {
      high = {i, arr[i]}; 
    }
  }

  ll sec{arr.back()};
  if(high.first == n - 1) {
    sec = 0;
    for (size_t i = 0; i < n - 1; i++) {
      sec = max(sec, arr[i]);
    }
  }
  cout << high.second + sec << '\n';
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

