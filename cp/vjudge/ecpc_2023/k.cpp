#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string match(string& str1, string& str2) {
  for(int i{}; i < str1.size(); ++i) {
    if(str1[i] == '.')
      str1[i] = str2[i];
    else if(str1[i] != str2[i])
        return "Impossible";
  }

  return str2;
}

void solve() {
  string str{};
  cin >> str;

  vector<string> arr{"omar", "ezzat", "hossam", "hussien"};
  if(str.size() < 4 || str.size() > 7)
    cout << "Impossible\n";
  else {
    cout << match(str, arr[str.size() - 4]) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  cin >> t;

  while(t--)
    solve();

  return 0;
}
