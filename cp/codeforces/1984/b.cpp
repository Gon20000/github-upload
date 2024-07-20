#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  ll num{};
  cin >> num;

  int l{0}, r{8};
  int carry{};
  while(num >= 100) {
    int curr{num % 10};
    if(curr - carry < l || curr - carry > r) {
      printf("NO\n");
      return;
    }

    carry = 1;
    num /= 10;
  }

  num -= carry;
  if(num >= 10 && num <= 18)
    printf("YES\n");
  else {
    printf("NO\n");
  }
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
