#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{};
  cin >> n;

  vector<int> arr(n);
  for(int& x : arr)
    cin >> x;

  int i{1}, first{arr[0]};
  while(i < n) {
    if(arr[i] < arr[i - 1])
      break;

    ++i;
  }

  for(; i < n; ++i) {
    if(first < arr[i] || (i < n -  1 && arr[i] > arr[i + 1])) {
      cout << "No\n";
      return;
    }
  }

  cout << "Yes\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  cin >> t;

  while(t--) {
    solve();
  }

  return 0;
}
