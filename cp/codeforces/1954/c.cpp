#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  string x{}, y{};
  cin >> x >> y;

  int take{};

  for(int i{}; i < x.size(); ++i) {
    if(!take) {
      if(x[i] > y[i])
        take = -1;
      else if(x[i] < y[i])
          take = 1;
    }
    else {
      if(take == -1 && x[i] > y[i]) 
          swap(x[i], y[i]);
      else if(take == 1 && y[i] > x[i])
          swap(x[i], y[i]);
    }
  }

  cout << x << '\n' << y << '\n';
}

int main() {
  int t{};
  cin >> t;

  while(t--)
      solve();

  return 0;
}
