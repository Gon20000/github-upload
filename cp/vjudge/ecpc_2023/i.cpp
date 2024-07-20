#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll siz{ll(1e6) + 5};
bitset<siz> sieve{};

void init() {
  sieve.set();
  sieve[0] = false;
  sieve[1] = false;

  for(int i{2}; i < siz; ++i) {
    if(!sieve[i])
      continue;

    for(int j{i * 2}; j < siz; j += i) {
      sieve[j] = false;
    }
  }
}

bool prime(ll x) {
  return sieve[x];  
}

void solve() {
  init();
  int n{};
  cin >> n;

  ll res{}, cnt{};
  vector<ll> arr(n);
  for(ll& x : arr) {
    cin >> x;
    if(x == 2)
      ++cnt;
  }

  for(int i{}; i < n; ++i) {
    if(arr[i] == 2)
        continue;

    if(prime(arr[i] + 2))
      res += cnt;
  }

  cout << 2 * res << '\n';
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

