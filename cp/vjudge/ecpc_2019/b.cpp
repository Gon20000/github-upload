#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  vector<ll> arr(3);
  for(int i{}; i < 3; ++i)
    cin >> arr[i];

  sort(arr.begin(), arr.end());

  ll a{arr[0]}, b{arr[1]}, c{arr[2]}, k{};
  cin >> k;


  auto getArea = [&](ld d) {
    ld S{(a + d + b + c) / 2.0};
    return sqrt(S * (S - a - d) * (S - b) * (S - c));
  };

  ld l{}, r{k}, res{};
  while(r - l >= 1e-8) {
    ld mid{l + (r-l) / 2.0};

    if(a + mid >= b + c) {
      r = mid;
      continue;
    }
    else if(c >= b + a + mid) {
      l = mid;
      continue;
    }

    if(getArea(mid) <= getArea((mid + 1e-8)))
      l = mid;
    else {
      r = mid;
    }

    res = max(res, getArea(mid));
  }

  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("sticks.in", "r", stdin);

  int t{};
  cin >> t;

  while(t--)
    solve();

  return 0;
}
