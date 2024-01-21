#include<bits/stdc++.h>
using namespace std;
//we merge two sorted arrays by comparing first element of both the arrays. If a1's first element is smaller then we 
//append this element in the merged array and increment the index of a1 by 1 and repeat the process until all the 
//elements of atleast 1 of the arrays are processed
//then we simply append the elements of the array which has remaining elements to be processed
vector<int> merge(int a1[],int a2[],int n,int m){
    int i=0,j=0;//initialising index of both the arrays
    vector<int>merged_array;//resultant vector

    //comparing the elements of both the arrays and appending into the vector
    while(j<m&&i<n){
        if(a1[i]<a2[j]){
            merged_array.push_back(a1[i]);
            i++;
        }
        else{
            merged_array.push_back(a2[j]);
            j++;
        }
    }
    //outputing the remaining elements
    while(j++<m)merged_array.push_back(a2[j-1]);
    while(i++<n)merged_array.push_back(a1[i-1]);
    return merged_array;

}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input_1a.txt", "r", stdin);
    freopen("output_1a.txt", "w", stdout);
#endif

//no. of test cases
int t;cin>>t;
while(t--){
    //sizes of both the arrays
    int n,m;
    cin>>n>>m;
    int a[n],b[m];

    //input into arrays
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    //result in merged_array
    vector<int>merged_array=merge(a,b,n,m);
    //outputing the result
    for(int i=0;i<merged_array.size();i++)cout<<merged_array[i]<<' ';
    cout<<endl;
}

return 0;
}