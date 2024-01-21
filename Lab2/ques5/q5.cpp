#include<bits/stdc++.h>
using namespace std;
int main(){
#ifndef ONLINE_JUDGE
    freopen("input_5.txt", "r", stdin);
    freopen("output_5.txt", "w", stdout);
#endif
int t;
cin>>t;//no. of test cases
while(t--){
    //size of array
    int n;cin>>n;
    int arr[n];
    //input into array
    for(int i=0;i<n;i++)cin>>arr[i];

    //if size of array is 1 then there is only one element which is the minimum element.there is no 
    //second minimum element so return INT_MAX for second minimum element in that case
    int mn=INT_MAX;
    int smn=INT_MAX;
    if(n==1){
        cout<<arr[0]<<' '<<smn<<endl;continue;
    }

    //we run through the loop and check each element
    //if the current element is smaller than the current minimum element than we update second minimum element with the current minimum element and current minimum element with the currrent element
    for(int i=0;i<n;i++){
        if(arr[i]<=mn){
            smn=mn;
            mn=arr[i];
        }
        //if current element is not smaller than current minimum then we check second minimum element 
        //with that element and update the second minimum element if required
        else{
            if(arr[i]<smn)smn=arr[i];
        }
    }
    //outputing minimum and second minimum element
    cout<<mn<<' '<<smn<<endl;
}
return 0;
}