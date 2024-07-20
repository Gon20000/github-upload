#include <bits/stdc++.h>
using namespace std;

constexpr int factor{8};
constexpr int max_n{101};
bitset<8> dp[max_n];
int prev[max_n][8];

int main() {
  string str{};
  cin >> str;
  memset(prev, -1, sizeof prev);

  dp[0][(str[0] - '0') % factor] = 1;

  for(int i{1}; i < str.size(); ++i) {
    int curr{(str[i] - '0') % factor};
    dp[i][curr] = 1;

    for(int j{0}; j < factor; ++j) {
      if(dp[i - 1][j]) {
        dp[i][(j + curr) % factor] = true;
        prev[i][(j + curr) % factor] = j;

        // not including the current one I believe
        dp[i][j] = true;
        prev[i][j] = j;
      }
    }
  }
  return 0;
}
