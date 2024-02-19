#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// BeginCodeSnip{Range Maximum Segment Tree}
class MaxSegTree {
  private:
	ll len;
	vector<ll> segtree;

  public:
	MaxSegTree(ll len) : len(len), segtree(2 * len) {}

	void set(ll ind, ll val) {
		for (segtree[ind += len] = val; ind > 1; ind >>= 1) {
			segtree[ind >> 1] = max(segtree[ind], segtree[ind ^ 1]);
		}
	}

	// maximum of the range [from, to)
	ll range_max(ll from, ll to) {
		ll max_ = INT32_MIN;
		for (from += len, to += len; from < to; from >>= 1, to >>= 1) {
			if ((from & 1) != 0) { max_ = max(max_, segtree[from++]); }
			if ((to & 1) != 0) { max_ = max(max_, segtree[--to]); }
		}
		return max_;
	}
};
// EndCodeSnip

ll find_lis(vector<ll> a) {
	// apply coordinate compression to all elements of the array
	vector<ll> sorted(a);
	sort(sorted.begin(), sorted.end());
	ll at = 0;
	map<ll, ll> coord_comp;
	for (ll i : sorted) {
		if (!coord_comp.count(i)) { coord_comp[i] = at++; }
	}
	// cmp(i) gives the compressed version of index i
	auto cmp = [&](ll i) -> ll { return coord_comp[a[i]]; };

	MaxSegTree dp(coord_comp.size());
	dp.set(cmp(0), 1);
	for (ll i = 1; i < a.size(); i++) {
		ll max_prev = dp.range_max(0, cmp(i));
		if (max_prev != INT32_MIN) {
			dp.set(cmp(i), max_prev + 1);
		} else {
			dp.set(cmp(i), 1);
		}
	}

	return dp.range_max(0, coord_comp.size());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n{};
    cin >> n;

    vector<ll> a{};
    while(n--) {
        ll x{};
        cin >> x;
        a.push_back(x);
    }

    cout << find_lis(a) << '\n';
}