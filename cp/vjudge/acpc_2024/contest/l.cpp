#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using bt_t = bitset<200005>;

void mx(int curr, int mex, bt_t s, const vector<vector<int>>& adj, const vector<int>& spec, vector<int>& res) {
  s.set(spec[curr]);
  if(spec[curr] == mex) {
    while(s[mex]) {
        ++mex;
    }
  }

  res[curr] = mex;
  for(int node : adj[curr]) {
    mx(node, mex, s, adj, spec, res);
  }
}

void solve() {
  int n{};
  cin >> n;

  vector<vector<int>> adj(n);
  vector<int> spec(n);
  vector<int> res(n);
  for(int i{}; i < n; ++i)
    cin >> spec[i];
  
  for(int i{1}; i < n; ++i) {
    int p{};
    cin >> p;
    --p;

    adj[p].push_back(i);
  }

  mx(0, 0, bt_t{}, adj, spec, res);
  for(int i{}; i < n - 1; ++i)
    cout << res[i] << ' ';
  cout << res[n - 1] << '\n';

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{};
  cin >> t;
  while(t--)
    solve();

  return 0;
}
