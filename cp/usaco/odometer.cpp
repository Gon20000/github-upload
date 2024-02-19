#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string curr{};

/*18 digits -> n
number of occurences of a digit and should be >= 20 to avoid negative indices -> k
under decides if you're below the number already
started decides if you've actually started the number (not leading zeroes only)*/
ll dp[19][40][2][2];

void reset() {
    memset(dp, -1, sizeof(dp));
}

int digit(int idx) {
    return curr[idx] - '0';
}

ll solve(int pos, int k, bool under, bool started, int targ, int targ2 = -1) {
    if(pos == curr.size()) {
        // all leading zeroes
        if(!started)
            return 0;

        if(targ2 == -1) 
            return k >= 20; // at least half of its digits are the same (1020, 1030,..)
        
        // used for pruning duplicates when half of its digits are targ
        // and the other half is targ2
        return k == 20; 
        
    }

    if(dp[pos][k][under][started] != -1)
        return dp[pos][k][under][started];

    int lim{under ? 9 : digit(pos)};
    ll res{};

    for(int i{}; i <= lim; ++i) {
        bool is_started{started || (i != 0)};

        // we're checking for duplicates of a number with exacly half of its
        // digits as targ and the other as targ2 so we use only these digits
        // also (targ2 != -1)
        if(is_started && targ2 != -1 && i != targ && i != targ2)
            continue;

        int new_k{k};
        if(is_started) {
            if(i == targ) 
                new_k = k + 1;
            else
                new_k = k - 1;
        }

        res += solve(pos + 1, new_k, under || (i < digit(pos)), is_started, targ, targ2);
    }
    
    return dp[pos][k][under][started] = res;
}

ll solve_upto() {
    ll res{};
    for(int i{}; i <= 9; ++i) {
        reset();
        res += solve(0, 20, false, false, i, -1);
    }


    /* keep in mind that there are duplicates when half of the number digits
    are i and the other half is j, for example the number 1122 gets counted  
    once for targ == 1 and once for targ == 2*/

	for (int i{}; i <= 9; i++) {
		for (int j{i + 1}; j <= 9; j++) {
			reset();
			res -= solve(0, 20, false, false, i, j);
		}
	}
	return res;
}

int main() {
    freopen("odometer.in", "r", stdin);
    freopen("odometer.out", "w", stdout);
    ll x{};
    cin >> x;
    --x;

    curr = to_string(x);
    ll res1{solve_upto()};

    cin >> curr;
    ll res2{solve_upto()};

    cout << res2 - res1 << '\n';


    return 0;
}
