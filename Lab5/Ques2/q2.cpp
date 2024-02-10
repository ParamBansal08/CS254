#include<bits/stdc++.h>
using namespace std;

int customisedBFS(vector<int>& arr, vector<int>& visited, int s, int n) {
    queue<int>q;
    q.push(s);
    visited[s] = 1;
    int count = 0;
    bool done = 0;
    int y = q.front();
    while (arr[y] != -1 && y < n) {
        y = arr[y];
    }
    q.pop();
    q.push(y);
    while (!q.empty()) {
        if (done)break;
        count++;
        int size = q.size();
        for (int j = 0;j < size;j++) {
            if (done)break;
            int curr = q.front();
            q.pop();

            for (int i = 1;i <= 6;i++) {

                if (curr + i <= n) {

                    if (!visited[curr + i]) {
                        if (arr[curr + i] == -1)q.push(curr + i);
                        else {
                            q.push(arr[curr + i]);
                            if (arr[curr+i] == n ) { done = 1; break; }
                            visited[arr[curr + i]] = 1;
                        }
                        if (curr+i == n ) { done = 1; break; }
                        visited[curr + i] = 1;
                    }
                }

            }
        }
    }
    return count;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input_2.txt", "r", stdin);
    freopen("output_2.txt", "w", stdout);
#endif
    int t;cin >> t;
    while (t--) {
        int n;cin >> n;
        vector<int>arr(n + 1);
        

        vector<int>visited(n + 1);
        visited[0] = 1;
        for (int i = 1;i <= n;i++)cin >> arr[i];
        cout << customisedBFS(arr, visited, 1, n) << endl;;
    }
    return 0;
}