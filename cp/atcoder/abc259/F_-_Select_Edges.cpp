#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct Edge {
  int u{}, v{};
  ll w{};
};

void solve() {
  int n{};
  cin >> n;

  vector<ll> allowed(n);
  for(ll& x : allowed)
    cin >> x;

  vector<Edge> edges(n - 1);
  for(Edge& edge : edges) 
    cin >> edge.u >> edge.v >> edge.w;

  sort(edges.begin(), edges.end(), [&](const Edge& a, const Edge& b) {
    return a.w > b.w;
  });

  ll res{};
  for(Edge& edge : edges) {
    --edge.u;
    --edge.v;

    if(edge.w <= 0)
      break;

    if(!allowed[edge.u] || !allowed[edge.v])
      continue;

    --allowed[edge.u];
    --allowed[edge.v];

    res += edge.w;
  }

  cout << res << '\n';
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

