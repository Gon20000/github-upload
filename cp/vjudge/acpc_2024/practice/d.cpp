#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll l{1}, r{static_cast<ll>(1e9)};

  while(l <= r) {
    ll mid{l + (r-l) / 2};
    cout << mid << endl;
    
    char inp{};
    cin >> inp;

    if(inp == '<') {
      r =  mid - 1;
    }
    else if(inp == '>') {
      l = mid + 1;
    }
    else {
      cout << "! " << mid << endl;
      break;
    }
  }

  return 0;
}
