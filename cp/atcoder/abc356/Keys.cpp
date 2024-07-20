#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, m{}, k{};
  cin >> n >> m >> k;

  ll st{0};
  /* Doesn't work in case of
   * 4 1 1 
   * 2 4 n
   * As 0 keys is a correct combination :)
   * for(int i{}; i < k ; ++i)
   * st = (st << 1ll) | 1ll;*/

  bitset<101> check{};
  vector<ll> tests(m);
  for(int i{}; i < m ; ++i) {
    int c{};
    cin >> c;

    while(c--) {
      int key{};
      cin >> key;
      --key;

      tests[i] |= (1ll << key);
    }

    char x{};
    cin >> x;
    check[i] = (x == 'o');
  }
  
  ll cnt{1ll << n}, res{};
  for(; st < cnt; ++st) {
    bool works{true};
    for(int i{}; i < m; ++i) {
      ll curr{__builtin_popcount(tests[i] & st)};
      if((check[i] && curr < k) || (!check[i] && curr >= k)) {
        works = false;
        break;
      }
    }

    if(works)
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

