#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int max_k{501}, max_n{50001};
int res{}, k{};
vector<int> adj[max_n];

vector<int> dfs(int curr, int prev, int depth) {
  vector<int> arr(k + 1);

  for(int node : adj[curr]) {
    if(node == prev)
      continue;

    vector<int> nodeArr{dfs(node, curr, min(k, depth + 1))};
    
    for(int i{}; i < k; ++i) {
        if(nodeArr[i] == 0)
            break;
      res += nodeArr[i] * arr[k - i - 1];   
    }
    for (size_t i = 0; i < k; i++) {
      arr[i + 1] += nodeArr[i];
    }
  }

  ++arr[0];
  res += arr[k];

  return arr;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n{};
  cin >> n >> k;

  res = 0;
  while (--n) {
    int x{}, y{};
    cin >> x >> y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  vector<int> x{dfs(1, -1, 0)};
  cout << res << '\n';
  return 0;
}
