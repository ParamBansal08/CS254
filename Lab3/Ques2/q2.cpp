#include<bits/stdc++.h>
using namespace std;

//function to find sum of subarray with maximum sum of elements

//we will find the maximum sum subarray ending at each index and our answer will be the maximum of all these sums
int largestSumSubarray(int arr[],int n){

    int ans=arr[0];//initialising answer as first element of array

    int maxEnding=arr[0];// maximum sum of subarray ending with first element is the element itself

    for(int i=1;i<n;i++){

        //maximum sum subaraay ending at element i is formed either using (maximum sum subarray ending at element (i-1) + arr[i] ) OR the element itself is the maximum sum subarray ending with element i
        maxEnding=max(maxEnding+arr[i],arr[i]);

        //updating the answer if current maxEnding is larger than the ans
        ans=max(ans,maxEnding);
    }
    return ans;//returning tha answer
}

//Apart from the above method, there is also another divide and conquer algorithm which has time complexity O(nlogn) and that approach is written below

//function to find sum of subarray with maximum sum of elements

//since we are using divide and conquer algorithm we will provide l (left) and r (right) as parameters
int largestSumSubarray2(int arr[],int l,int r){
    if(l>r)return INT_MIN;//if left and right cross each other we return INT_MIN so that this does not interfere with other sums

    int mid=l+(r-l)/2;//calculating mid element

    //finding maximum sum subarray which lies completely in left half
    int lsum=largestSumSubarray2(arr,l,mid-1);

    //finding maximum sum subarray which lies completely in right half
    int rsum=largestSumSubarray2(arr,mid+1,r);

    //now finding the maximum subarray which includes the middle element

    //midsum1 will store maximum subarray formed using middle element and left half 
    //midsum2 will store maximum subarray formed using middle element and right half 
    int midsum1=INT_MIN,midsum2=INT_MIN;
    int currsum=0;
    //loop to find midsum1
    for(int i=mid;i>=l;i--){
        currsum+=arr[i];
        midsum1=max(midsum1,currsum);
    }
    currsum=0;
    //loop to find midsum2
    for(int i=mid;i<=r;i++){
        currsum+=arr[i];
        midsum2=max(midsum2,currsum);
    }

    //note that maximum sum subarray using left half middle element and right half is equal to 
    //midsum1+midsum2-arr[mid]
    //midsum1=arr[mid]+sum_using_only_left_half ; midsum2=arr[mid]+sum_using_only_right_half
    //midsum1+midsum2=2*arr[mid]+sum_using_only_left_half+sum_using_only_right_half
    //midsum1+midsum2-arr[mid]=arr[mid]+sum_using_only_left_half+sum_using_only_right_half
    //midsum1+midsum2-arr[mid]=sum using middle element left half and right half
    int midsum=max(midsum1,max(midsum2,midsum1+midsum2-arr[mid]));

    //returning maximum of all the three sums
    return max(lsum,max(rsum,midsum));
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input_2.txt", "r", stdin);
    freopen("output_2.txt", "w", stdout);
#endif
int t;cin>>t;//number of test cases
while(t--){
    int n;cin>>n;//size of array
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];//input into array

    cout<<largestSumSubarray(arr,n)<<endl;//outputing result
}
return 0;
}