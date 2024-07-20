#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ll n{};
  cin >> n;
  ll siz{(n * n) / 2};

  ll l{1}, r{(ll)1e12}, res{};

  while (l <= r)
  {
    res = LLONG_MAX;
    ll mid{l + (r - l) / 2};

    ll left{}, dups{(ll)(mid <= n)};
    for (int i{1}; i < min(mid, n + 1) && left <= siz; ++i)
    {
      ll cnt{min(n + 1, (ll)ceil(mid / double(i)))};

      left += cnt - 1;
      if (cnt <= n)
      {
        res = min(res, i * cnt);

        if(i * cnt == mid)
          ++dups;
      }
    }

    // cout << mid << ' ' << left << '\n';

    if (left == siz)
    {
      break;
    }
    else if (left < siz)
    {
      if (dups + left > siz)
      {
        res = mid;
        break;
      }
      l = mid + 1;
    }
    else
  {
      r = mid - 1;
    }
  }

  // if input is 1:
  cout << (res == LLONG_MAX ? 1 : res) << '\n';
  return 0;
}
