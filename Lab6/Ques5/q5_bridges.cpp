#include<bits/stdc++.h>
using namespace std;
int timer = 0; // global timer to share among all function calls in dfs

// The main idea is to use Tarjan's algorithm.
// It will store discovery_time and low value for each vertex.
// Low value stores the highest ancestor that the current node can reach using some other path from which it was originally addressed.
void DFS(vector<int> adj[], int i, int u, int visited[], int low[], int discovery_time[]) {
    visited[i] = 1; // Marking the current node as visited.
    discovery_time[i] = timer++; // Assigning the discovery time for the current node and incrementing timer.
    low[i] = discovery_time[i]; // Initializing low value of the current node with its discovery time.
    
    // Iterating through all adjacent nodes of the current node.
    for (auto x : adj[i]) {
        if (x == u) continue; // Skip if the adjacent node is the parent node in the DFS traversal.
        if (visited[x] == 0) { // If the adjacent node is not visited.
            // Recursively call DFS for the adjacent node.
            DFS(adj, x, i, visited, low, discovery_time);
            // Update the low value of the current node using the low value of its adjacent node.
            low[i] = min(low[i], low[x]);
            // If the low value of the adjacent node is greater than the discovery time of the current node,
            // it indicates a bridge. Print the edge.
            if (low[x] > discovery_time[i])
                cout << i << ' ' << x << endl;
        }
        if (visited[x]) { // If the adjacent node is already visited.
            // Update the low value of the current node using the low value of its adjacent node.
            low[i] = min(low[i], low[x]);
        }
    }
}

// Function to print bridges in the graph.
void print_bridges(vector<int> adj[], int V) {
    vector<pair<int, int>> bridge; // Vector to store bridges.
    int visited[V] = { 0 }, low[V], discovery_time[V]; // Arrays to store visited, low value, and discovery time.
    for (int i = 0; i < V; i++) {
        if (!visited[i]) // If the current node is not visited, perform DFS.
            DFS(adj, i, -1, visited, low, discovery_time);
    }
    cout << endl;
    timer = 0; // Reset timer for the next graph.
}

int main() {
    freopen("input_5_bridges.txt", "r", stdin); // Redirect input from file.
    freopen("output_5_bridges.txt", "w", stdout); // Redirect output to file.
    int t; cin >> t; // Number of test cases.
    while (t--) {
        int V, E;
        cin >> V >> E; // Number of vertices and edges.
        vector<int> adj[V]; // Adjacency list representation of the graph.
        // Input edges.
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v); // Adding edge (u, v).
            adj[v].push_back(u); // Adding edge (v, u) for undirected graph.
        }

        print_bridges(adj, V); // Call function to print bridges.

    }
    return 0;
}
