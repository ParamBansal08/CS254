#include<bits/stdc++.h>
using namespace std;

//initialising indexing of two arrays with 0 ad incrementing them until a common element is found
vector<int>solve(int a1[],int a2[],int n,int m){
    vector<int>intersection_array;
    int i=0,j=0;
    while(j<m&&i<n){
        if(i>0&&a1[i]==a1[i-1]){i++;continue;}//to avoid duplicates
        if(a1[i]<a2[j]){i++;}
        
        else if(a1[i]>a2[j]){
            j++;
        }
        //both elements are equal thus appending them in the result
        else{
            intersection_array.push_back(a1[i]);
            i++;
            j++;
        }
    }
    return intersection_array;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input_1c.txt", "r", stdin);
    freopen("output_1c.txt", "w", stdout);
#endif
int t;cin>>t;
while(t--){
    int n,m;
    cin>>n>>m;  

    int a1[n];
    for(int i=0;i<n;i++)cin>>a1[i];

    int a2[m];
    for(int j=0;j<m;j++)cin>>a2[j];
    
    vector<int>intersection_array=solve(a1,a2,n,m);

    for(auto x:intersection_array)cout<<x<<' ';cout<<endl;

}
return 0;
}