#include <bits/stdc++.h>
using namespace std;

array<array<int, 3>, 100000> breeds = {{0,0,0}};

void printDifference(array<int, 3> x, array<int, 3> y) {
    cout << y[0] - x[0] << ' ' << y[1] - x[1] << ' ' << y[2] - x[2] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int n{}, q{};
    cin >> n >> q;

    for(int i{1}; i <= n; ++i) {
        breeds[i] = breeds[i - 1];
        
        int id{};
        cin >> id;

        ++breeds[i][id - 1];
    }

    for (; q--;) {
        int a{}, b{};
        cin >> a >> b;

        printDifference(breeds[a - 1], breeds[b]);
    }

    return 0;

}