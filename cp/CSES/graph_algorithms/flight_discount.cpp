#include <bits/stdc++.h>
#include <utility>
using namespace std;
using ll = long long;
using route_t = pair<ll, ll>;
using used_t = pair<route_t, bool>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n{}, m{};
  cin >> n >> m;
  vector<vector<route_t>> adj(n + 1);
  vector<route_t> prev(n + 1);
  vector<pair<ll, bool>> dist(n + 1, make_pair(LLONG_MAX, false));

  priority_queue<used_t, vector<used_t>, greater<used_t>> q{};
  while(m--) {
    ll x{}, y{}, w{};
    cin >> x >> y >> w;
    adj[x].push_back({y, w});
  }

  q.push({{0, 1}, false});
  while(!q.empty()) {
    auto [route, done] = q.top();
    auto [cdist, node] = route;
    q.pop();

    /*if(cdist >= dist[node])*/
    /*  continue;*/
    /**/
    /*dist[node] = cdist;*/
    /*for(const route_t& p : adj[node]) {*/
    /*  if(cdist + p.second < dist[p.first]) {*/
    /*    prev[p.first] = {node, p.second};*/
    /*    q.push({cdist + p.second, p.first});*/
    /*  }*/
    }
  }

  ll res{}, high{}, node{n};
  while(node != 1) {
    res += prev[node].second;
    high = max(high, prev[node].second);
    node = prev[node].first;
  }

  cout << (res - high + high / 2) << '\n';
  return 0;
}
