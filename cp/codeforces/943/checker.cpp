#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ifstream file("in");
  ll t{}, n{};
  file >> t;

  for(int k{}; k < t; ++k) {
    file >> n;

    vector<ll> a(n - 1), b(n);
    for(ll i{}; i < n - 1; ++i) {
      file >> a[i];
    }

    for(ll i{}; i < n; ++i)
      cin >> b[i];

    for(ll i{1}; i < b.size(); ++i) {
      if(b[i] % b[i - 1] != a[i - 1] || b[i] > ll(1e9)) {
        cout << "Testcase " << k << '\n' << b[i] << ' ' << b[i - 1] << ' ' << -1 << '\n';
        return 0;
      }
    }
  }

  cout << 0 << '\n';
  return 0;
}
