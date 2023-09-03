#include <bits/stdc++.h>
using namespace std;
using Point = pair<int, int>;

struct Rect {
    int x1{}, x2{}, y1{}, y2{};
    
    friend std::istream& operator>>(std::istream& in, Rect& rect) {
        in >> rect.x1 >> rect.y1 >> rect.x2 >> rect.y2;
        return in;
    }

    int getArea() const {
        return (x2 - x1) * (y2 - y1);
    }

};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    Rect bl1{}, bl2{};
    cin >> bl1 >> bl2;

    Point dl { max(bl1.x1, bl2.x1), max(bl1.y1, bl2.y1) };
    Point tr { min(bl1.x2, bl2.x2), min(bl1.y2, bl2.y2)};

    if ((dl.second == bl1.y1 && tr.second == bl1.y2 && (bl1.x1 >= bl2.x1 || bl1.x2 <= bl2.x2)) || (dl.first == bl1.x1 && tr.first == bl1.x2 && (bl1.y1 >= bl2.y1 || bl1.y2 <= bl2.y2))) {
        cout << bl1.getArea() - max(tr.first - dl.first, 0) * max(tr.second - dl.second, 0);
    }
    else {
        cout << bl1.getArea();
    }

    return 0;

}