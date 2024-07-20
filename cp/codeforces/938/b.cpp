#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{}, c{}, d{};
  cin >> n >> c >> d;

  map<int, int> mp{};
  int x{INT_MAX};

  for(int i{}; i < n*n; ++i) {
    int e{};
    cin >> e;

    x = min(x, e);
    ++mp[e];
  }

  vector<int> row(n);
  row[0] = x;


  for(int i{0}; i < n; ++i) {
    if(i > 0)
        row[i] = row[i - 1] + c;
    if(!mp.count(row[i])) {
      cout << "NO\n";
      return;
    }
    else {
      --mp[row[i]];
    }
  }

  for(int j{1}; j < n; ++j) {
    row[0] += d;
    
    for(int i{0}; i < n; ++i) {
      if(i > 0)
        row[i] = row[i - 1] + c;
      if(!mp.count(row[i])) {
        cout << "NO\n";
        return;
      }
      else {
        --mp[row[i]];
      }
    }
  }

    for(auto [l, r] : mp) {
        if(r != 0) {
            cout << "NO\n";
            return;
        }
    }
  cout << "YES\n";
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
