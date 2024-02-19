#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n;
    cin>>n;
    deque<ll>p;
    deque<ll>k;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        p.push_back(x);
        k.push_back(x);
    }
    sort(k.begin(),k.end());
    bool ok=0,ko=0;
    for(int i=0;i<n;i++){
        if(p[i]!=k[i]){
            ok=1;
            break;
        }
    }
    if (ok==1){
    ll ctr=0;
    for(int i=0;i<n;i++){
        ko=0;
        auto it=p.rbegin();
        ll x=*it;
        p.push_front(x);
        p.pop_back();
        ctr++;
        if (p==k)
        ko=0;
        else
        ko=1;
        if (ko==0)
        break;
    }
    if (ko==0)
    cout<<ctr;
    else
    cout<<-1;
    }
    else
    cout<<0;
    // for(int i=0;i<n;i++){
    //     cout<<p[i]<<endl;
    // }
        return 0;
}






/*ll n;
   cin>>n;
   vector<ll>v(n);
   for (ll i=0;i<n;i++){
    cin>>v[i];
   }
   ll ctr=0,freq[3]{0},stop;
   bool one=0;
    for (ll i=0;i<v.size();i++){
    if (v[i]>0){
            stop=i;
    if (v[i]==1)
    one=1;
    }
    else if (v[i]==0||(n-i)==1){
        cout<<1<<endl;
    if (one==1){
    for (ll j=stop;j<i;j++){
    v[i]--;
    }
    ctr++;
    }
    else{
    for (ll j=stop;j<i;j++){
    v[i]-=2;
    }
    ctr++;
    }
    }
    }
   cout<<ctr;*/

