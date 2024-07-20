#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n{}, a{}, b{};
  cin >> n >> a >> b;

  if(b < a) {
    cout << n * a << '\n';
    return;
  }

  ll l{min(n, b - a)}; 
  cout << (b * l - (l * (l - 1))/2) + (n - l) * a << '\n';
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
// 1192 - 27  
