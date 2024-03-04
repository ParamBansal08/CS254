#include<bits/stdc++.h>
using namespace std;

//main idea is to use kahn's algorithm
//if the graph is not directed acyclic then kahn's algorithm should not work
//thus, the elements in the final queue will have less elements than the number of vertices as 
//if there is a  loop there is  extra indegree in some vertex. this its indegree does not become 0 on removal of adjacent vertices
bool loopDetection(vector<int> adj[], int V) {
    queue<int>q;
    vector<int>visited(V, 0);
    //making a indegree array which has indegree of each vertex
    vector<int>indegree(V, 0);
    for (int i = 0;i < V;i++) {
        for (auto x : adj[i]) {
            indegree[x]++;
        }
    }
    for (int i = 0;i < V;i++)
        if (!indegree[i])q.push(i);//pushing vertices with 0 indegree into the queue
    int count = 0;
    while (!q.empty()) {
        int u = q.front();
        count++;//count stores the number of vertices which were pushed to queue atleast once
        q.pop();
        for (auto x : adj[u]) {
            indegree[x]--;//reducing indegree of vertices adjacent to u and pushing vertices whose indegree has become 0 to queue

            if (!indegree[x])q.push(x);
        }
    }
    return count != V;//if count is not equal to number of vertices then the graph contains loop
}
int main() {
    freopen("input_4.txt", "r", stdin);
    freopen("output_4.txt", "w", stdout);
    int t;cin >> t;
    while (t--) {
        int N, E;cin >> N >> E;
        vector<int>adj[N];
        while (E--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        cout << ((loopDetection(adj, N)) ? "yes,loop detected" : "no loop") << endl;
    }
    return 0;
}