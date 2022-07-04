#include <iostream>

constexpr int size{ 3 };

enum class TicTacToe {
    empty,
    x,
    o,
};

void printGrid(TicTacToe arr[size][size]) {
    for(int i{ 0 }; i < size; ++i) {
        for(int j{ 0 }; j < size; ++j) {
            std::cout << "| ";
            if(arr[i][j] == TicTacToe::x) {
                std::cout << 'X';
            }
            else if (arr[i][j] == TicTacToe::o) {
                std::cout << 'O';
            }
            else {
                std::cout << '.';
            }
            std::cout << " |";
        }
        std::cout << '\n';
    }
}

void getInput(TicTacToe arr[size][size], bool me = true) {
    int row{ 0 };
    int col{ 0 };
    std::cin >> row >> col;
    
    while(arr[row - 1][col - 1] != TicTacToe::empty) {
        std::cout << "That square is occupied, Enter a valid square!\n";
        std::cin >> row >> col;
    }
    arr[row - 1][col - 1] = me ? TicTacToe::x : TicTacToe::o;
}

bool isEqual(TicTacToe x, TicTacToe y) {
    return x != TicTacToe::empty && x == y;
}

int checkDiag(TicTacToe arr[size][size]) {
    bool lDiag{ true };
    bool rDiag{ true };
    for(int i{ 1 }; i < size && (lDiag || rDiag); ++i) {
        lDiag &= isEqual(arr[i - 1][i - 1], arr[i][i]);
        rDiag &= isEqual(arr[i - 1][size - i], arr[i][size - i - 1]);
    }

    if(lDiag)
        return arr[0][0] == TicTacToe::x ? 1 : -1;
    else if(rDiag)
        return arr[size - 1][0] == TicTacToe::x ? 1 : -1;
    else
        return 0;
}

int checkColRow(TicTacToe arr[size][size]) {
    for(int i{ 0 }; i < size; ++i) {
        bool vertical{ true };
        bool horizontal{ true };
        for(int j{ 1 }; j < size && (vertical || horizontal); ++j) {
            vertical &= isEqual(arr[j - 1][i], arr[j][i]);
            horizontal &= isEqual(arr[i][j - 1], arr[i][j]);
        }

        if(horizontal || vertical)
            return arr[i][i] == TicTacToe::x ? 1 : -1;
    }

    return 0;
}

int check(TicTacToe arr[size][size]) {
    return checkDiag(arr) || checkColRow(arr);
}

int main() {
    TicTacToe arr[size][size]{};
    bool prog{ true };
    for(int i{ 0 }; i < size * size && prog; ++i) {
        getInput(arr, i % 2 == 0);
        printGrid(arr);
        switch (check(arr)) {
            case 1:
                std::cout << "X wins!\n";
                prog = false;
                break;
            case -1:
                std::cout << "Y wins!\n";
                prog = false;
                break;
        }

        if(i == size * size - 1)
            std::cout << "It's a tie.\n";
    }

    return 0;
}