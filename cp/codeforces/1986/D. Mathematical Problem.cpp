#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;
using ld = long double;

ll calc(const vector<ll>& str) {
  ll res{};
  for(const ll& x : str)
  res += x;
  return res;
}

ll toLL(const string& str) {
  ll res{};
  for(int i{}; i < str.size(); ++i) {
    res *= 10;
    res += str[i] - '0';
  }
  return res;
}

ll check(int idx, ll curr, ll last, const string& str, bool mult, bool done = false)  {
  if(idx >= str.size()) {
    if(curr == -1)
      curr = mult ? 1 : 0;
    return mult ? curr * last : curr + last;
  }
  else if(idx >= str.size() - 1 && !done)
    return LLONG_MAX;

  ll a{static_cast<ll>(str[idx] - '0')}, b{100ll};
  if(!done && idx + 1 < str.size()) {
    b = (str[idx] - '0') * 10 + (str[idx + 1] - '0');
  }
  if(b == 0)
    return 0;

  ll res{LLONG_MAX};
  if(mult) {
    a *= last;
    b *= last;
  }
  else if(idx != 0) {
    if(curr == -1)
      ++curr;
    curr += last;
  }

  if(a < b)
    res = min(res, check(idx + 1, curr, a, str, a <= 1, done));
  if(b != 100)
    res = min(res, check(idx + 2, curr, b, str, b <= 1, true));
  return res;
}

void solve() {
  int n{};
  string str{};

  cin >> n >> str;
  if (str.size() == 2) {
    cout << toLL(str) << '\n';
    return;
  }
  cout << min(toLL(str), check(0, -1, 0, str, false, false)) << '\n';;
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


