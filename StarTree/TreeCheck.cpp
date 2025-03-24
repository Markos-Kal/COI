#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    bool unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV)
            return false;  // Cycle detected

        if (rank[rootU] > rank[rootV])
            parent[rootV] = rootU;
        else if (rank[rootU] < rank[rootV])
            parent[rootU] = rootV;
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
        return true;
    }
};

bool isTree(int n, vector<pair<int, int>> &edges) {
    if (edges.size() != n - 1) return false; // Must have exactly n-1 edges

    DisjointSet ds(n);
    for (auto &edge : edges) {
        if (!ds.unionSet(edge.first, edge.second))
            return false; // Cycle detected
    }

    return true; // If no cycles and correct edges count, it's a tree
}

int main() {
    int n;
    cout << "Enter number of nodes and edges: ";
    cin >> n;

    vector<pair<int, int>> edges(n - 1);
    cout << "Enter edges (1-based index):" << endl;
    for (int i = 0; i < n - 1; i++)
        cin >> edges[i].first >> edges[i].second;

    if (isTree(n, edges))
        cout << "The graph is a tree.\n";
    else
        cout << "The graph is NOT a tree.\n";

    return 0;
}
