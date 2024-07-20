#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, k{};
  cin >> n >> k;

  vector<int> arr(n);
  int res{}, curr{};
  for(int& x : arr) {
    cin >> x;

    if(x >= k) {
      res += curr;
      continue;
    }

    ++curr;
  }
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

