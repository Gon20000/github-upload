#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using arr_t = set<int>[101][101];

int n{}, m{};
int grid[101][101];

void recurse(arr_t& arr)
{
  for(int i{}; i < n; ++i) {
    for(int j{}; j < m; ++j) {
      if(j > 0)
        for(const int& prev : arr[i][j - 1])
          arr[i][j].insert(gcd(grid[i][j], prev));
      if(i > 0) 
        for(const int& prev : arr[i - 1][j])
          arr[i][j].insert(gcd(grid[i][j], prev));
    }
  }
}

void solve()
{
  arr_t arr;
  cin >> n >> m;
  for (int i{}; i < n; ++i)
  {
    for (int j{}; j < m; ++j)
    {
      cin >> grid[i][j];
    }
  }

  arr[0][0].insert(grid[0][0]);
  recurse(arr);
  cout << *arr[n - 1][m - 1].rbegin() << '\n';
}

int main()
{
  int t{};
  cin >> t;

  while (t--)
    solve();
}
