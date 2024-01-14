#include<bits/stdc++.h>
using namespace std;
int maxval(int val[],int  wt[],int n,int w){

    //creating dynamic programming array for different weights and n
    int dp[n+1][w+1];

    //if maxweight w is 0 then we cannot take out any item so the maxval will be 0
    for(int i=0;i<=n;i++)dp[i][0]=0;

    //if n=0 then no item in array so regardless the weight we cannot take any item(as there is no item to pick)
    for(int i=0;i<=w;i++)dp[0][i]=0;

    //now for a given i(no. of elements) and j(max weight) we have two options -> 1. we pick the last element (i) and reduce the 
    //max weight by this element's weight or we do not pick the item and consider the rest of the items and we will take the max of both cases
    for(int i=1;i<=n;i++)
        for(int j=1;j<=w;j++)
            if(wt[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else 
                dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);

    //our ans will be the last element of ddynamic programming array
    //(the case with n element s and w maxweight)
    return dp[n][w];
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif

int t;cin>>t;
while(t--){
    int n;cin>>n;
    int w;cin>>w;
    int wt[n],val[n];
    for(int i=0;i<n;i++)cin>>val[i];
    for(int i=0;i<n;i++)cin>>wt[i];
    cout<<maxval(val,wt,n,w)<<endl;
}
return 0;
}