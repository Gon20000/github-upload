#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

constexpr int max_n{100'001};
bitset<max_n> breed{};
int cnt{1};

void dfs(int curr, int prev, vector<int>& components, const vector<vector<int>>& adj) {
  components[curr] = cnt;
  for(int node : adj[curr]) {
    if(node == prev || breed[node] != breed[curr])
      continue;

    dfs(node, curr, components, adj);
  } 
}

void solve() {
  int n{}, m{};
  cin >> n >> m;

  for (size_t i = 1; i <= n; i++) {
    char x{};
    cin >> x;

    breed[i] = (x == 'H');
  }

  vector<vector<int>> adj(n + 1);
  vector<int> components(n + 1);
  for(int i{}; i < n - 1; ++i)  {
    int x{}, y{};
    cin >> x >> y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  for (size_t i = 1; i < n; i++) {
    if(!components[i]) {
      dfs(i, -1, components, adj);
      ++cnt;
    }
  }

  while(m--) {
    int x{}, y{};
    char z{};
    cin >> x >> y >> z;
    bool curr{z == 'H'};

    cout << (breed[x] == curr || components[x] != components[y]);
  } 
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  /*freopen("milkvisits.out", "w", stdout);*/
  /*freopen("milkvisits.in", "r", stdin);*/
  int t{1};
  /*cin >> t;*/

  while(t--)
    solve();

  return 0;
}

