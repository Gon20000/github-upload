#include <bits/stdc++.h>
using namespace std;

int main() {
  int n{}, l{}, r{};
  cin  >> n >> l >> r;

  vector<int> res(n);
  int i{1};
  for(;i < l; ++i) {
    res[i - 1] = i;
  }

  for(int k{r}; k >= l; ++i) {
    res[i - 1] = k;
    --k;
  }

  for(int j{r}; j < n; ++j)
    res[j] = j + 1;

  for(int j{0}; j < n - 1; ++j)
    cout << res[j] << ' ';
  cout << res[n - 1] << '\n';

  return 0;
}
