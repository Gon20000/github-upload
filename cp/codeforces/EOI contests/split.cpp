// not my code
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld double
#define usaco(fname) freopen(#fname ".in","r",stdin);freopen(#fname ".out","w",stdout);
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// const ll INF = 1e18;
const int INF = 1e9;
const int mod = 1e9+7;
const lld PI = acos(-1.0);
int di[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dj[] = {0, 0, 1, -1, 1, -1, 1, -1};
#define vb vector<bool>
#define vvb vector<vb>
#define vs vector<string>
#define ff first
#define se second
#define all(x) x.begin(),x.end()
#define endl '\n'

int n;
vector<int>pref;

// idx = starting point
bool dnc(int pivsum, int idx) {
  // if out bounds, already splitted all?
  if (idx > n) {
    if (idx == n+1) return true; 
    else return false;
  }

  int l = idx, r = n;
  int idxans = idx;
  while (l <= r) {
    int mid = (l+r)>>1;

    // search for same sum
    if (pref[mid] - pref[idx-1] >= pivsum) {
      r = mid-1;
      idxans = mid;
    } else {
      l = mid+1;
    }
  }

  int ans = pref[idxans] - pref[idx-1];
  if (ans != pivsum) return false;
  return true && dnc(pivsum, idxans+1);
}

void solve() {
  cin>>n;
  pref = vector<int>(n+1);
  for (int i = 1; i <= n; i++) {
    int tmp;cin>>tmp;
    pref[i] = pref[i-1] + tmp;
  }

  if (n == 1) {
    cout << "NO" << endl;
    return;
  }

  for (int i = 1; i <= n-1; i++) {
    int pivsum = pref[i];
    if (dnc(pivsum, i+1)) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t=1;
  while(t--) solve();

  return 0;
}