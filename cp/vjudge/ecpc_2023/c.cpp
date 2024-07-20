#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  ll n{}, x{}, m{};
  cin >> n >> x >> m;

  cout << (x >= n && x <= m ? "Yes" : "No") << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  // cin >> t;

  while(t--)
    solve();

  return 0;
}
