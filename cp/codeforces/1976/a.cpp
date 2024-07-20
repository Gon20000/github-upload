#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{};
  cin >> n;

  string str{};
  cin >> str;

  int dig{0};
  char chr{'a'};
  bool dig1{false}, chr1{false};

  for(int i{}; i < n; ++i) {
    if(str[i] >= '0' && str[i] <= '9') {
      if(dig1 && str[i] - '0' < dig) {
        cout << "NO\n";
        return;
      }
      dig = str[i] - '0';
      dig1 = true;
    }
    else if(str[i] >= 'a' && str[i] <= 'z') {
      if(chr1 && str[i] < chr) {
        cout << "NO\n";
        return;
      }
      else if(i < n - 1 && str[i + 1] >= '0' && str[i + 1] <= '9') {
        cout << "NO\n";
        return;
      }
      chr = str[i];
      chr1 = true;
    }
    else {
        cout << "NO\n";
        return;
    }
  }

  cout << "YES\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  cin >> t;

  while(t--)
    solve();

  return 0;
}
