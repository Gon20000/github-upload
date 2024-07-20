#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll max_n{ll(1e5) + 1};
vector<ll> dist(max_n, INT_MAX);

ll n{}, t{}, k{}, a{}, b{};

void dfs(ll x, ll d) {
  ll a{x - k}, b{x - k - 1};
  if(a < 1) 
    a += n;
  if(b < 1)
    b += n;

  if(d + 1 < dist[a]) {
    dist[a] = d + 1 ;
    dfs(a, d + 1);
  }
  if(d + 1 < dist[b]) {
    dist[b] = d + 1;
    dfs(b, d + 1);
  }
} 

void solve() {
  cin >> n >> t >> k >> a >> b;
  dist[b] = 0;

  dfs(b, 0);
  cout << (dist[a] <= t ? "YES\n" : "NO\n");
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  //cin >> t;

  while(t--)
    solve();

  return 0;
}
