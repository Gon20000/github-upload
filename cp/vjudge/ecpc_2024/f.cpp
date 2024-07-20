#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const ll max_size{200000}; 
ll seg[4 * max_size];
ll arr[max_size];
 
 
void recalc(int idx) {
   seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]); 
}
 
void build(int idx, int left, int right) {
    if (left == right) {
        seg[idx] = arr[left]; // leaf node
    }
    else {
        int mid {left + (right - left)/ 2};
        build(2 * idx + 1, left, mid);
        build(2 * idx + 2, mid + 1, right);
        recalc(idx);
    }
}
 
ll query(int idx, int left, int right, int x, int y) {
    if (x <= left && y >= right) {
        return seg[idx];
    }
    else {
        ll res {};
        int mid {left + (right - left) / 2};
        
        if (x <= mid) {
            res = max(res, query(2 * idx + 1, left, mid, x, y));
        }
 
        if (mid < y) {
            res = max(res, query(2 * idx + 2, mid + 1, right, x, y));
        }
        
        return res;
    }
}

void solve() {
  ll n{};
  cin >> n; 

  for(ll i{}; i < n; ++i)  {
    ll x{};
    cin >> x;

    arr[i] = x;
  }

  build(0, 0, n - 1);
  
  set<ll> s{};
  vector<ll> res(n - 1);
  
  ll r{-1};
  for(ll i{}; i < n - 1; ++i) {
    s.insert(arr[i]);
    if(r == -1 || r == arr[i])
      r = query(0, 0, n - 1, i + 1, n - 1);

    auto it{s.upper_bound(r)};
    ll l = distance(s.begin(), it);
    res[i] = (ll)s.size() - l;
  } 

  for(int i{}; i < n - 2; ++i)
    cout << res[i] << ' ';
  cout << res[n - 2] << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  while(t--)
    solve();
  return 0;
}
