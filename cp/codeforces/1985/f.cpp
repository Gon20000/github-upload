#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct customLess {
  bool operator()(const pair<ll, ll> x, const pair<ll, ll> y) {
    if (x.second > y.second)
      return true;
    if (x.second < y.second)
      return false;    return x.first > y.first;
  }
};

void solve() {
  int h{}, n{};
  cin >> h >> n;

  vector<ll> a(n), s(n);
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, customLess> q;

  for(ll& x : a) {
    cin >> x;
    h -= x;
  }

  for(int i{}; i < n; ++i) {
    cin >> s[i];
    q.push({i, s[i] + 1});
  }

  ll i{1};
  while(h > 0 && !q.empty()) {
    pair<ll, ll> curr{q.top()};
    q.pop();

    i = max(i, curr.second);
    h -= a[curr.first];
    q.push({curr.first, s[curr.first] + curr.second});
  }

  cout << i << '\n';
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

