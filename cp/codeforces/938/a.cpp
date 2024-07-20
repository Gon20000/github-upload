#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{}, a{}, b{};
  cin >> n >> a >> b;

  if(b > a * 2) {
    b = a * 2;
  }

  cout << (n / 2) * b + (n % 2) * a << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{};
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}
