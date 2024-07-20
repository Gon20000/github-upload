#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n{}, x{};
  cin >> n >> x;

  vector<ll> arr(n);
  for(ll& x : arr) 
    cin >> x;

  size_t r{}, sum{}, res{};
  for (size_t l = 0; l < n && r < n; l++) {
    while(r < n && sum + arr[r] <= x) {
      sum += arr[r];
      ++r;
    }

    if(sum == x)
      ++res;
    sum -= arr[l];
  }

  cout << res << '\n';
  return 0;
}
