#include bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n), suff(n), pref(n);
  for (size_t i = 0; i < n; i++) {
    cin >> arr[i];
    suff[i] = pref[i] = arr[i];
    pref[i] += i;
    suff[i] -= i;
  }

  for (size_t i = 1; i < n; i++) {
    pref[i] = max(pref[i], pref[i - 1]);
  }

  for (int i = n - 2; i >= 0; i--) {
    suff[i] = max(suff[i], suff[i + 1]);
  }

  ll res{};
  for (size_t i = 1; i < n - 1; i++) {
    res = max(res, pref[i - 1] + suff[i + 1] + arr[i]);
  }

  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  cin >> t;

  while(t--)
    solve();

  return 0;
}
