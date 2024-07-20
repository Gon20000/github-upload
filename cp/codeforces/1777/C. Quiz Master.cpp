#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using factors_t = bitset<500>;

constexpr int max_n{100'001};
factors_t facts[max_n];

void get_factors(int num) {
  for(int i{1}; i <= ceil(sqrt(num)); ++i) {
    if(num % i == 0) {
      facts[num][i] = true;
    }
  }
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
      factors_t factors {facts[arr[r]]};
      int x{int(ceil(sqrt(arr[r])))};
      for(int i{1}; i <= min(m, x); ++i) {
        if(factors[i]) {
          ++mp[i];
          if(arr[r] / i <= m)
            ++mp[arr[r] / i];
        }
      }

      team.insert(arr[r]);
      ++r;
    }

    if(mp.size() == m && !team.empty())
      res = min(res, *(--team.end()) - *(team.begin()));

    team.extract(arr[l]);
    factors_t factors {facts[arr[l]]};
    int x{int(ceil(sqrt(arr[l])))};
    for(int i{1}; i <= min(m, x); ++i) {
      if(!factors[i])
        continue;

      --mp[i];
      if(mp[i] == 0)
        mp.erase(i);

      if(arr[l] / i <= m) {
        --mp[arr[l] / i];

        if(mp[arr[l] / i] == 0)
          mp.erase(arr[l] / i);
      }
    }
  }

  cout << (res == INT_MAX ? -1 : res) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  cin >> t;

  for(int i{1}; i < max_n; ++i)
    get_factors(i);

  while(t--)
    solve();

  return 0;
}

