#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  vector<string> arr{"pocket watches", "telescopes", "steam engines", "telephones", "airplanes", "terraforming",
  "exploration", "relaxing","going above and beyond", "second chances", "the origin", "empowering the youth", "ECPC"};
  cout << arr[(n - 1508) / 100]  << '\n';
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

