#include<bits/stdc++.h>
using namespace std;

//this function will return true if the compliment of the given graph is a bipartite

//note: if a graph is bipartite then it can be divided in two groupps such that no two elements in same group are connected
//thus the original graph will be such that  all the elements in one group will be connected to every other element
bool BFS_with_color_checker(vector<vector<int>>& arr, int v, vector<int>& colortoggle, int s) {
    colortoggle[s] = 1;//initialising color of source as 1
    queue<int>q;
    q.push(s);
    while (!q.empty()) {//normal breadth first search algorithm with assignment of colors
        int  curr = q.front();
        q.pop();
        for (int i = 0;i < v;i++) {
            if (i != curr) {
                if (!arr[curr][i] && colortoggle[i] == -1) {//if in the original graph, i and curr are not connected and i have no color then we giive it a color different from curr
                    q.push(i);
                    colortoggle[i] = colortoggle[curr] == 0 ? 1 : 0;
                }

                //if curr and i have same color and they are not connected in original graph then we return false, as the compliment of the graph is not bipartite
                else if (!arr[curr][i] && colortoggle[i] == colortoggle[curr]) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool canBeDivided(vector<vector<int>>& arr, int v) {
    vector<int>colortoggle(v, -1);//initialising color toggle array as -1

    for (int i = 0;i < v;i++) {
        if (colortoggle[i] == -1) {
            //check for each non filled color element 
            if (!BFS_with_color_checker(arr, v, colortoggle, i))return false;
        }
    }
    //compliment of graph is bipartite
    return true;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input_3.txt", "r", stdin);
    freopen("output_3.txt", "w", stdout);
#endif
    int t;cin >> t;
    while (t--) {
        int n;cin >> n;
        vector<vector<int>> arr(n, vector<int>(n));
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                cin >> arr[i][j];

        if (canBeDivided(arr, n))cout << "Yes, the graph can be divided into 2 cliques";
        else cout << "no, graph cannot be divided into 2; cliques";
        cout << endl;
    }
    return 0;
}