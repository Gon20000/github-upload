#include <bits/stdc++.h>
using namespace std;

int random(int x, int y) {
  return x + rand() % (y - x + 1);
}

int main(int argc, char* argv[]) {
  srand(stoi(argv[1]));

  int t{random(1, 10)};
  cout << t << '\n';

  for(int i{}; i < t; ++i) {
    int n{random(1, 10)};
    cout << n + 1 << '\n';

    vector<int> a(n);
    for(int& x : a)
      x = random(1, 10);

    for(int i{}; i < n - 1; ++i)
      cout << a[i] << ' ';
    cout << a[n - 1] << '\n';
  }
}
