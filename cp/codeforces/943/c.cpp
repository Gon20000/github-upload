#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{};
  cin >> n;

  vector<ll> a(n - 1), b{};
  for(ll& x : a)
  cin >> x;

  b.push_back(a[0] + 1);
  for(int i{}; i < a.size(); ++i) {
    ll x{max(a[i], b.back())};
    if(i < a.size() -  1)
      x =  max(x, a[i + 1] + 1);
 
    if(x % b.back() == a[i])
      b.push_back(x);
    else {
      b.push_back(x + (a[i] - (x % b.back())) % x);
      if(i < a.size() - 1 && b.back() <= a[i + 1])
        b[b.size() - 1] += b[b.size() - 2];
    }
    // 6

    //4 2 5 1 2

}

for(int i{}; i < b.size() - 1; ++i)
  cout << b[i] << ' ';
cout << b.back() << '\n';
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
