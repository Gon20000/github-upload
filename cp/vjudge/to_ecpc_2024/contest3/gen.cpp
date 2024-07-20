#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll getRand(ll x, ll y) {
  return x + (rand() % (y - x + 1));
}

int main(int argc, char* argv[]) {
  srand(stoi(argv[1]));
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  

  ll n{getRand(3, 6)};
  cout << n << '\n';
  for(int i{}; i < n - 1; ++i)
    cout << getRand(1, 100) << ' ';
  cout << getRand(1, 100) << '\n';

  return 0;
}

