#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int num(int x, int y) {
  return x + rand() % (y - x + 1);
}

int main(int argc, char* argv[]) {
  srand(stoi(argv[1]));

  int n{num(3, 6)};
  cout << n << '\n';

  set<int> s{};
  for(int i{}; i < n - 1; ++i) {
    int x{num(1, 20)};
    while(s.count(x) != 0)
      x = num(1, 20);

    s.insert(x);
    cout << x << ' ';
  }

  int x{num(1, 20)};
  while(s.count(x) != 0)
    x = num(1, 20);

  cout << x << '\n';
  return 0;
}
