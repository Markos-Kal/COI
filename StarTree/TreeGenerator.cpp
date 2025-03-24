#include <bits/stdc++.h>
using namespace std;

// Function to generate a random tree with N nodes
void generateRandomTree(int N, string filename) {

    ofstream fout(filename);
    srand(time(0)); // Seed for randomness
    if (N < 1) {
        cout << "Invalid input: N must be at least 1.\n";
        return;
    }

    vector<int> nodes(N);
    for (int i = 0; i < N; i++) nodes[i] = i + 1;

    // Shuffle nodes to randomize the starting node
    random_shuffle(nodes.begin(), nodes.end());

    vector<pair<int, int>> edges;

    // Connect each new node to a random existing node
    for (int i = 1; i < N; i++) {
        int parentIndex = rand() % i; // Choose a random existing node
        int u = nodes[parentIndex], v = nodes[i];
        if (u > v) swap(u, v); // Ensure smaller node comes first
        edges.push_back({u, v});
    }

    // Sort edges to print them in an ordered manner
    sort(edges.begin(), edges.end());

    // Print the tree edges
    fout << edges.size() + 1 << endl;
    for (auto &[u, v] : edges) {
        fout << u << " " << v << endl;
    }
}

void generate_linear_tree(int n, string filename)
{
    ofstream fout(filename);
    vector<pair<int, int>> tree;
    fout << n << endl;
    for (int i = 1; i < n; ++i) {
        fout << i << " " << i + 1 << endl;
    }
}

void generate_star_tree(int n, string filename)
{
    ofstream fout(filename);
    int center = rand() % n + 1; // Randomly choose center between 1 and n
    fout << n << endl;
    for (int i = 1; i <= n; ++i) {
        if (i < center) {
            fout << i << " " << center << endl; // Print edge directly
        }
        else if (i > center)
            fout << center << " " << i << endl;
    }
}
