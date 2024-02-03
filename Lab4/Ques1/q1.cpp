#include<bits/stdc++.h>
using namespace std;
int countAndMerge(int arr[],int l,int m,int r){
    //this function will count the number of inversions in the two half and also merge the two sorted halves

    
    int i=l,j=m+1;
    int c[r-l+1];//array of size r-l+1 which will store all the elements from arr[l] to arr[r] in sorted order
    int count=0;
    int index=0;
    while(i<=m&&j<=r){
        if(arr[i]<=arr[j])//no inversion,we simply update the c array
            c[index++]=arr[i++];
  
        else {
            c[index++]=arr[j++];//inversion happened so we increment the count and also update c
            count+=m-i+1;
        }
        
    }
    while(i<=m)c[index++]=arr[i++];//appending rest of the elements into c
    while(j<=r)c[index++]=arr[j++];
    for(int i=l;i<=r;i++){
        arr[i]=c[i-l];//copying into original array
    }
    return count;//returning the count
}
int countInversions(int arr[],int l,int r){
    if(l>=r)return 0;//if left and right have crossed each other then there is single or no element so count is 0
    int mid=l+(r-l)/2;
    int counts=countInversions(arr,l,mid);//counts calculated in left half and also sorted the right half
    counts+=countInversions(arr,mid+1,r);//counts calculated in right half and also sorted the right half
    counts+=countAndMerge(arr,l,mid,r);//counts calculated by checking inversions in left and right halves
    return counts;//returning counts result
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input_1.txt", "r", stdin);
    freopen("output_1.txt", "w", stdout);
#endif
int t;cin>>t;//no. of test cases
while(t--){
    int n;cin>>n;//size of array
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];//input into array
    cout<<countInversions(arr,0,n-1)<<endl;//outputing results
}
return 0;
}