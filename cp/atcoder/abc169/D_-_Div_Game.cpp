#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

constexpr int N{static_cast<int>(1e6) + 1};
vector<int> sieve(N, 1);

void init_sieve() {
  for(int i{2}; i < N; ++i) {
    if(sieve[i] != 1)
      continue;

    for(int j{i + i}; j < N; j += i) {
      --sieve[j];
    }
  }
}

void solve() {
  init_sieve();

  ll n{};
  cin >> n;

  ll res{};
  for(int i{2}; i < N; ++i) {
    if(sieve[i] < 0 || n % i != 0)
      continue;

    n /= i;
    ++res;
  }

  cout << res + (n >= N) << '\n';
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

