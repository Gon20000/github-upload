#include <cstdlib>
#include <iostream>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll randNum(ll x, ll y) {
  return  x + rand() % (y - x + 1);
}

int main(int argc, char** argv) {
  srand(atoi(argv[1]));
  ll n{randNum(1, 100)};
  ll m{randNum(1, min(n, 50ll))};

  cout << n << ' ' << m << '\n';

  return 0;
}

