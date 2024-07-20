#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll check(int i, ll curr, const vector<ll>& arr) {
  if(i == arr.size())
    return curr;

  return max(check(i + 1, curr + arr[i], arr), check(i + 1, abs(curr + arr[i]), arr));
}

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n);
  for(ll& x : arr)
    cin >> x;


    printf("%lld\n", check(0, 0, arr));
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


