#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n{};
  cin >> n;

  vector<int> arr(n);
  
  for(int& x : arr)
    cin >> x;

  int c{0};

  int i{}, res{};
  while(i < n) {
    res += arr[i] && !c;

    if(i + 1 < n  && c == arr[i + 1]) {
      ++i;
    }

    c ^= 1;
    ++i;
  }

  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{};
  cin >> t;

  while(t--) 
      solve();

  return 0;
}
