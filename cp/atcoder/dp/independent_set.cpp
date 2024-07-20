#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod{static_cast<ll>(1e9) + 7};
ll siz{100002};

vector<ll> f(siz, 1), g(siz, 1);
vector<vector<int>> adj(siz);

ll multiply(ll x, ll y) {
  return ((x % mod) * (y % mod)) % mod;
}

ll add(ll x, ll y) {
  return ((x % mod) + (y % mod)) % mod;
}

void dfs(int curr, int prev) {
  for(int node : adj[curr]) {
    if(node == prev)
        continue;
    
    dfs(node, curr);
    f[curr] = multiply(f[curr], add(f[node], g[node]));
    g[curr] = multiply(g[curr], f[node]);
  }
}

int main() {
  int n{};
  cin >> n;


  while(--n) {
    int x{}, y{};
    cin >> x >> y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  dfs(1, -1);
  cout << add(f[1], g[1]) << '\n';

  return 0;
}
