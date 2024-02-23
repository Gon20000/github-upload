#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using grid_t = vector<pair<ll, char>>;

grid_t prt{}, grid{{0, 'R'}, {0, 'G'}, {0, 'B'}};
ll n{}, m{};

/* bool check()
{
				for (auto x : grid)
								if (x.first > 0)
												return false;

				return true;
} */

int get(char x)
{
		for (int i{}; i < 3; ++i)
		{
				if (x == grid[i].second)
						return i;
		}

		return -1;
}

bool filter(int idx, int i, int j, const vector<vector<char>> &res)
{
		if (i < 0 || j < 0 || i >= n || j >= m)
				return false;
		return idx == get(res[i][j]);
}

void print()
{
		cout << n << ' ' << m << ' ';
		for (const auto &x : prt)
		{
				cout << x.first << ' ';
		}
		cout << '\n';
}

void solve()
{
		//prt = grid_t(grid);
		vector<vector<char>> res(n);
		for (int i{}; i < n; ++i)
				res[i].resize(m);

		sort(grid.begin(), grid.end(), greater<pair<ll, char>>());

		if (grid[0].first > ceil((n * m) / 2.0) + 1)
		{
				cout << "NO\n";
				//  print();
				return;
		}

		for (int i{}; i < n; ++i)
		{

				for (int j{}; j < m; ++j)
				{
						if (res[i][j])
								continue;

						int idx{};

						int check{};
						while (grid[idx].first <= 0 || filter(idx, i - 1, j, res) || filter(idx, i, j - 1, res) || filter(idx, i + 1, j, res) || filter(idx, i, j + 1, res))
						{
								idx = (idx + 1) % 3;
								if (check++ > 3)
								{
										cout << "NO\n";
										//print();
										return;
								}
						}

						for (int k{i}, l{j}; k < n && l < m && grid[idx].first > 0; ++k, ++l)
						{
								res[k][l] = grid[idx].second;
								--grid[idx].first;
						}

						sort(grid.begin(), grid.end(), greater<pair<ll, char>>());
				}
		}

		cout << "YES\n";

		// int k{};
		for (const auto &x : res)
		{
				for (int i{}; i < m; ++i)
				{
						cout << x[i];
						/*if (k > 0 && x[i] == res[k - 1][i] || (i < m - 1 && res[i] == res[i + 1]))
														{
																		print();
																		return;
														}
										}*/
				}
						cout << '\n';
		}
}

int main()
{
		// freopen("inp.in", "r", stdin);
		int t{1};
		//cin >> t;
		while (t--)
		{
				cin >> n >> m >> grid[0].first >> grid[1].first >> grid[2].first;
				// cout << t << '\n';
				solve();
		}

		return 0;
}