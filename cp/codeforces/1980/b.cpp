#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{}, f{}, k{};
  cin >> n >> f >> k;

  vector<ll> arr(n);
  for(ll& x : arr)
    cin >> x;

  ll element{arr[f - 1]};
  sort(arr.begin(), arr.end(), greater<ll>());

  ll last{arr[k - 1]};
  ll last2{-1};
  if(k < arr.size())
    last2 = arr[k];

  if(last > element)
    cout << "NO\n";
  else if(last < element)
    cout << "YES\n";
  else {
    if(last2 == element)
      cout << "MAYBE\n";
    else {
      cout << "YES\n";
    }
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

