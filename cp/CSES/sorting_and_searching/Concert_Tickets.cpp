#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, m{};
  cin >> n >> m;

  multiset<int> s{};
  while(n--) {
    ll x{};
    cin >> x;
    s.insert(x);
  }

  while(m--) {
    ll x{};
    cin >> x;

    auto it{s.upper_bound(x)};
    if(it == s.begin())
      cout << -1 << '\n';
    else {
      --it;
      cout << *(it) << '\n';
      s.erase(it);
    }
  }
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

