#include <bits/stdc++.h>
using namespace std;

using edge_t = pair<int, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n{}, m{};
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<edge_t> least(n + 1, {INT_MAX, 0});
    least[1] = {1, -1};

    for (int i{1}; i <= m; ++i)
    {
        edge_t x{};
        cin >> x.first >> x.second;

        graph[x.first].push_back(x.second);
        graph[x.second].push_back(x.first);
    }

    queue<int> q{};
    q.push(1);

    while (!q.empty())
    {
        int curr{q.front()};
        q.pop();

        for (int child : graph[curr])
        {
            if (least[child].first > least[curr].first + 1)
            {
                least[child] = {least[curr].first + 1, curr};
                q.push(child);
            }
        }
    }
    /*
        WRONG LOGIC, ASSUMING THAT 42 IS SHORTER THAN 41 IN THE ROUTE,
        41 NEVER GETS UPDATED TILL WE PASS BY 42 THEN ITS CHILDREN DON'T GET
        AFFECTED.

        for(int i{1}; i < graph.size(); ++i) {
            for(int x : graph[i]) {
                if(least[x].first > least[i].first + 1) {
                    least[x] = {least[i].first + 1, i};
                }
            }
        } */

    int x{least[n].second};
    vector<int> res{n};

    while (x > 0)
    {
        res.push_back(x);
        x = least[x].second;
    }

    if (x != -1)
        cout << "IMPOSSIBLE" << '\n';
    else {
        cout << least[n].first << '\n';

        reverse(res.begin(), res.end());
        for(int r : res)
            cout << r << ' ';
        cout << '\n';
    }
    return 0;
}
