#include<bits/stdc++.h>
using namespace std;
int mindis(vector<vector<int>>&dp,vector<vector<int>>&dis,int n,int visited,int pos){
    //using booleans to determine whether a city is visited or not. for eg. 1001 means than only '0' and '3' cities are visited
   
    //if all cities are visited we return distance between initial and current pos
    if(visited==((1<<n)-1))return dis[pos][0];

    //if current condition of visited cities is same and we are on the same position for whose, we have already calculated the dp
    //we return that memo
    if(dp[visited][pos]!=-1)
        return dp[visited][pos];
    int ans=INT_MAX;

    //for the current position we will consider all cases from this pos to other unvisited cities and calculate dp  recursively 
    //also we will update the ans 
    for(int i=0;i<n;i++){
        if((visited&(1<<i))==0){
            int curr=dis[pos][i]+mindis(dp,dis, n,visited|(1<<i),i);
            ans=min(ans,curr);
        }
    }
    //return the memo of the current visited and pos
    return dp[visited][pos]=ans;
}
int main(){

#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif

//no. of test cases 
int t;cin>>t;
while(t--){
    //no of cities
    int n;cin>>n;
    
    //dynamic programming vector with initial values -1
    vector<vector<int>>dp;
    vector<int>d;
    for(int j=0;j<n;j++)
            d.push_back(-1);
    int x=1<<n;
    for(int i=0;i<x;i++){
        dp.push_back(d);
    }

    //distance between cities (adjacency matrix)
    vector<vector<int>>dis;
    for(int i=0;i<n;i++){
        vector<int>v(n);
        for(int j=0;j<n;j++){
            cin>>v[j];
        }
        dis.push_back(v);
    }
    
   //minimum cost/distance
    cout<<mindis(dp,dis,n,1,0)<<endl;
}
return 0;
}