#include <bits/stdc++.h>
using namespace std;

int num(int x, int y) {
  return x + (rand() % (y - x + 1));
}

int main(int argc, char* argv[]) {
  srand(stoi(argv[1]));
  int t{num(1, 5)};
  cout << t << '\n';

  while(t--) {
    int n{num(1, 5)};
    cout << n << '\n';

    for(int i{}; i < 2 * n - 1; ++i) {
      cout << num(-1, 1);
      cout << (i == n - 1 ? '\n' : ' ');
    }
    cout << num(-1, 1) << '\n';
  }

  return 0;
}

