#include<bits/stdc++.h>
using namespace std;


// the main idea of the solution is breadth first search in which we will consider all the adjacent elements of an element (including diagonal). while doing breadth first search we will recursively calculate the number of elements in the region. While doing so , if we encounter 0 in array then it means no contribution of that element in the region and we will return 0.

//for the sake of simplicity of code, i have also incorporated a square frame(border) of 0s in the array to check that we don't go out of bound.

//if we encounter this square frame (basically border of 0s), then we will return 

//A visited array is also maintained so that we do not encounter a vertex twice.

//It can be noted that once a region is calculated , then any element in this region will not be encountered again as if we do breadth first search for any of these elements, we will get the same region length

int upgraded_BFS(vector<vector<int>>& arr, vector<vector<int>>& visited, int i, int j) {
    if (arr[i][j] == 0)return 0;//i,j not in the region
    if (visited[i][j])return 0;//if already visited, then return 0
    visited[i][j] = 1;//i,j is now visited

    //recursively calculating the size of region
    return 1 + upgraded_BFS(arr, visited, i + 1, j)
        + upgraded_BFS(arr, visited, i - 1, j)
        + upgraded_BFS(arr, visited, i, j + 1) + upgraded_BFS(arr, visited, i, j - 1) + upgraded_BFS(arr, visited, i + 1, j + 1) + upgraded_BFS(arr, visited, i - 1, j - 1) + upgraded_BFS(arr, visited, i + 1, j - 1) + upgraded_BFS(arr, visited, i - 1, j + 1);
}

int largestRegion(vector<vector<int>>& arr, int n, int m) {
    int ans = 0;//initialisation of result
    //visited array. Note that vector is initialised with 0 as default
    vector<vector<int>> visited(n + 2, vector<int>(m + 2));
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (arr[i][j] == 1) {
                if (!visited[i][j]) {//if i,j is not visited then we call the upgraded BFS function and calculate the region corresponding to it
                    int temp = upgraded_BFS(arr, visited, i, j);
                    ans = max(ans, temp);//getting the maximum ans

                }
            }
        }
    }
    return ans;//returning the ans
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input_1.txt", "r", stdin);
    freopen("output_1.txt", "w", stdout);
#endif
    int t;cin >> t;//no. of test cases
    while (t--) {
        int n, m;//rows and columns in array
        cin >> n >> m;

        vector<vector<int>>arr(n + 2, vector<int>(m + 2));
        //input into array
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= m;j++)
                cin >> arr[i][j];
        }
        //outputing result
        cout << largestRegion(arr, n, m) << endl;

    }

    return 0;
}