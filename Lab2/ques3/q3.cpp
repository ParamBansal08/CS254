#include<bits/stdc++.h>
using namespace std;
//the idea is to use gap method 

void inplace_merge(int arr[],int n,int m){
    //initialise gap with ceiling of length of array/2
    int gap=(n+1)/2;

    while(gap>0){
        //we initialise left from 0 and right at gap distance away from left and we move them 
        //simultaneously by 1 position and while doing so, we swap left and right if left element is 
        //larger than right element and then reduce gap to ceil of gap/2.
        int left=0;
        int right=left+gap;
        while(right<n){
            if(arr[left]>arr[right])
                swap(arr[left],arr[right]);
            left++;right++;
        }
        if(gap==1)break;
        gap=(gap+1)/2;
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input_3.txt", "r", stdin);
    freopen("output_3.txt", "w", stdout);
#endif
int t;cin>>t;//no. of test cases
while(t--){
    int n,m;//size of array and point m
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];//input into array

    inplace_merge(arr,n,m);//applying inplace merge

    for(int i=0;i<n;i++)cout<<arr[i]<<' ';//outputing result
    cout<<endl;
}
return 0;
}