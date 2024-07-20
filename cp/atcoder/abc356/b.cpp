#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n{}, m{};
  cin >> n >> m;

  vector<ll> arr1(m), arr2(m);
  for(ll& x : arr1)
    cin >> x;

  for(int i{}; i < n; ++i) {
    for(ll& x : arr2) {
      ll a{};
      cin >> a;
      x += a;
    }
  }

  for(int i{}; i < m; ++i)  {
    if(arr2[i] < arr1[i]) {
      cout << "No\n";
      return 0 ;
    }
  }

  cout << "Yes\n";
  return 0;
}
