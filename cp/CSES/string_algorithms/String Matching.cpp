#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

class HashedString {

public:
  static inline vector<ll> m_pow;
  vector<ll> m_hash{};

  ll m_base{}, m_mod{};

  HashedString(const string& str, ll base = 9973, ll mod = static_cast<ll>(1e9) + 9) 
  : m_hash(str.size()), m_base{base}, m_mod{mod} {

    m_pow.push_back(1);
    for(size_t i{1}; i < str.size(); ++i) 
      m_pow.push_back((m_pow[i - 1] * m_base) % m_mod);

    m_hash[0] = str[0];
    for (size_t i{1}; i < m_hash.size(); i++) {
      m_hash[i] = ((m_hash[i - 1] * m_base) % m_mod + str[i]) % m_mod;
    }
  }

  ll get_hash(size_t l, size_t r) {
    if(l == 0)
      return m_hash[r];

    ll res{ m_hash[r] - m_hash[l - 1] * m_pow[r - l + 1] };
    return (res % m_mod + m_mod) % m_mod;
  }

};

void solve() {
  string s{}, pat{};
  cin >> s >> pat;

  HashedString a(s), b(pat);
  ll p{b.get_hash(0, pat.size() - 1)}, res{};

  for(int i{}; i < (int)s.size() - (int)pat.size() + 1;  ++i) {
    ll curr{a.get_hash(i, i + pat.size() - 1)};
    if(p == curr)
      ++res;
  }

  cout << res << '\n';
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

