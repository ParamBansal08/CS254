#include <bits/stdc++.h>
using namespace std;
int main(){

#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif

//no. of test cases
int t;cin>>t;
while(t--){
    //size of the array
    int n;
    //input size of array
    cin>>n;
    int arr[n];
    //input array
    for(int i=0;i<n;i++)cin>>arr[i];
    //initialising both mx and smx as minimum value
    int mx=INT_MIN;
    int smx=INT_MIN;
    //now the main concept is that we will traverse the array
    //if element is bigger than the maxvaalue, we will update max value and second max value will be previous max value
    //else if element is smaller than the max value than we will 
    //check if the element is bigger than second max value. if 
    //element is bigger than second max value then we will update the second max value
    for(int i=0;i<n;i++){
        if(arr[i]>=mx){
            smx=max(smx,mx);
            mx=arr[i];
        }
        else {
            if(arr[i]>smx)smx=arr[i];
        }
    }
    cout<<mx+smx<<endl;
}
}