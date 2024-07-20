#include <bits/stdc++.h>
using namespace std;

int main() {
  int n{};
  cin >> n;

  vector<char> str(n);
  map<char, int> mp{};
  set<char> s{};

  for(char& x : str) {
    cin >> x;
    s.insert(x);
  }

  int r{0}, res{INT_MAX};
  for(int l{}; l < n; ++l) {
    while(r < n && mp.size() < s.size()) {
      ++mp[str[r]];
      ++r;
    }

    if(mp.size() == s.size())
      res = min(res, r - l);

    --mp[str[l]];
    if(mp[str[l]] == 0)
      mp.erase(str[l]);
  }

  cout << res << '\n';
  return 0;
}
