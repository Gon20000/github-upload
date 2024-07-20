#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{};
  cin >> n;
  vector<int> arr(n);

  for(int i{}; i < n; ++i) {
    int x{};
    cin >> x;
    arr[i] = x;
  }
  
  int res{INT_MAX};
  for(int i{}; i < arr.size(); ++i) {
    if(arr[i] != arr.back()) {
      res = min(res, i);
      break;
    }
  }

  for(int i{arr.size() - 1}; i >= 0; --i) {
    if(arr[i] != arr[0]) {
      res = min(res, n - i - 1);
      break;
    }
  }

  cout << (res == INT_MAX ? -1 : res) << '\n';
}

int main() {
  int t{};
  cin >> t;

  while(t--)
    solve();

  return 0;
}
