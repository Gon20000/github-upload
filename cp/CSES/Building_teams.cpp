#include <bits/stdc++.h>
using namespace std;

constexpr int max_size{100001};

vector<int> teams(max_size);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n{}, m{};
    cin >> n >> m;
    
    vector<vector<int>> city(n+1);
    for (int i{}; i <= n; ++i)
        teams[i] = 0;

    for(;m--;) {
        int a{}, b{};
        cin >> a >> b;
        city[a].push_back(b);
        city[b].push_back(a);
    }

    for(int i{1}; i <= n; ++i) {
        int neighbourColor{};

        for (int neighbour : city[i]) {
            if (neighbour > i && teams[neighbour] > 0) {
                if (neighbourColor == 0) {
                    neighbourColor = teams[neighbour];
                }
                else if (neighbourColor != teams[neighbour]) {
                    cout << "IMPOSSIBLE\n";
                    return 0;
                }
            }
        }

        if (neighbourColor == 0) {
            teams[i] = max(teams[i], 1);
            continue;
        }
        else {
            teams[i] = neighbourColor == 1 ? 2 : 1;
        }

        for (int neighbour : city[i]) {
            if (teams[neighbour] != neighbourColor) {
                teams[neighbour] = neighbourColor;
                for (int other : city[neighbour]) {
                    teams[other] = neighbourColor == 1 ? 2 : 1;
                }

            }
        }

    }

    for(int i{1}; i < n; ++i)
        cout << teams[i] << ' ';
    cout << teams[n] << '\n'; 

    
    /*10 20
1: [7,9]
2: [5, 6, 8, 10]
3: [4, 5, 6, 10]
4: [3, 7, 9]
5: [2, 3, 7, 9]
6: [2, 3, 7, 9]
7: [1, 4, 5, 6, 8, 10]
8: [2, 7, 9]
9: [1, 4, 5, 6, 8, 10]
10: [2, 3, 7, 9]

1 2 2 1 1 1
1 2 2 1 1 1 2 1 2 1 

1: [1, 2. 3]
2: [4, 5, 7, 8, 9]
 
*/

    return 0;
}