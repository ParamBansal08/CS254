#include<bits/stdc++.h>
using namespace std;

//dynamic programming approach 
int maxval(int weight[], int val[], int n, int W) {
    int dp[n + 1][W + 1];//creating dp array
    for (int i = 0;i <= n;i++)
        dp[i][0] = 0;//if max weight allowed is 0 we cannot add any element
    for (int i = 0;i <= W;i++)
        dp[0][i] = 0;//if there is no element then we cannot add any element

    for (int i = 1;i <= n;i++)//if weight of current element is less than the allowed weight then we take maximum value if it is added or it is not added
        for (int j = 1;j <= W;j++) {
            if (weight[i - 1] <= j) {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            }
            else dp[i][j] = dp[i - 1][j];//if weight is greater then we simply not take this element
        }
    return dp[n][W];//returning the answer
}
int main() {
    freopen("input1_optimal.txt", "r", stdin);
    freopen("output_optimal.txt", "w", stdout);
    int t;cin >> t;//number of test cases
    while (t--) {
        int n;cin >> n;//no. of items
        int weight[n], val[n];
        for (int i = 0;i < n;i++)cin >> weight[i];//input weight of each element
        for (int i = 0;i < n;i++)cin >> val[i];//input value of each element
        int W;
        cin >> W;//input maximum allowable weight
        cout << maxval(weight, val, n, W) << endl;;

    }
    return 0;
}