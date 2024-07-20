#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("collectingofficer.in", "r", stdin);

  ll t;
  cin>>t;
  while (t--){
    ll x{}, res{INT_MAX};
    string s;
    cin >> x >> s;

    for (ll i=0;i<x;i++){
      if (s[i]!='A')
        continue;

      char curr{'A'};
      for (ll j=i;j<x;j++){
        if (s[j] == curr){
          if (s[j]=='Z'){
            res = min(res, j - i + 1);
            break;
          }
          
          ++curr;
        }
      }
    }

    cout<< res <<endl;

  }
  return 0;
}
