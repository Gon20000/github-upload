#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string str{};
  cin >> str;

  bool l1{false}, l2{false}, r1{false}, r2{false};

  for (size_t i = 0; i < str.size(); i++) {
    if(str[i] != 'B') 
      continue;

    char left{}, right{};
    if(i > 0)
      left = str[i - 1];
    if(i < str.size() - 1)
      right = str[i + 1];

    if(left == 'A' && !l1) {
      l1 = true;
    }
    else if(l1 && right == 'A')
      r1 = true;

  }
  
  for (size_t i = 0; i < str.size(); i++) {
    if(str[i] != 'B') 
      continue;

    char left{}, right{};
    if(i > 0)
      left = str[i - 1];
    if(i < str.size() - 1)
      right = str[i + 1];

    if(right == 'A' && !l2) {
      l2 = true;
      i += 2;
    }
    else if(l2 && left == 'A')
      r2 = true;

  }

  cout << ((l1 && r1) || (l2 && r2) ? "YES": "NO") << '\n';

  return 0;
}
