#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n{};
  string str;
  cin >> n >> str;

  map<char, int> mp{};  
  for(int i{}; i < n; ++i) {
    ++mp[str[i]];
  }

  int m{};
  cin >> m;

  while(m--) {
    int used{}, res{};
    char x{};
    cin >> used >> x;

    if(n - mp[x] <= used) {
      cout << n << '\n';
      continue;
    }

    int r{};
    for(int l{}; l < n; ++l) {
      while(r < n && (str[r] == x  || used > 0)) {
        if(str[r++] == x)
          continue;
        
        --used;
      }

      res = max(res, r - l);
      if(str[l] != x)
        ++used;
    }

    cout << res << '\n';
  }
}
