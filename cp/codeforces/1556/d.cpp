#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll getXor(ll an, ll orr) {
  return ~(an)  & orr;
}

ll getSum(ll x, ll y) {
  ll an{}, orr{};
  cout << "and " << x << ' ' << y << endl;
  cin >> an;
  cout << "or " << x << ' ' << y << endl;
  cin >> orr;

  return (an << 1) + getXor(an, orr);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n{}, k{};
  cin >> n >> k;

  ll a_b{getSum(1,2)}, b_c{getSum(2,3)}, a_c{getSum(1,3)};

  vector<ll> arr(n);
  arr[0] = (a_b + a_c - b_c) / 2;
  arr[1] = a_b - arr[0];
  arr[2] = a_c - arr[0];
  for(int i{3}; i < n; ++i) {
    ll sum{getSum(i, i + 1)};
    arr[i] = sum - arr[i - 1];
  }

  sort(arr.begin(), arr.end());
  cout << "finish " << arr[k - 1] << '\n';

  return 0;
}


