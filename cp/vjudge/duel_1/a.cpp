#include <bits/stdc++.h>
using namespace std;
using ll = long long;
  
void solve() {
  int a{}, b{};
  cin >> a >> b;

  int res{a};
  ll curr{b};

  --a;
  if(a % 4 == 0)
    curr ^= a;
  else if(a % 4 == 1)
    curr ^= 1;
  else if(a % 4 == 2)
    curr ^= (a + 1);

  if(curr == a + 1)
    res += 2;
  else if(curr != 0) {
    ++res;
  }

  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
