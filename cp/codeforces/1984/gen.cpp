#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int num(int x, int y) {
  return x + rand() % (y - x + 1);
}

int main(int argc, char* argv[]) {
  srand(stoi(argv[1]));

  int t{num(1, 5)};
  cout << t << '\n';
  while(t--) {
    int n{num(3, 6)};
    cout << n << '\n';

    for(int i{}; i < n - 1; ++i)
      cout << num(-100, 100) << ' ';

    cout << num(-100, 100) << '\n';
  }
  return 0;
}
