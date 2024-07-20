#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("herding.in", "r", stdin);
  // freopen("herding.out", "w", stdout);

  ll n{};
  cin >> n;

  vector<ll> arr(n + 1);
  arr[n] = LLONG_MAX;
  for(int i{}; i < n; ++i)
    cin >> arr[i];

  sort(arr.begin(), arr.end());
  
  pair<ll, ll> res{LLONG_MAX, 0};
  ll l{}, r{};
  for(; l < n; ++l) {
    ll curr{(arr[r] - arr[l]) - (r - l)};
    while(r < n - 1 && curr < l + (n - r - 1)) {
      ++r;
      curr = (arr[r] - arr[l]) - (r - l);
    }

    if(l == 0 || r == n)
        curr = min(curr, n - 1);    
    else
        curr = min(curr, n - (r - l));
    res.first = min(res.first, curr);
  }

  for(int i{2}; i < n - 1; ++i)
    res.second += arr[i] - arr[i - 1] - 1;

  res.second += max(arr[1] - arr[0], arr[n - 1] - arr[n - 2]) - 1;
  cout << res.first << '\n' << res.second << '\n';
}

