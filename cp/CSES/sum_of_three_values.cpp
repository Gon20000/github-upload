#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n{}, x{};
  cin >> n >> x;

  vector<ll> arr(n), original(n);
  for(size_t i{}; i < n; ++i) {
    cin >> arr[i];
    original[i] = arr[i];
  }

  sort(arr.begin(), arr.end());
  vector<int> res(3);

  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      ll diff{x - arr[i] - arr[j]};
      if(diff <= 0)
        continue;

      auto it{lower_bound(arr.begin() + j + 1, arr.end(), diff)};
      if(it == arr.end() || *it != diff)
        continue;

      int k{1};
      for(auto ele : original) {
        if(ele == arr[i] && !res[0])
          res[0] = k;
        else if(ele == arr[j] && !res[1])
          res[1] = k;
        else if(ele == diff && !res[2])
          res[2] = k;
        ++k;
      }
      break;
    }
  }

  if(!res[0])
    cout << "IMPOSSIBLE\n";
  else {
    sort(res.begin(), res.end());
    cout << res[0] << ' ' << res[1] << ' ' << res[2] << '\n';
  }
  return 0;
}
