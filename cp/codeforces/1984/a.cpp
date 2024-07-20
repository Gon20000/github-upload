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

  for(int i{1}; i < n; ++i) {
    if(arr.back() - arr[i] != arr[i - 1] - arr[0]) {
      printf("YES\n");
      for(int j{}; j < i; ++j)
        printf("R");
      for(int j{i}; j < n; ++j)
        printf("B");

      printf("\n");
      return;
    }
  }
  
  for(int i{n - 2}; i >= 0; --i) {
    if(arr.back() - arr[i + 1] != arr[i] - arr[0]) {
      printf("YES\n");
      for(int j{}; j <= i; ++j)
        printf("R");
      for(int j{i + 1}; j < n; ++j)
        printf("B");

      printf("\n");
      return;
    }
  }
  printf("NO\n");
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
