#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

bool check(int i, int k, const string& str) {
  for(int j{}; j < str.size(); ++j) {
    if(str[(i + j) % str.size()] == str[(i + k + j) % str.size()])
      return false;
  }

  return true;
}

void solve() {
  int n{}, k{};
  cin >> n >> k;

  string str{};
  cin >> str;

  vector<ll> sum(n + 1);
  for(int i{}; i < n; ++i) {
    sum[i + 1] = sum[i] + (str[i] == '1');
  }

  if(n == k) {
    cout << (sum[n] == n || sum[n] == 0 ? n : -1) << '\n';
    return;
  }

  ll res{-1};
  for(int i{2}; i < n - k; ++i) {
    if(sum[i + k] - sum[i] == k  || sum[i + k] - sum[i] == 0) {
      if(check(i, k, str)) {
        res = i;
        break;
      }
    }
  }

  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{};
  cin >> t;

  while(t--)
    solve();

  return 0;
}

