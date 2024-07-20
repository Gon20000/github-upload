#include <bits/stdc++.h>
using namespace std;
using ld =  long double;

bool check(ld x, ld y) {
  return abs(x - y) <= 1e-6;
}

int main() {
  ld x{}, l{}, r{(1 << 5)};
  cin >> x;

  while(l < r) {
    ld mid{l + (r - l) / 2.0};
    ld num{mid * mid};

    if(check(num, x)) {
      cout << mid << '\n';
      break;
    }
    else if (num < x) {
      l = mid;   
    }
    else {
      r = mid;
    }
  }

  return 0;
}
