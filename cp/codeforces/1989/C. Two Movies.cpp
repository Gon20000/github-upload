#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  vector<ll> a(n), b(n);
  for(ll& x : a)
    cin >> x;
  for(ll& x : b)
    cin >> x;

  ll neg{}, pos{}, x{}, y{};
  for(int i{}; i < n; ++i) {
    if(a[i] > b[i])
      x += a[i];
    else if(a[i] < b[i])
      y += b[i];
    else if(a[i] == 1)
      ++pos;
    else if(a[i] == -1)
      ++neg;
  }

  if(x < y)
    swap(x, y);

  if(neg) {
    if(x - neg >= y) {
      x -= neg;
      neg = 0;
    }
    else {
      neg -= x - y;
      y -= neg / 2;
      x = y;
      y -= neg % 2;
    }
  }

  if(pos) {
    if(y + pos <= x) {
      y += pos;
      pos = 0;
    }
    else {
      pos -= x - y;
      x += pos / 2;
      y = x;
      x += pos % 2;
    }
  }
  
  cout << y << '\n';
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

