#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n{}, m{};
  cin >> n >> m;
  vector<ll> a(n), b(m);

  for(int i{0}; i < n; ++i) {
    cin >> a[i]; 
  }

  for(int i{0}; i < m; ++i) 
      cin >> b[i];

  sort(b.begin(), b.end());
  b.erase(std::unique(b.begin(), b.end()), b.end());

  ll res{};

  for(ll& e : a) {
    ll l{}, r{m};

    while (l < r) {
      ll mid{l + (r - l) / 2};
      ll local{abs(b[mid] - e)};     
      if(mid + 1 < r && abs(b[mid + 1] - e) < local) {
        local = abs(b[mid + 1] - e);
        l = mid;
      }

      if(mid - 1 >= l && abs(b[mid - 1] - e) < local) {
        local = abs(b[mid - 1] - e);
        r = mid;
      }

      if(local == abs(b[mid] - e)) {
        res = max(res, local);
        break;
      }
    }
  }

  cout << res << '\n';
  return 0;
}
