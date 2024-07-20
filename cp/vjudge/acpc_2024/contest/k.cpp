#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{};
  string str{};
  cin >> str >> n;

  --n;

  string nw{};
  for(int i{}; i < str.size(); ++i) {
    if(abs(i - n) == 1)
      continue;

    nw += str[i];
  }

  sort(nw.begin(), nw.end());

  string res{};
  int j{};
  for(int i{}; i < str.size(); ++i) {
    if(abs(i - n) == 1) {
      res += str[i];
      continue;
    }

    res += nw[j];
    ++j;
  }

  cout << res << '\n';
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
