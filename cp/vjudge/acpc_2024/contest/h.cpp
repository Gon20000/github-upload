#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  ll m{}, n{};
  cin >> m >> n;
  m /= n;

  if(m >= 150)
    cout << "VERY HAPPY\n";
  else if(m >= 100) 
    cout << "HAPPY\n";
  else
    cout << "SAD\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  /*cin >> t;*/
  while(t--)
    solve();

  return 0;
}
