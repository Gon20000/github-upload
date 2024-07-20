#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

// Union-Find Data Structure for handling disjoint sets
class UnionFind {
private:
    vector<int> parent, rank;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
            return true;
        }
        return false;
    }
};

// Function to generate a random integer between l and r (inclusive)
int randomInt(int l, int r) {
    return l + rand() % (r - l + 1);
}

// Function to generate the test case
void generateTestCase(int n, int m, int q) {

    // Output n, m, q
    cout << n << " " << m << " " << q << endl;


    UnionFind uf(n);

    // Generate m unique random edges
    set<pair<int, int>> edges;
    while (edges.size() < m) {
        int a = randomInt(1, n);
        int b = randomInt(1, n);
        if (a != b && uf.unionSets(a - 1, b - 1)) {
            edges.insert(minmax(a, b));
        }
    }
    for (const auto& edge : edges) {
        cout << edge.first << " " << edge.second << endl;
    }

    // Generate q random queries
    for (int i = 0; i < q; ++i) {
        int type = randomInt(1, 2);
        int x = randomInt(1, n);
        if (type == 1) {
            // Query of type 1
            cout << type << " " << x << endl;
        } else {
            // Query of type 2
            int y = randomInt(1, n);
            cout << type << " " << x << " " << y << endl;
        }
    }

}

int main(int argc, char** argv) {
  srand(atoi(argv[1]));

    // Number of cities, roads, and queries for the test case
    int n = 150000; // Max value for n
    int m = 21372; // Max value for m (to keep the graph sparse)
    int q = 9126; // Max value for q


    // Generate the test case
    generateTestCase(n, m, q);

    return 0;
}
