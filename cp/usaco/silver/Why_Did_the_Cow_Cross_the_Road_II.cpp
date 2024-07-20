#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, k{}, b{};
  cin >> n >> k >> b;

  vector<int> arr(n, 1);
  while(b--) {
    int x{};
    cin >> x;

    arr[--x] = 0;
  }

  for(int i{1}; i < n; ++i)
    arr[i] += arr[i - 1];

  int res{};
  for(int i{k}; i < n; ++i) {
    res = max(res, arr[i] - arr[i - k]);
  }

  cout << k - res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("maxcross.in", "r", stdin);
  freopen("maxcross.out", "w", stdout);

  int t{1};
  /*cin >> t;*/

  while(t--)
    solve();

  return 0;
}

