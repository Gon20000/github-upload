#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld double
#define int ll
#define usaco(fname) freopen(#fname ".in","r",stdin);freopen(#fname ".out","w",stdout);
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// const ll INF = 1e18;
const int INF = 1e9;
const int mod = 1e9+7;
const lld PI = acos(-1.0);
int di[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dj[] = {0, 0, 1, -1, 1, -1, 1, -1};
#define debug(x) cout << #x << ": " << x << endl;
#define add(a, b) a += b, a %= mod
#define mul(a, b) ((a % mod) * (b % mod)) % mod
#define all(x) x.begin(),x.end()

void solve() {
  int n;cin>>n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  vector<int> b(n-1);
  for (int i = 0; i+1 < n; i++) b[i] = __gcd(a[i], a[i+1]);

  vector<bool> pref(n-1, 1), suff(n-1, 1);
  for(int i = 1; i < n-1; i++) {
    pref[i] = pref[i-1];
    if (b[i] < b[i-1]) {
      pref[i] = 0;
    }
  }

  function<bool(int)> chk = [&](int exclude_idx) {
    int before = -1;
    vector<int> bruh;
    for (int i = 0; i < n; i++) {
      if (i == exclude_idx) continue;
      if (before == -1) {
        before = a[i];
        continue;
      }
      bruh.push_back(__gcd(before, a[i]));
      before = a[i];
    }
 
    // debug(b);
    // debug(bruh);
    return is_sorted(all(bruh));
  };

  for (int i = n-3; i >= 0; i--) {
    suff[i] = suff[i+1];
    if (b[i] > b[i+1]) {
      suff[i] = 0;
    }
  }

  for (int i = 0; i+2 < n; i++) {
    int x = __gcd(a[i], a[i+2]);

    // debug(i);
    // debug(pref[i-1]);
    // debug(b[i-1]);
    // debug(b[i+2]);
    // debug(suff[i+2]);
    if ((i-1 >= 0 ? pref[i-1] && x >= b[i-1] : 1) && (i+2 < n-1 ? x <= b[i+2] && suff[i+2] : 1)) {
      cout << "YES\n";
      return;
    }
  }

  if (chk(0) || chk(n-1)) cout << "YES\n";
  else cout << "NO\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--) solve();

  return 0;
}

