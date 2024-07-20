#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{}, m{}, k{};
  cin >> n >> m >> k;

  n -= ceil(n / static_cast<double>(m));

  cout << (n > k ? "YES": "NO") << '\n';
}

int main() {
  int t{};
  cin >> t;

  while(t--)
      solve();

  return 0;
}
