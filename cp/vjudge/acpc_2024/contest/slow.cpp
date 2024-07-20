#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  ll res{LLONG_MAX}, n{};
  cin >> n;

  ll high{ll(ceil(sqrt(n))) + 5};
  ll x{}, y{}
  for(int i{high}; i >= 0; --i) {
    for(int j{}; j <= i; ++j) {
      ll curr{i * i + j * j};
      if(curr > n)
        curr = curr - n;
      else
        curr = n - curr;

      if(res > curr) {
        res = curr;
        x = i; y = j;
      }
      /*if(res == 0) {*/
      /*  cout << i << ' ' << j << '\n';*/
      /*  return;*/
      /*}*/
    }
  }

  /*cout << x << ' ' << y << '\n';*/
  cout  << res  << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{};
  cin >> t;
  while(t--)
    solve();

  return 0;
}
