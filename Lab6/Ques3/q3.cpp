#include<bits/stdc++.h>
using namespace std;

//this dfs will do normal dfs traversal and make a stack which will contain vertices in decreasing order of their departure time
void DFS(vector<int>adj[], int i, int visited[], stack<int>& st) {
    if (visited[i])return;
    visited[i] = 1;
    for (auto x : adj[i]) {
        if (!visited[x])DFS(adj, x, visited, st);
    }
    st.push(i);
}

void printDFS(vector<int>adj[], int i,int visited[]) {
    if (visited[i])return;
    visited[i] = 1;
    cout << i << ' ';
    for (auto x : adj[i]) {
        if (!visited[x])printDFS(adj, x, visited);
    }
    
}
void stronglyConnectedComponent(vector<int>adj[], int V) {
    stack<int>st;
    int visited[V] = { 0 };
    for (int i = 0;i < V;i++) {
        if (!visited[i])DFS(adj, i, visited, st);//filling the stack
    }
    vector<int>adj2[V];//new adjacency list which contains edges in reverse order
    for (int i = 0;i < V;i++) {
        for (auto j : adj[i]) {
            adj2[j].push_back(i);
        }
    }
    for (int i = 0;i < V;i++)visited[i] = 0;
    while (!st.empty()) {//now doing normal dfs in order of elements popped from stack
        int u = st.top();
        st.pop();
        if (!visited[u]) {
            printDFS(adj2, u, visited);
            cout << endl;
        }
    }
}


int main() {
    freopen("input_3.txt","r",stdin);
    freopen("output_3.txt","w",stdout);
    int t;cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        while (E--) {
            int u, v;cin >> u >> v;
            adj[u].push_back(v);
        }
        stronglyConnectedComponent(adj, V);
        cout << endl;
    }
    return 0;
}