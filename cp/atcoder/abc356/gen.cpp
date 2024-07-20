#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int num(int x, int y) {
  return x + rand() % (y - x + 1);
}

int main(int argc, char* argv[]) {
  srand(stoi(argv[1]));

  int n{num(1, 15)}, m{num(1, 10)};
  int k{num(1, n)};

  cout << n << ' ' << m << ' ' << k << '\n';

  for (size_t i = 0; i < m; i++) {
    int c{num(1, n)};
    cout << c << ' ';

    set<int> s{};
    while(c--) {
      int x{num(1, n)};
      while(s.count(x))
        x = num(1, n);

      cout << x << ' ';
      s.insert(x);
    }

    cout << (num(0, 1) ? "o" : "n") << '\n';
  }

  return 0;
}
