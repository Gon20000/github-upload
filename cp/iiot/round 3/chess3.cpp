#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, char> grid{};
pair<int, int> queen{};


bool checkKnight(int x, int y) {
    vector<pair<int, int>> a = {{x - 2, y + 1}, {x - 2, y - 1},
      {x + 2, y + 1}   ,{x + 2, y - 1},
      {x - 1, y + 2}   ,{x + 1, y + 2} ,
      {x - 1, y - 2} ,  {x + 1, y - 2}};

    for(auto e : a) {
        if(e == queen)
            return true;
    }

    return false;
}

bool checkRow(int x, int y) {
    if(queen.first != x)
        return false;

    int prev_y{y};
    
    --y;
    while(y > 0) {
        if(grid.count({x, y}) > 0)
            break;
        else if(queen.second == y)
            return true;
        --y;        
    }

    y = prev_y + 1;
    while(y <= 8) {
        if(grid.count({x, y}) > 0)
            break;
        else if(queen.second == y)
            return true;
        
        ++y;
    }

    return false;
}

bool checkCol(int x, int y) {
    if(queen.second != y)
        return false;

    int prev_x{x};
    
    --x;
    while(x > 0) {
        if(grid.count({x, y}) > 0)
            break;
        else if(queen.first == x)
            return true;
        --x;        
    }

    x = prev_x + 1;
    while(x <= 8) {
        if(grid.count({x, y}) > 0)
            break;
        else if(queen.first == x)
            return true;
        
        ++x;
    }

    return false;
}

bool checkVertical(int x, int y) {
    if(x < 1 || y < 1 || x > 8 || y > 8) 
        return false;

    
    return checkRow(x, y) || checkCol(x, y);
}

bool checkLeftDiag(int x, int y) {
    int prev_x{x};
    int prev_y{y};
    
    --x;
    --y;

    while(x > 0 && y > 0) {
        if(grid.count({x, y}) > 0)
            break;
        else if(queen.first == x && queen.second == y)
            return true;
        --x;
        --y;
    }

    x = prev_x + 1;
    y = prev_y + 1;

    while(x <= 8 && y <= 8) {
        if(grid.count({x, y}) > 0)
            break;
        else if(queen.first == x && queen.second == y)
            return true;
        ++x;
        ++y;
    }

    return false;
}

bool checkRightDiag(int x, int y) {
    int prev_x{x};
    int prev_y{y};
    
    --x;
    ++y;

    while(x > 0 && y <= 8) {
        if(grid.count({x, y}) > 0)
            break;
        else if(queen.first == x && queen.second == y)
            return true;
        --x;
        ++y;
    }

    x = prev_x + 1;
    y = prev_y - 1;

    while(x <= 8 && y > 0) {
        if(grid.count({x, y}) > 0)
            break;
        else if(queen.first == x && queen.second == y)
            return true;
        ++x;
        --y;
    }

    return false;
}

bool checkDiag(int x, int y) {
    return checkLeftDiag(x, y) || checkRightDiag(x, y);
}

bool checkPawn(int x, int y) {
    vector<pair<int, int>> a = {{x - 1, y + 1}, {x - 1, y - 1}};

    for(auto e : a) {
        if(e == queen)
            return true;
    }

    return false;
}

int main() {
    int n{};
    cin >> n;

    while(n--) {
        grid.clear();
        for(int i{1}; i <= 8; ++i) {
            for(int j{1}; j <= 8; ++j) {
                char x{};
                cin >> x;

                while(x == ' ')
                    cin >> x;

                if(x == 'q') {
                    queen = {i, j};
                }
                else if(x != '.') {
                    grid[make_pair(i, j)] = x;
                }
            }
        }

        bool res{false};

        for(auto e : grid) {
            if(res)
                break;

            int x{e.first.first}, y{e.first.second};
            if(e.second == 'P')
                res = checkPawn(x, y);
            else if(e.second == 'N')
                res = checkKnight(x, y);
            else if(e.second == 'B') 
                res = checkDiag(x, y);
            else if(e.second == 'R') 
                res = checkVertical(x, y);
            else if(e.second == 'Q')
                res = checkDiag(x, y) || checkVertical(x, y);
        }

        cout << (res ? "YES" : "NO") << '\n';
    }

    return 0;
}