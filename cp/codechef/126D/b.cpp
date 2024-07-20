#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int n{};
    cin >> n;

    while(n--) {
        int x{}, y{};
        cin >> x >> y;
        if(x < 50) 
            cout << "Z\n";
        else if(y < 50)
            cout << "F\n";
        else 
            cout << "A\n";
    }

    return 0;
}

