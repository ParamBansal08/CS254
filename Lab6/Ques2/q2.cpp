#include<bits/stdc++.h>
using namespace std;
int DFS(vector<int>adj[], int i, vector<int> &dp,vector<int>&visited) {
    if(visited[i])
        return dp[i];//if visited then dp is already calculated
    visited[i] = 1;
    int mx = 0;
    for (auto x : adj[i])
        mx = max(mx, DFS(adj, x, dp, visited));//mx stores the maximum path from i
    
    return dp[i] = 1 + mx;

}
//main idea is that we will make a dp array in which dp[i] stores the longest path starting from vertex i

int longestPath(vector<int>adj[], int N, int M) {
    vector<int>visited(N, 0);
    vector<int>dp(N, -1);//dp array
    for (int i = 0;i < N;i++) {
        if (!visited[i]) {
            DFS(adj, i, dp, visited);//using dfs and storing values into dfs
        }
    }
    int ans = 0;
    for (auto x : dp)ans = max(ans, x);//outputing the longest path
    return ans;
}

int main() {
    freopen("input_2.txt","r",stdin);
    freopen("output_2.txt","w",stdout);
    int t;cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<int>adj[N];
        for (int i = 0;i < M;i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        cout << longestPath(adj, N, M)<<endl;
    }
    return 0;
}