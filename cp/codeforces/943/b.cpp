#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{}, m{};
  cin >> n >> m;

  string a{}, b{};
  cin >> a >> b;

  int i{}, j{}, res{};
  
  while(i < a.size() && j < b.size()) {
    while(a[i] != b[j] && j < b.size()) 
      ++j;
    
    if(i < a.size() && j < b.size() && a[i] == b[j]) {
      ++res;
      ++j;
    }
    ++i;
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
