#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll mod{static_cast<ll>(1e9) + 7};
constexpr int N{100'001};

ll mult(ll x, ll y) {
  return ((x % mod) * (y % mod)) % mod;
}

ll add(ll x, ll y) {
  return (x % mod + y % mod) % mod;
}

long long exp(long long x, long long n) {

	x %= mod;  // note: m * m must be less than 2^63 to avoid ll overflow
	long long res = 1;

	while (n > 0) {
		if (n % 2 == 1) { res = res * x % mod; }
		x = x * x % mod;
		n /= 2;
	}

	return res;
}


vector<pair<ll, ll>> adj[N];
vector<bool> visited(N);
vector<ll> dp(N), in(N), cnt(N);
int n{};

void dfs3(int curr) {
  if(visited[curr])
    return;

  visited[curr] = true;

  for(auto [node, w] : adj[curr]) {
    ++in[node];
    dfs3(node);
  }
}

void dfs2() {
  /*for(int i{2}; i <= n; ++i) {*/
  /*  if(cnt[i] == 0)*/
  /*    fix(i);*/
  /*}*/

  queue<int> q{};
  q.push(1);

  while(!q.empty()) {
    int node{q.front()};
    q.pop();

    /*dp[node] = mult(dp[node], exp(cnt[node], mod - 2));*/
    for(auto [child, w] : adj[node]) {
      dp[child] = add(dp[child], add(dp[node], mult(w, cnt[node])));
      cnt[child] = add(cnt[child], cnt[node]);
      
      if(--in[child] == 0)
        q.push(child);
    }
  }
}

void solve() {
  int m{};
  cin >> n >> m;

  while(m--) {
    pair<ll, ll> p{};
    ll x{};
    cin >> x >> p.first >> p.second;

    adj[x].push_back(p);
  }

  dfs3(1);

  ++cnt[1];
  dfs2();

  cout << mult(dp[n], exp(cnt[n], mod - 2)) << '\n';
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

