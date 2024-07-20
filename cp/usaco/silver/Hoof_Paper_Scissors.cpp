#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct Game {
  ll hoofs{}, papers{}, scissors{};

  Game() {}

  Game(ll x, ll y, ll z) : hoofs{x}, papers{y}, scissors{z} {
  }

  Game(const Game& game) {
    hoofs = game.hoofs;
    papers = game.hoofs;
    scissors = game.hoofs;
  }

  Game operator-(const Game& game) {
    return Game(hoofs - game.hoofs, papers - game.papers, scissors - game.scissors);
  }

  ll highest() {
    return max(hoofs, max(papers, scissors));
  }
};

void solve() {
  int n{};
  cin >> n;

  vector<Game> arr(n);
  for(int i{}; i < n; ++i) {
    if(i > 0)
      arr[i] = arr[i - 1];

    char x{};
    cin >> x;
    if(x == 'P') {
      ++arr[i].papers;
    }
    else if(x == 'H')  {
      ++arr[i].hoofs;
    }
    else {
      ++arr[i].scissors;
    }
  }

  ll res{arr.back().highest()};
  for(size_t i{}; i < n - 1; ++i) {
    Game curr(arr.back() - arr[i]);
    res = max(res, curr.highest() + arr[i].highest());
  }

  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);

  int t{1};
  /*cin >> t;*/

  while(t--)
    solve();

  return 0;
}

