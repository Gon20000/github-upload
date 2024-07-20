#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod{static_cast<ll>(1e9) + 7};
ll siz{100002};
constexpr ll colors{3};

vector<vector<ll>> arr(3, vector<ll>(siz, 1ll));
vector<vector<ll>> adj(siz);

ll multiply(ll x, ll y) {
  return ((x % mod) * (y % mod)) % mod;
}

ll add(ll x, ll y) {
  return ((x % mod) + (y % mod)) % mod;
}

ll subtract(ll x, ll y) {
  return ((x % mod) - (y % mod)) % mod;
}

void dfs(int curr, int prev) {
  for(int node : adj[curr]) {
    if(node == prev)
      continue;

    dfs(node, curr);
    for(int i{}; i < colors; ++i) {
    ll res{};
      for(int j{}; j < colors; ++j)
          if(i != j)
            res += arr[j][node];

      arr[i][curr] = multiply(arr[i][curr], res);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("barnpainting.in", "r", stdin);
  freopen("barnpainting.out", "w", stdout);
  int n{}, k{};
  cin >> n >> k;


  while(--n) {
    int x{}, y{};
    cin >> x >> y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  while(k--) {
    int x{}, c{};
    cin >> x >> c;
    --c;

    for(int i{}; i < colors; ++i) {
      if(i == c) 
        continue;

      arr[i][x] = 0;
    }
  }

  dfs(1, -1);
  cout << add(arr[0][1], add(arr[1][1], arr[2][1])) << '\n';

  return 0;
}
