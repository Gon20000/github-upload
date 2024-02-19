#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int max_n{1002};
vector<ll> print{};

void assign(ll x, ll y, ll num, map<ll, ll[max_n + 1]>& dp) {
    if(dp[x][y] == 0)
        ++dp[x][max_n];
    
    dp[x][y] = num;
}

void printResult() {
    for(ll i{}; i < print.size() - 1; ++i)
        cout << print[i] << ' ';

    cout << print[print.size() - 1] << '\n'; 
}

void getMax(ll start, ll low, ll high, map<ll, ll[max_n + 1]>& dp) {
        ll res{-1};
        if(low == 0) {
            res = start;
            ++low;
        }

        for(; low <= high; ++low) {
            if(dp[start][low] == 0)
                break;
            res = max(res, dp[start][low]);
        }

        print.push_back(res);
}

int main()
{
    int n{};
    cin >> n;

    map<ll, multiset<ll>> inp{};
    map<ll, ll[max_n + 1]> dp{};
    map<ll, ll> repeat{};

    while (n--)
    {
        ll l{}, r{};
        cin >> l >> r;
        if(l == r)
            ++repeat[l];
        else {
            inp[l].insert(r);
            dp[l][1] = max(dp[l][1], r);
        }

        dp[l][0] = l;
        dp[l][max_n] = dp[l][1] ? 2ll : 1ll;

    }

    // do repetitions to avoid empty elements
    // example : 1->1->10 where dp.count(10) == 0
    for(auto it{dp.rbegin()}; it != dp.rend(); ++it) {
        ll i{it->second[max_n]}, cnt{};
        if(repeat.find(it->first) != repeat.end())
            cnt = repeat[it->first];

        for(int j{}; j < cnt; ++j) {
            assign(it->first, i, dp[it->first][i - 1], dp);
            i++;
        }
    }

    for (auto it{inp.rbegin()}; it != inp.rend(); ++it)
    {
        ll parent{it->first};

        for (auto r{it->second.rbegin()}; r != it->second.rend(); ++r)
        {
            ll element{*r};

            // parent -> element as in 1 -> 10
            if (dp.count(element) == 0)
                continue;

            ll element_size{dp[element][max_n]};

            for (ll i{1}; i < element_size; ++i)
            {
                if (dp[element][i] == 0)
                    break;
                
                assign(parent, i + 1, max(dp[parent][i + 1], dp[element][i]), dp);
                
                // account for repetitions
                ll idx{i + 2};
                for(int j{}; j < repeat[parent]; ++j) {
                    assign(parent, idx, max(dp[element][i], dp[parent][idx]), dp);
                    ++idx;
                } 
            }
        }
    }

    ll q{};
    cin >> q;
    print.clear();

    while(q--) {
        ll start{}, low{}, high{};
        cin >> start >> low >> high;

        getMax(start, low, high, dp);
    }

    printResult();

    return 0;
}

/*
testcases:

5
0 2
0 4
2 5
4 10
5 6

3
0 0 3
0 3 3
2 1 5


5
4 4
2 4
4 4
4 7
2 4

4
2 4 4
2 5 5
1 0 2
1 1 5


6
1 1
1 4
1 10
4 9
9 11
10 10*/