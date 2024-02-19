#include <bits/stdc++.h>
using namespace std;

bool check(const string& a, const string& b, int x) {
    int carry{0};
    for(int i{x - 1}; i >= 0; --i) {
        if(a[i] == b[i] && a[i] == '1')  {
            carry = 1;
        }
        else {
            if(carry == 1 && (a[i] == '1' || b[i] == '1'))
                carry = 1;
            else {
                carry = (a[i] == '1' && b[i] == '1');
            }
        }
    }

    return carry != 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x{};
    cin >> x;
    string a{}, b{};
    cin >> a >> b;

    int q{};
    cin >> q;

    while(q--) {
        int l{}, r{}, num{};
        cin >> l >> r >> num;

        cout << check(a.substr(l, num), b.substr(r, num), num);
        if(q != 0)
            cout << ' ';
    }
    cout << '\n';

    return 0;
}