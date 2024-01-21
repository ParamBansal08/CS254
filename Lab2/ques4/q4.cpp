#include<bits/stdc++.h>
using namespace std;

//this ElementAtIndex function return the element which would have been at the position Index if the 
//array was sorted using lomuto's partition algorithm
int ElementAtIndex(int arr[],int index,int l,int r){

    int i=l-1,j=l;//initialising i and j
    int pivot=arr[r];//taking last element as pivot

    //applying lomuto's partition in which we position the pivot at its correct index and 
    //all the elements before the pivot are smaller or equal than pivot and all the elements after the 
    //pivot are larger or equal than the pivot
    for(;j<=r-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[++i],arr[r]);
    
    
    if(i==index)return pivot;
    if(i>index){
        return ElementAtIndex(arr,index,l,i-1);
    }
    else return ElementAtIndex(arr,index,i+1,r);
}
float median(int arr[],int n){
    int i1=(n-1)/2,i2=n/2;
    int a1=ElementAtIndex(arr,i1,0,n-1);
    int a2=(n%2)?a1:ElementAtIndex(arr,i2,0,n-1);
    return ((float)a1+(float)a2)/2;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input_4.txt", "r", stdin);
    freopen("output_4.txt", "w", stdout);
#endif
int t;cin>>t;
while(t--){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    float med=median(arr,n);
    cout<<med<<endl;
}

return 0;
}