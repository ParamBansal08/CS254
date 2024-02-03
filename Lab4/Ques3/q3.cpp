#include<bits/stdc++.h>
using namespace std;
#define int long long
//we will use lomuto partition function to get the element at required index
//the idea is that we will check for pivot its position, if its position is the required position we will return that pivot
//this function will give the kth element in sorted array but if we want kth largest element than its position will be n-k in the array. thus , we will get pass n-k in the argument and get the kth largest element
int kthLargestElement(int arr[],int l,int r,int k){
    int pivot=arr[r];//taking last element as pivot
    int i=l-1,j=l;
    for(;j<r;j++){//normal partition function
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[++i],arr[j]);
    if(i==k)return arr[i];//if position of pivot is the required index than we return the pivot
    //if position is greater than the required index. it means the element is in the left part of the array
    if(i>k)return kthLargestElement(arr,l,i-1,k);
    //else element is in the right part
    return kthLargestElement(arr,i+1,r,k);
}
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input_3.txt", "r", stdin);
    freopen("output_3.txt", "w", stdout);
#endif
int t;cin>>t;
while(t--){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int k;
    cin>>k;
    cout<<kthLargestElement(arr,0,n-1,n-k)<<endl;
}
return 0;
}