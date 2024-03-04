#include<bits/stdc++.h>
using namespace std;
int timer = 0;

// This code detects articulation points in an undirected graph using depth-first search (DFS) traversal
// and Tarjan's algorithm. An articulation point is a vertex in a graph whose removal disconnects the graph,
// making it not connected or increasing its number of connected components.
// Tarjan's algorithm is used to efficiently find articulation points by maintaining information about discovery
// times and low #include<bits/stdc++.h>
using namespace std;

// Main idea: This code detects articulation points in an undirected graph using depth-first search (DFS) traversal
// and Tarjan's algorithm. An articulation point is a vertex in a graph whose removal disconnects the graph,
// making it not connected or increasing its number of connected components.
// Tarjan's algorithm is used to efficiently find articulation points by maintaining information about discovery
// times and low values for each vertex during DFS traversal. This information helps identify articulation points
// by checking if a vertex is the root of a DFS tree and has more than one child, or if any of its descendants
// can only reach ancestors of the vertex using a back edge.
values for each vertex during DFS traversal. This information helps identify articulation points
// by checking if a vertex is the root of a DFS tree and has more than one child, or if any of its descendants
// can only reach ancestors of the vertex using a back edge.

// Function to perform DFS traversal and find articulation points.
void dfs(int node, int parent, vector<int>& vis, int discovery_time[], int low[], vector<int>& mark, vector<int>adj[]) {
    vis[node] = 1; // Marking the current node as visited.
    discovery_time[node] = low[node] = timer++; // Assigning discovery time and low value for the current node.
    int child = 0; // Counter to count children of the current node in DFS tree.
    for (auto it : adj[node]) {
        if (it == parent) continue; // If the adjacent node is the parent node in DFS tree, skip.
        if (!vis[it]) { // If the adjacent node is not visited.
            dfs(it, node, vis, discovery_time, low, mark, adj); // Recursively call DFS for the adjacent node.
            low[node] = min(low[node], low[it]); // Update the low value of the current node.
            if (low[it] >= discovery_time[node] && parent != -1) mark[node] = 1; // Check if the subtree rooted at 'it' has a back edge to an ancestor of 'node'.
            child++; // Increment child count.
        }
        else { // If the adjacent node is already visited.
            low[node] = min(low[node], discovery_time[it]); // Update the low value of the current node.
        }
    }
    // Check if the current node is root and has more than one child. If so, it's an articulation point.
    if (child > 1 && parent == -1) mark[node] = 1;
}

// Function to print articulation points in the graph.
void print_articulation_points(int n, vector<int>adj[]) {
    vector<int> vis(n, 0); // Array to track visited nodes.
    int low[n], discovery_time[n]; // Arrays to store low value and discovery time for each node.
    vector<int> mark(n, 0); // Array to mark nodes as articulation points.
    // Perform DFS traversal for each unvisited node in the graph.
    for (int i = 0; i < n; i++) {
        if (!vis[i])
            dfs(i, -1, vis, discovery_time, low, mark, adj);
    }
    vector<int> ans; // Vector to store articulation points.
    bool no_articulation_point = 1; // Flag to check if there are no articulation points.
    for (int i = 0; i < n; i++) {
        if (mark[i]) { // If the node is marked as an articulation point.
            cout << i << ' '; // Print the node.
            no_articulation_point = 0; // Set the flag to indicate that there is at least one articulation point.
        }
    }
    if (no_articulation_point) cout << "no articulation point"; // If there are no articulation points, print appropriate message.
    cout << endl;
}

int main() {
    freopen("input_5_articulation_points.txt", "r", stdin); // Redirect input from file.
    freopen("output_5_articulation_points.txt", "w", stdout); // Redirect output to file.
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

        print_articulation_points(V, adj); // Call function to print articulation points.

    }
    return 0;
}
