#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while(t--){
    long double x{}, y{};
    cin >> x >> y;
    long double res {x*y*2};
    cout << std::setprecision(8) << res << '\n';
  }
}
