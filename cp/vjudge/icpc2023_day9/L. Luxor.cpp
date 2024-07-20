#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  map<ll, ll> mp{};
  for(int i{}; i < 7; ++i) {
    ll x{};
    cin >> x;

    mp[x] = i;
  }

  cout << "the " << vector<string>{"first", "second", "third", "fourth", "fifth", "sixth", "seventh"}[mp.begin()->second] << '\n';

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

