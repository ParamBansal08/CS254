#include<bits/stdc++.h>
using namespace std;


vector<int>union_of_array(int a1[],int a2[],int n,int m){
    int i=0,j=0;//initialising indexing of both the arrays from 0
    vector<int>union_array;

    //loop until all the elements of atleast one array are processed
    while(i<n&&j<m){
        //inputing smallest element first and then increasing the index until other element is found
        if(i>0&&a1[i]==a1[i-1]){i++;continue;}
        if(j>0&&a2[j]==a2[j-1]){j++;continue;}
        if(a1[i]<a2[j]){
            union_array.push_back(a1[i]);
            i++;
        }
        else if(a1[i]>a2[j]){
            union_array.push_back(a2[j++]);
        }
        else{
            union_array.push_back(a2[j]);
            j++;
            i++;
        }
    }
    //appending remaining elements and increasing index such that no element is repeated
    while(i<n){
        if(i>0&&a1[i]!=a1[i-1])
            union_array.push_back(a1[i]);
        i++;
        while(i<n&&a1[i]==a1[i-1])i++;
    }
    while(j<m){
        if(j>0&&a2[j]!=a2[j-1])
            union_array.push_back(a2[j]);
        j++;
        while(j<m&&a2[j]==a2[j-1])j++;
    }
    return union_array;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input_1b.txt", "r", stdin);
    freopen("output_1b.txt", "w", stdout);
#endif
int t;cin>>t;
while(t--){
    int n,m;
    cin>>n>>m;
    int a1[n],a2[m];
    for(int i=0;i<n;i++)cin>>a1[i];
    for(int i=0;i<m;i++)cin>>a2[i];
    vector<int>union_array=union_of_array(a1,a2,n,m);
    for(auto x:union_array)cout<<x<<' ';
    cout<<endl;
}
return 0;
}