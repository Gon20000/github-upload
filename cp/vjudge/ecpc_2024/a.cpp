#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using sparse_t = vector<vector<ll>>;

class HashedString { 
  ll m_base{}, m_mod{};
  size_t n{};
  static inline vector<ll> m_pow{1};
  vector<ll> m_hash{};
  vector<ll> m_rev{};

public:
  HashedString(const string& str = "", ll base = 9973, ll mod = static_cast<ll>(1e9) + 9) 
  : m_hash(str.size()), m_rev(str.size()), m_base{base}, m_mod{mod}, n{str.size()} {
    if(n == 0)
      return;

    while(m_pow.size() < n)
      m_pow.push_back((m_pow.back() * m_base) % m_mod);

    m_hash[0] = str[0];
    m_rev[n - 1] = str[n - 1];
    for(size_t i{1}; i < (int)n; ++i) {
      m_hash[i] = ((m_hash[i - 1] * m_base) % m_mod + str[i]) % m_mod;
    }

    for(int i{(int)n - 2}; i >= 0; --i)  {
      m_rev[i] = ((m_rev[i + 1] * m_base) % m_mod + str[i]) % m_mod;
    }
  }

  ll getHash(size_t start, size_t end) {
    if(start == 0)
      return m_hash[end];

    ll res{m_hash[end] - m_hash[start - 1] * m_pow[end - start + 1]};
    return (res % m_mod + m_mod) % m_mod;
  }

  ll getRevHash(size_t start, size_t end) {
    if(end == n - 1)
      return m_rev[start];

    ll res{m_rev[start] - m_rev[end + 1] * m_pow[end - start + 1]};
    return (res % m_mod + m_mod) % m_mod;
  }

  bool checkPalindrome(size_t start, size_t end) {
    if(start == end)
      return true;

    size_t mid{start + (end - start) / 2}, parity = !((end - start) % 2);
    ll x{getHash(start, mid - parity) };
    ll y{getRevHash(mid + 1, end)};
    return x == y;
  }

  bool empty() {
    return n == 0;
  }
};

constexpr int N{200'001}, LOG{18};

set<int> adj[N];
vector<int> depArr[N];
sparse_t sparse(LOG, vector<ll>(N, -1));
string strs[N];
HashedString hashes[N];
char code[N];
int depth[N], in[N], out[N];
int idx{};

void dfs_init(int curr, int prev, int dep = 0) {
  in[curr] = idx++;
  depArr[dep].push_back(in[curr]);
  depth[curr] = dep;
  strs[dep] += code[curr]; 

  for(int node : adj[curr]) {
    if(node == prev)
      continue;

    sparse[0][node] = curr;
    dfs_init(node, curr, dep + 1);
  }
  out[curr] = idx++;
}

int k_step(int node, int steps, const sparse_t& sparse) {
  for(int i{}; i < LOG; ++i) {
    if(steps & 1)
      node = sparse[i][node];
    steps >>= 1;
  }

  return node;
}

void solve() {
  int n{}, q{};
  cin >> n >> q;

  for(int i{}; i < n; ++i) {
    cin >> code[i];
    strs[i] = "";
    adj[i].clear();
    depArr[i].clear();
  }

  for(int i{1}; i < n; ++i) {
    int x{};
    cin >> x;

    adj[i].insert(--x);
    adj[x].insert(i);
  }

  dfs_init(0, -1);

  for(int i{1}; i < LOG; ++i) {
    for(int j{1}; j < n; ++j) {
      if(sparse[i - 1][j] == -1)
        continue;

      sparse[i][j] = sparse[i - 1][sparse[i - 1][j]];
    }
  }

  for(int i{}; i < n; ++i)
    hashes[i] = HashedString(strs[i]);

  while(q--) {
    int v{}, k{};
    cin >> v >> k;

    --v;
    int u{k_step(v, k, sparse)};

    HashedString& hash {hashes[depth[v]]};

    const auto& children = depArr[depth[v]];
    ll x{lower_bound(children.begin(), children.end(), in[u]) - children.begin()};
    ll y{upper_bound(children.begin(), children.end(), out[u]) - children.begin() - 1};

    if(x >= children.size() || y < x) {
      cout << "NO\n";
      continue;
    }

    cout << (hash.checkPalindrome(x, y) ? "YES" : "NO") << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  cin >> t;

  while(t--)
    solve();

  return 0;
}



