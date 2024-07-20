#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct Node {
  int start{}, end{};
  Node(int x, int y) : start{x}, end{y} {
  }
};

void solve() {
  int n{};
  cin >> n;

  set<pair<ll, ll>> s{};
  map<ll, ll> starts{}, ends{};

  for(int i{}; i < n; ++i) {
    ll x{};
    cin >> x;

    ends[x] = i;
    if(!starts.count(x))
      starts[x] = i;
  }
  
  bool stop{false};
  while(s.size() > 1 && !stop) {
    for(auto it{s.begin()}; it != --s.end(); ++it) {
      auto [x, y] = *it;
      auto [a, b] = *(next(it));

      if()
    }
  }
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

