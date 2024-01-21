#include<bits/stdc++.h>
using namespace std;

//quick sort function with pivot close to median
void medquicksort(int arr[],int l,int r){

    //if r is less than or equal to l then the size of array is 0 or 1 so we will not  do anything
    if(r<=l)return;

    //if size of array is 2 then will just check if first element is smaller than second element
    if(r-l==1){
        if(arr[l]>arr[r])swap(arr[l],arr[r]);
        return;
    }
    
    //we will compute the mid of left and right and sort left,mid and right

    int mid=l+(r-l)/2;
    int mn=min(arr[l],min(arr[r],arr[mid]));
    int mx=max(arr[l],max(arr[r],arr[mid]));
    int sum=arr[l]+arr[r]+arr[mid];
    arr[l]=mn;
    arr[r]=mx;
    arr[mid]=sum-mn-mx;

    //taking pivot as median of left, mid, and right

    int pivot=arr[mid];
    int i=l;
    int j=r;
    //swapping mid element with element just after the left element
    //appplying hoare's partition function on left+1 to right-1 part of the array
    //no need to include left and right element as left element is already smaller than pivot and right element is larger 
    //than pivot
    swap(arr[mid],arr[i+1]);
    while(true){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j)break;
        swap(arr[i],arr[j]);
    }
    //left of j is smaller than or equal to pivot and right of j is greater than or equal to pivot
    //thus, calling quicksort in these two subarrays and getting the sorted array
    medquicksort(arr,l,j);
    medquicksort(arr,j+1,r);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input_6.txt", "r", stdin);
    freopen("output_6.txt", "w", stdout);
#endif
int t;cin>>t;
while(t--){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    medquicksort(arr,0,n-1);
    for(int i=0;i<n;i++)cout<<arr[i]<<' ';
    cout<<endl;
}
return 0;
}