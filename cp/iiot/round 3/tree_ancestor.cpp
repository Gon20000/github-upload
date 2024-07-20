#include <bits/stdc++.h>
using namespace std;

const int max_n{static_cast<int>(1e6 + 1)};

constexpr int max_sparse_rows{21};
vector<vector<int>> generateSparse(vector<int> parents) {
  int n{parents.size() + 1};
  vector<vector<int>> sparse(max_sparse_rows, vector<int>(n + 2, -1));

  for(int i{}; i < n; ++i) 
    sparse[1][i + 2] = parents[i];

  for(int row{2}; row < max_sparse_rows; ++row) {
    bool changed{false};
    for(int j{2}; j <= n; ++j) {
      int pred{sparse[row - 1][j]};
      if(pred == -1)
        continue;

      sparse[row][j] = sparse[row - 1][pred];
      if(sparse[row][j] != -1)
        changed = true;
    }

    if(!changed)
      break;
  }

  return sparse;
}

int k_step(int num, int k, const vector<vector<int>>& sparse) {
  int cnt{1}, curr{-INT_MAX};
  while(k > 0) {
    if(curr == -1)
      return -1;

    if(k & 1 == 1) {
      if(curr == -INT_MAX) {
        curr = sparse[cnt][num];
      }
      else
      curr = sparse[cnt][curr];
    }

    ++cnt;
    k >>= 1;
  }

  return curr == -1 ? curr : curr - 1;
}

int main() {
  int n{}, q{};
  cin >> n >> q;

  vector<int> parents(n - 1, -1);
  for(int i{}; i < n - 1; ++i) {
    int x{}, y{};
    cin >> x >> y;
    ++x; ++y;

    if(x > y)
      swap(x, y);

    parents[y - 2] = x;
  }
  
  vector<vector<int>> sparse{generateSparse(parents)};
  parents.clear();


  for(int i{1}; i < n; ++i)
    cout << k_step(i, q, sparse) << ' ';

  cout << k_step(n, q, sparse) << '\n';

  return 0;
}
