#include <bits/stdc++.h>
using namespace std;

using cond_t = vector<array<int, 4>>;

array<int, 100> cows;

bool check() {
    return all_of(cows.begin(), cows.end(), [](int num) {
        return num <= 0;
    });
}

// m is amount of money
int solve(size_t ind, int m, const cond_t& conds) {
    if (check())
        return m;
    else if (ind == conds.size())
        return INT_MAX;

    for(int i{conds[ind][0]}; i <= conds[ind][1]; ++i) {
        cows[i] -= conds[ind][2];
    }
    int first { solve(ind + 1, m + conds[ind][3], conds) };
    for(int i{conds[ind][0]}; i <= conds[ind][1]; ++i) {
        cows[i] += conds[ind][2];
    }
    int second { solve(ind + 1, m, conds) };

    return min(first, second);

}

int main() {
    ios::sync_with_stdio(false);
    fill(cows.begin(), cows.end(), 0);

    int N{}, M{};
    cin >> N >> M;

    cond_t conditioners{};

    for(size_t i{}; i < N; ++i) {
        int start{}, end{}, amt{};
        cin >> start >> end >> amt;

        for(; start <= end; ++start) {
            cows[start] += amt;
        }
    }

    for(size_t i{}; i < M; ++i) {
        conditioners.push_back({});
        for(size_t j{}; j < 4; ++j) {
            cin >> conditioners[i][j];
        }
    }

    cout << solve(0, 0, conditioners) << '\n';
}
