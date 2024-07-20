#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

class HashedString { 
  ll m_base{}, m_mod{};
  static inline vector<ll> m_pow{1};
  vector<ll> m_hash{};


public:
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

  HashedString a(str);

  bitset<1'000'001> visited{};
  for(int i{1}; i < str.size(); ++i) {
    if(visited[i])
      continue;

    ll hash{a.getHash(0, i)};
    int j{i};
    bool check{true};

    for(; j < str.size() - i; j += i) {
      ll hash2{a.getHash(j, j + i)};
      if(hash != hash2) {
        check = false;
        break;
      }
    } 

    if(j < str.size() && a.getHash(j, str.size() - 1) != a.getHash(0, str.size() - j - 1)) {
      check = false;
    }

    if(check) {
      for(int j{i}; j < str.size(); j += i) {
        visited[j] = true;
      }
    }
  }

  for(int i{1}; i < str.size(); ++i)
    if(visited[i])
      cout << i << ' ';
  cout << str.size() << '\n';
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

