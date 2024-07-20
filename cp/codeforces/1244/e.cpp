#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n{}, k{};
  cin >> n >> k;

  vector<ll> arr(n);
  for(ll& x : arr)
  cin >> x;

  sort(arr.begin(), arr.end());
  ll first{arr[0]}, last{arr[n - 1]};

  while (k > 0 && first != last) {
    ll  left{distance(arr.begin(), upper_bound(arr.begin(), arr.end(), first))},
    right{distance(lower_bound(arr.begin(), arr.end(), last), arr.end())},
    diff{};

    if (left <= right) {
      diff = k / left;
      if(left < n)
        diff = min(diff, (arr[left] - first));
    
      first += diff;
      k -= diff * left;
    }
    else {
      diff = min(k / right, last - arr[n - right - 1]);

      last -= diff;
      k -= diff * right;
    }

    if(diff == 0)
      break;
  }

  cout << last - first << '\n';

  return 0;
}
