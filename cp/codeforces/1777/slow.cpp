#include <bits/stdc++.h>
#include <climits>
using namespace std;

using ll = long long;
using ld = long double;
using factors_t = bitset<100'001>;

factors_t get_factors(int num, int high) {
  factors_t res{};
  for(int i{1}; i <= min(high, (int)ceil(sqrt(num))); ++i) {
    if(num % i == 0) {
      res[i] = true;
      res[num / i] = true;
    }
  }

  return res;
}

void solve() {
  int n{}, m{};
  cin >> n >> m;

  vector<int> arr(n);
  for(int& x : arr)
    cin >> x;

  sort(arr.begin(), arr.end(), less<int>());

  int l{}, r{};
  multiset<int> team{};
  map<int, ll> mp{};
  int res{INT_MAX};

  for(; l < n; ++l) {
    while(r < n && mp.size() != m) {
      factors_t factors {get_factors(arr[r], m)};
      for(int i{1}; i <= m; ++i) {
        if(factors[i])
          ++mp[i];
      }
  
      team.insert(arr[r]);
      ++r;
    }

    if(mp.size() == m)
      res = min(res, *(--team.end()) - *(team.begin()));

    team.extract(arr[l]);
    factors_t factors {get_factors(arr[l], m)};
    for(int i{1}; i <= m; ++i) {
      if(factors[i])
        --mp[i];
      if(mp[i] == 0)
        mp.erase(i);
    }
  }

  cout << (res == INT_MAX ? -1 : res) << '\n';
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

