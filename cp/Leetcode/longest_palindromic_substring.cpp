#include <bits/stdc++.h>
using namespace std;

vector<int> manacher_odd(const string& str) {
  vector<int> d(str.size());

  int l{0}, r{0};
  for(int i{0}; i < str.size(); ++i){
    d[i] = max(0, min(d[l + (r - i)], r - i));

    while(i - d[i] >= 0 && i + d[i] < str.size() && str[i - d[i]] == str[i + d[i]]) {
      ++d[i];
    }

    if(i + d[i] > r) {
      r = i + d[i];
      l = i - d[i];
    }
  }

  return d;
}

vector<int> manacher(const string& str) {
  string inp{"#"};
  for(char chr : str) {
    inp += (chr);
    inp += "#";
  }

  vector<int> vec{manacher_odd(inp)};

  return vector<int>(vec.begin() + 1, vec.end() - 1);
}
void print(vector<int>& vec) {
  for(int i{}; i < vec.size() - 1; ++i)
    cout << vec[i] << ' ';
  cout << vec.back() << '\n';
}

int main () {
  int t{1};
  // cin >> t;

  while(t--) {
    string str{};
    cin >> str;

    vector<int> res{manacher(str)};
    pair<int, int> high{};

    for(int i{}; i < res.size(); ++i) {
      if(res[i] > high.second) {
        high = {i, res[i]};
      }
    }



    for(int i{high.first / 2 - high.second / 2}; i < high.first / 2; ++i) {
      cout << str[i];
    }

    if (high.first % 2 == 0) {
      cout << res[high.first / 2];
    }

    for(int i{high.first / 2 + high.second / 2}; i - (high.first / 2) <= high.second / 2; ++i) {
      cout << str[i];
    }
  }

  return 0;

}
