#include <bits/stdc++.h>
#include <queue>
using namespace std;

using ll = long long;
using ld = long double;

bool check(pair<ll, ll> p, int n, const set<ll>& s) {
  auto it{++s.find(p.second)};
  ll last{it == s.end() ? n : *(it)};
  --it;
  ll first{it == s.begin() ? 0 : *(--it)};

  return p.second - first == p.first || last - p.second == p.first;
}

void solve() {
  ll n{}, m{};
  cin >> n >> m;

  set<ll> s{};
  priority_queue<pair<ll, ll>> pq{};
  vector<ll> res(m);

  for(int i{}; i < m; ++i) {
    ll x{};
    cin >> x;

    auto it{s.insert(x).first};
    ll last{++it == s.end() ? n : *(it)};
    --it;
    ll first{it == s.begin() ? 0 : *(--it)};

    pq.push({last - x, x});
    pq.push({x - first, x});

    while(!check(pq.top(), n, s))
      pq.pop();
    
    res[i] = pq.top().first;
  }

  for(int i{}; i < m - 1; ++i)
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

