#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, m{};
  cin >> n >> m;

  set<int> unvisited{};
  for(int i{1}; i <= n; ++i)
    unvisited.insert(i);

  while(m--) {
    string str{};
    cin >> str;

    if(str[0] == 'r') {
      auto it{unvisited.begin()};
      int id{*it};
      unvisited.erase(it);
      cout << id << '\n';
    }
    else {
      int x{};
      cin >> x;

      unvisited.insert(x);
    }
  }
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

