#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  map<int, ll> mp{};
  ll res{};

  while(n--) {
    string str{};
    cin >> str;
    
    int num{};
    for(char x : str) {
      num ^= (1 << (x - 'a'));
    }

    res += mp[num]++;
    for(int i{}; i < 32; ++i)
      res += mp[num ^ (1 << i)];
  }

  cout << res << '\n';
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

