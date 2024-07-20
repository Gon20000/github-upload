#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod{ll(1e9) + 7};

int main() {
  ll sum{};
  cin >> sum;

  sum *= (sum + 1);
  if(sum % 4 != 0) {
    cout << 0 << '\n';
    return;
  }

  sum /= 4;
  
}

/*
1: [1]
2: [2]
3 : [1,2], [3]
4: [1, 3], [4]
5: [1,4], [2,3], [5]
6: [1,2,3], [1,5], [2,4], [6]
7: [1, 2, 4] = [1,6], [2,5], [3,4], [0, 7]

7 + 3: [1,2,3,4], [1, 2, 0, 7], [1, 3, 6], [1,2, 3, 5], [0, 3, 7]
*/
