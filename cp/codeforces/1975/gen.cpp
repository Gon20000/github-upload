#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int random(int x, int y) {
  return x + (rand() % (y - x + 1));
}

int main(int argc, char* argv[]) {
  int t{5};

  srand(argc);
  
  cout << t << '\n';
  while(t--) {
    int n{random(5, 9)};
    cout << n << '\n';

    for(int i{}; i < n - 1; ++i) {
      cout << random(1, 100) << ' ';
    }

    cout << random(1, 100) << '\n';
  }

  return 0;
}
