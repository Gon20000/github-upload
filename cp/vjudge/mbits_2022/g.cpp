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

  for(int i{0}; i < n - 1; ++i) {
    ll curr{arr[i + 1]}, r{};
    bool check{true};
    for(int j{i + 1}; j < n; ++j){
      if(arr[j] >= curr) {
        curr = arr[j];
        if(arr[i] != curr) {
          ++r;
        }
        else if(arr[i] == curr && check) {
          ++r;
          check = false;
        }
      }

      if(arr[j] > arr[i])
        break;
    }

    res += r;
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
