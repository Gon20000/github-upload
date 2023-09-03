#include <bits/stdc++.h>
using namespace std;

struct Rect {
    long double x1{}, x2{}, y1{}, y2{};
    
    friend std::istream& operator>>(std::istream& in, Rect& rect) {
        in >> rect.x1 >> rect.y1 >> rect.x2 >> rect.y2;
        return in;
    }

    long double getArea() const {
        return (x2 - x1) * (y2 - y1);
    }

    long double getIntersection(Rect& rect) {
        if(y1 > rect.y2 || rect.y1 > y2 || x1 > rect.x2 || rect.x1 > x2)
            return 0;
        
        return (min(x2, rect.x2) - max(x1, rect.x1)) * (min(y2, rect.y2) - max(y1, rect.y1));
    }
};

int main() {
    ios::sync_with_stdio(false);

    Rect white{}, black1{}, black2{};
    cin >> white >> black1 >> black2;

    long double inter1{white.getIntersection(black1)};
    long double inter2{white.getIntersection(black2)};
    long double res { white.getArea()};
    
    if (inter1 > 0 && inter2 > 0)
        res -= black1.getIntersection(black2);
    else
        res -= (inter1 + inter2);

    cout << (res <= 0 ? "NO" : "YES");
}