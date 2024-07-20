#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n{}, t{};
  cin >> n >> t;
  vector<ll> a(n);
  for (ll &x : a)
  {
    cin >> x;
  }

  sort(a.begin(), a.end());
  ll sum{}, res{(ll)1e18}, l{}, r{(ll)1e18};

  while (l <= r)
  {
    sum = 0;
    ll mid{l + (r - l) / 2};
    auto last{upper_bound(a.begin(), a.end(), mid)};
    for (auto it{a.begin()}; it != last && it != a.end(); ++it)
    {
      sum += mid / *it;
      if(sum < 0)  {
        sum = LLONG_MAX;
        break;
      }
    }

    if (sum >= t)
    {
      r = mid - 1;
      res = min(res, mid);
    }
    else
  {
      l = mid + 1;
    }
  }

  cout << res << '\n';

  return 0;
}
