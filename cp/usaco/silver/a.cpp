#include <bits/stdc++.h>
using namespace std;

const int mxn=1e5+1;
int n,cows[mxn];

int min_dist(){
  if(cows[n-1] -cows[1]==n-2&&cows[n]-cows[n-1]>2) return 2;
  if(cows[n]-cows[2]==n-2&&cows[2]-cows[1]>2) return 2;
  int res=0;
  for(int ll=1,rr=1;ll<=n&&rr<=n;){
    if(rr<n&&cows[rr+1]-cows[ll]<=n-1) rr++;
    else res=max(res,rr-ll+1),ll++;
  }
  return n-res;
}

int max_dist(){
  return max(cows[n-1]-cows[1],cows[n]-cows[2])-(n-2);
}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for(int i=1;i<=n;i++)
    cin >> cows[i];
  sort(cows+1,cows+n+1);
  cout << min_dist() << '\n' << max_dist() << '\n';
}
