#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int num(int x, int y) {
  return x + rand() % (y - x + 1);
}

int main(int argc, char* argv[]) {
  srand(stoi(argv[1]));

  int t{1};
  while(t--) {
    int n{num(3, 6)};
    cout << n << '\n';

    for(int i{}; i < n - 1; ++i)
      cout << num(1, 10) << ' ';

    cout << num(1, 10 << '\n';
  }
  return 0;
}
