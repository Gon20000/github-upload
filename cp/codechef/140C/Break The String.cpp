#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

class HashedString { 
public:
  static inline vector<ll> m_pow{1};
  vector<ll> m_hash{};
  ll m_base{}, m_mod{};
  HashedString(const string& str, ll base = 9973, ll mod = static_cast<ll>(1e9) + 9) 
  : m_hash(str.size()), m_base{base}, m_mod{mod} {
    while(m_pow.size() < str.size())
      m_pow.push_back((m_pow.back() * m_base) % m_mod);

    m_hash[0] = str[0];
    for(size_t i{1}; i < (int)str.size(); ++i) {
      m_hash[i] = ((m_hash[i - 1] * m_base) % m_mod + str[i]) % m_mod;
    }
  }

  ll getHash(size_t start, size_t end) {
    if(start == 0)
      return m_hash[end];

    ll res{m_hash[end] - m_hash[start - 1] * m_pow[end - start + 1]};
    return (res % m_mod + m_mod) % m_mod;
  }
};

void solve() {
  string str{};
  cin >> str;

  if(str.size() % 2 != 0) {
    cout << 0 << '\n';
    return;
  }

  HashedString hash(str);
  int n{(int)str.size()};
  int k{n / 2 - 1};


  ll left{}, right{}, res{};
  for(int i{}; i + k < n; ++i) {
    left = ((i == 0 ? 0 : hash.getHash(0, i - 1)) * hash.m_pow[n - i - k - 1]);
    right = ((i + k == n ? 0 : hash.getHash(i + k + 1, n - 1)));

    ll curr{hash.getHash(i, i + k)};
    if((left + right) % hash.m_mod == curr)
      ++res;
  }

  cout << res << '\n';
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

