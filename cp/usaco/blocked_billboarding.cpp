#include <bits/stdc++.h>
using namespace std;

struct Rect {
    int x1{}, x2{}, y1{}, y2{};
    
    friend std::istream& operator>>(std::istream& in, Rect& rect) {
        in >> rect.x1 >> rect.y1 >> rect.x2 >> rect.y2;
        return in;
    }

    int getArea() const {
        return (x2 - x1) * (y2 - y1);
    }

    int getIntersection(Rect& rect) {
        if(y1 > rect.y2 || rect.y1 > y2 || x1 > rect.x2 || rect.x1 > x2)
            return 0;
        
        return (min(x2, rect.x2) - max(x1, rect.x1)) * (min(y2, rect.y2) - max(y1, rect.y1));
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    Rect bl1{}, bl2{}, truck{};
    cin >> bl1 >> bl2 >> truck;
    
    cout << bl1.getArea() - bl1.getIntersection(truck) + bl2.getArea() - bl2.getIntersection(truck);
    return 0;

}