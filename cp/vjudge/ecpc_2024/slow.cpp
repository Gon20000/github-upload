#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lll __int128_t
#define SZ(x) (int) x.size()

const int B[2] = {27, 31}, M[2] = {1'000'000'007, 998'244'353};
int power(int a, int b, int idx) {
	int ans = 1;
	while (b) {
		if (b & 1) {
			ans = 1ll * ans * a % M[idx];
		}
		a = 1ll * a * a % M[idx], b >>= 1;
	}
	return ans;
}
struct Hashing {
	string s;
	int n, base, invbase, idx;
	vector<int> inv, prf;
	Hashing(){}
	Hashing(string &_s, int _cur) {
		s = _s;
		n = SZ(s);
		idx = _cur;
		base = B[idx];
		invbase = power(base, M[idx] - 2, idx);
		inv.resize(n + 1);
		inv[0] = 1;
		for (int i = 1; i <= n; i++) {
			inv[i] = 1ll * inv[i - 1] * invbase % M[idx];
		}
		prf.resize(n + 1);
		prf[0] = 0;
		int pw = 1;
		for (int i = 0; i < n; i++) {
			prf[i + 1] = prf[i] + 1ll * pw * (s[i] - 'a' + 1) % M[idx];
			if (prf[i + 1] >= M[idx]) prf[i + 1] -= M[idx];
			pw = 1ll * pw * base % M[idx];
		}
	}
	int get(int l, int r) {
		int v = prf[r + 1] - prf[l];
		if (v < 0) v += M[idx];
		return 1ll * v * inv[l] % M[idx];
	}
};
const int N = 200'005;
vector<int> adj[N];
int st[N], en[N], dep[N], curt = 0;
vector<array<int, 2>> lvl[N];
array<Hashing, 2> h[N], hrev[N];
int anc[N][18];
void dfs(int i, int d) {
	dep[i] = d;
	st[i] = curt++;
	lvl[d].push_back({st[i], i});
	for (auto nxt : adj[i]) {
		dfs(nxt, d + 1);
	}
	en[i] = curt - 1;
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		for (int i = 0; i < n; i++) {
			adj[i].clear();
			lvl[i].clear();
		}
		char c[n];
		for (int i = 0; i < n; i++) {
			cin >> c[i];
		}
		for (int i = 1; i < n; i++) {
			int p;
			cin >> p;
			p--;
			anc[i][0] = p;
			for (int j = 1; j < 18; j++) {
				anc[i][j] = anc[anc[i][j - 1]][j - 1];
			}
			adj[p].push_back(i);
		}
		curt = 0;
		dfs(0, 0);
		for (int i = 0; i < n; i++) {
			string s;
			for (auto [dfstime, x] : lvl[i]) {
				s.push_back(c[x]);
			}
			for (int k = 0; k < 2; k++) {
				h[i][k] = Hashing(s, k);
			}
			reverse(s.begin(), s.end());
			for (int k = 0; k < 2; k++) {
				hrev[i][k] = Hashing(s, k);
			}
		}
		while (q--) {
			int v, k;
			cin >> v >> k;
			v--;
			for (int i = 17; i >= 0; i--) {
				if (k & (1 << i)) {
					v = anc[v][i];
				}
			}
			int d = dep[v] + k;
			int l = lower_bound(lvl[d].begin(), lvl[d].end(), (array<int, 2>) {st[v], 0}) - lvl[d].begin();
			int r = lower_bound(lvl[d].begin(), lvl[d].end(), (array<int, 2>) {en[v] + 1, 0}) - lvl[d].begin() - 1;
			bool ok = 1;
			int sz = SZ(lvl[d]);
			for (int i = 0; i < 2; i++) {
				ok &= h[d][i].get(l, r) == hrev[d][i].get(sz - 1 - r, sz - 1 - l);
			}
			if (ok) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
	return 0;
}   
