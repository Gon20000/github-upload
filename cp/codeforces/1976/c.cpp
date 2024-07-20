#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{}, m{};
  cin >> n  >> m;

  vector<ll> p(n + m + 1), t(n + m + 1), ans(n + m + 1);
  bool check[n + m + 1];
  memset(check, false, sizeof check);

  for(ll& x : p)
    cin >> x;

  for(ll& x : t) {
    cin >> x;
  }

  set<ll> bad_p{}, bad_t{};
  ll res{}, x{}, y{};
  for(int i{}; i < n + m; ++i) {
    if(x == n) {
      res += t[i];
      if(p[i] > t[i]) 
        bad_p.insert(i);
      ++y;
    }
    else if(y == m) { 
      res += p[i];
      if(t[i] > p[i])
        bad_t.insert(i);
      check[i] = true;
      ++x;
    }
    else if(p[i] > t[i]) {
      ++x;
      res += p[i];
      check[i] = true;
    }
    else if(t[i] > p[i]){
      ++y;
      res += t[i];
    }
  }

  for(int i{}; i < n + m; ++i) {
    ll copy{res};
    if(check[i]) {
      copy -= p[i];
      
      auto it{bad_p.upper_bound(i)};
      if(it == bad_p.end())
        copy += p[n + m];
      else {
        copy -= t[*it];
        copy += p[*it];

        copy += t[n + m];
      }
    }
    else {
      copy -= t[i];

      auto it{bad_t.upper_bound(i)};
      if(it == bad_t.end()) 
        copy += t[n + m];
      else {
        copy -= p[*it];
        copy += t[*it];

        copy += p[n + m];
      }
    }

    cout << copy << ' ';
  }

  cout << res << '\n';

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

