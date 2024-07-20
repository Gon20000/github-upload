#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
  
constexpr int max_n{100'001};

vector<int> adj[max_n];
int prevArr[max_n];

pair<int, int> bfs(int start) {
  memset(prevArr, -1, sizeof prevArr);
  pair<int, int> res{start, 0};
  queue<pair<int, int>> q{};
  q.push(res);

  while(!q.empty()) {
    pair<int, int> curr{q.front()};
    q.pop();

    if(curr.second > res.second)
      res = curr;

    for(int node : adj[curr.first]) {
      if(prevArr[curr.first] == node)
        continue;

      prevArr[node] = curr.first;
      q.push({node, curr.second + 1});
    }
  }

  return res;
}

void solve() {
  ld n{}, s{};
  cin >> n >> s;

  for(int i{1}; i < n; ++i) {
    int x{}, y{};
    cin >> x >> y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  int start{bfs(1).first};
  int res {bfs(start).second};
  --n;
  if(res % 2 == 1)
    --n;

  cout << setprecision(10) << (s / n * (res - (res % 2))) << '\n';
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  // cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
