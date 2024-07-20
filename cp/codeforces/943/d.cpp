#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{}, k{}, pb{}, ps{};
  cin >> n >> k >> pb >> ps;

  --pb; --ps;

  vector<ll> a(n), p(n);
  for(ll& x : p) {
    cin >> x;
    --x;
  }
    ll maxi{};
  for(ll& x : a) {
  cin >> x;
  maxi = max(x, maxi);
  }

  int cnt1{}, cnt2{};
  ll res1{}, res2{}, pos1{k * a[pb]}, pos2{k * a[ps]};
  while(maxi > a[pb] && cnt1 < min(k, n)) {
    res1 += a[pb];
    pb = p[pb];
    ++cnt1;
  }

  while(maxi > a[ps] && cnt2 < min(n ,k)) {
    res2 += a[ps];
    ps = p[ps];
    ++cnt2;
  }

  res1 += (k - cnt1) * a[pb];
  res2 += (k - cnt2) * a[ps];
  res1 = max(res1, pos1);
  res2 = max(res2, pos2);
  cout << (res1 == res2 ? "Draw" : res1 > res2 ? "Bodya" : "Sasha") << '\n';
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



