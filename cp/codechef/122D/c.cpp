#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t{};
	cin >> t;
	
	while(t--) {
	    	pair<int, int> res{};

	    for(int i{}; i < 22; ++i) {
	        int a{}, b{};
	        cin >> a >> b;
	        if(res.first < a + 20 * b)
	            res = {a+20*b, i + 1};
	    }
	    cout << res.second << '\n';
	}
}
