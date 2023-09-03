#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    
    int a_x1{}, a_y1{}, a_x2{}, a_y2{}, b_x1{}, b_y1{}, b_x2{}, b_y2{};
    cin >> a_x1 >> a_y1 >> a_x2 >> a_y2 >> b_x1 >> b_y1 >> b_x2 >> b_y2;   
    
    cout << pow(max(max(a_x2, b_x2) - min(a_x1, b_x1), max(a_y2, b_y2) - min(a_y1, b_y1)), 2);
}