#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{}, m{};
  cin >> n >> m;

  pair<ll, ll> high{0, 0};
  vector<string> grid(n);

  int j{};
  for(string& x : grid) {
    ++j;
    cin >> x;
    int cnt{}, curr{};
    for(int i{}; i < m; ++i) {
      if(x[i] == '.') {
        curr = max(curr, cnt);
        cnt = 0;
      }
      else{
        ++cnt;
      }
    }
    curr = max(cnt, curr);

    if(curr > high.second)
      high = {j, curr};
  }

  int i{};
  int l1{-1}, r1{-1}, l2{}, r2{};
  string& a{grid[high.first - 1]};
  while(i < m) {
    if(a[i] == '.') {
      if(r2 - l2 > r1 - l1) {
        l1 = l2;
        r1 = r2;
      }
      ++i;
    }
    else {
      l2 = i;
      while(i < m && a[i] == '#') {
        ++i;
        r2 = i;
      }
    }
  }

  if(r2 - l2 > r1 - l1) {
    l1 = l2;
    r1 = r2;
  }
  // printf("%d %d - %d %d\n", l1, r1, l2, r2);
  cout << high.first << ' ' << l1 + ((r1 - l1) / 2) + 1 << '\n';
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

