#include <bits/stdc++.h>
using namespace std;

constexpr int board_size = 8;
using board_t = array<int, board_size>;
using input_t = array<array<bool, board_size>, board_size>;

int res{};

void solve(board_t comb, int row, const input_t& invalid) {
    if(row > board_size) {
        ++res;
        return;
    }

    for(int j{1}; j <= board_size; ++j) {
            if (invalid[row - 1][j - 1])
                continue;

            bool check{ true };

            for(int k{}; k < board_size; ++k) {
                if(comb[k] == 0)
                    continue;
                else if(abs(k - row + 1) == abs(comb[k] - j) 
                    || comb[k] == j) {
                    check = false;
                    break;
                }
            }

            if(check) {
                comb[row - 1] = j;
                solve(comb, row + 1, invalid);
            }
    }
}

int main() {
    ios::sync_with_stdio(false);
    
    res = 0;
    input_t invalid{};

    for(int i{}; i < board_size; ++i) {
        for(int j{}; j < board_size; ++j) {
            char piece{};
            cin >> piece;

            if(piece == '*') {
                invalid[i][j] = true;
            }
        }
    }

    solve(board_t{}, 1, invalid);

    cout << res << '\n';

    return 0;
}