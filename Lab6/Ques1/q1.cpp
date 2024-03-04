#include<bits/stdc++.h>
using namespace std;

//in this question, i am using kahn's approach to find topological sorting
//it uses a queue 
void topological_sort(vector<int> adj[], int V) {
    queue<int>q;
    //making a indegree array which has indegree of each vertex
    vector<int>indegree(V, 0);
    for (int i = 0;i < V;i++) {
        for (auto x : adj[i]) {
            indegree[x]++;
        }
    }

    //pushing vertices with 0 indegree into queue
    for (int i = 0;i < V;i++)
        if (!indegree[i])q.push(i);

    while (!q.empty()) {
        int u = q.front();//popping and printing from q
        cout << u << ' ';
        q.pop();
        for (auto x : adj[u]) {
            indegree[x]--;//reducing indegree of all vertices connected to u and pushing vertices whose indegree has now become 0
            if (!indegree[x])q.push(x);
        }
    }
    cout << endl;
}

int main() {
    freopen("input_1.txt", "r", stdin);
    freopen("output_1.txt", "w", stdout);
    int t;cin >> t;
    while (t--) {
        int V;cin >> V;
        int E;cin >> E;
        vector<int>adj[V];
        for (int i = 0;i < E;i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        topological_sort(adj, V);
    }
    return 0;
}