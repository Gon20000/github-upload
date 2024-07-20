#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll high{static_cast<ll>(1e6) + 1};
int num(int x, int y) {
  return x + rand() % (y - x + 1);
}

int main(int argc, char* argv[]) {
  srand(stoi(argv[1]));

  int t{num(3, 6)};
  cout << t << '\n';

  for(int i{}; i < t - 1; ++i)
    cout << num(0, high) << ' ';
  cout << num(0, high) << '\n';

  return 0;
}
