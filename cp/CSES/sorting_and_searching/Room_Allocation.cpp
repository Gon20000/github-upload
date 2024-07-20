#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  vector<pair<ll, ll>> arr(n);
  map<pair<ll, ll>, deque<ll>> orders{};
  for(int i{}; i < n; ++i) {
    cin >> arr[i].first >> arr[i].second;
    orders[arr[i]].push_back(i);
  }

  sort(arr.begin(), arr.end());

  
  multimap<ll, ll> mp{};
  vector<ll> res(n);
  ll highest{};
  for(int i{}; i < n; ++i) {
    auto [x, y] = arr[i];

    auto it{mp.lower_bound(x)};
    ll order{orders[arr[i]].front()};
    orders[arr[i]].pop_front();
    if(it == mp.begin()) {
      mp.insert({y, mp.size() + 1});
      
      res[order] = mp.size();
    }
    else {
      --it;
      mp.insert({y, it->second});
      res[order] = (it->second);
      mp.erase(it);
    }

    highest = max(highest, res[order]);
  }

  cout << highest << '\n';
  for(int i{}; i < res.size() - 1; ++i)
    cout << res[i] << ' ';
  cout << res.back() << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  /*cin >> t;*/

  while(t--)
    solve();

  return 0;
}

