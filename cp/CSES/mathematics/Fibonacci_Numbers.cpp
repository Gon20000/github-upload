#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll mod{static_cast<ll>(1e9) + 7};
struct Matrix {
  vector<vector<ll>> mat{};
  size_t m_size{};

  Matrix(const Matrix& mat2) : mat{mat2.mat}, m_size{mat2.m_size} {};

  Matrix(size_t size) : m_size{size}, mat(size, vector<ll>(size)) {};

  Matrix operator*(const Matrix& mat2) {
    Matrix res(m_size);
    for(int i{}; i < m_size; ++i) {
      for(int j{}; j < m_size; ++j) {
        for(int k{}; k < m_size; ++k) {
          res.mat[i][j] += mat[i][k] * mat2.mat[k][j];
          res.mat[i][j] %= mod;
        }
      }
    }

    return res;
  }

  void operator*=(const Matrix& mat2) {
    Matrix res{this->operator*(mat2)};
    swap(mat, res.mat);
  }
};


void solve() {
  Matrix res(2);
  res.mat[0][0] = res.mat[1][1] = 1;

  Matrix curr{2};
  curr.mat[0][1] = curr.mat[1][0] = curr.mat[1][1] = 1;

  ll n{};
  cin >> n;
  
  if(n-- == 0) {
    cout << 0 << '\n';
    return;
  }

  while(n > 0) {
    if(n & 1) 
      res *= curr;

    curr *= curr;
    n >>= 1;
  }

  cout << res.mat[1][1] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  /*cin >> t;*/

  while(t--)
    solve();

  return 0;
}
