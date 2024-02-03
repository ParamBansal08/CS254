#include<bits/stdc++.h>
using namespace std;
float median(int a1[],int a2[],int n1,int n2){
    if(n1<=n2){//so that index does not goout of bound
        int l=0,r=n1;//initialising l and r as first and last elements (INT_MIN and INT_MAX)
        while(l<=r){
            int i=l+(r-l)/2;//middle element of smaller array
            //corresponding index of larger array such that:
            int j=(n2+n1+1)/2-i;
            //no. of elements from 0 to i-1 of a1 and o to j-1 of a2  is equal to number of elements from i to n1 and j to n2
            //if the total number of elements is odd then there is one extra element in the left subpart
            int min1=(i==n1)?INT_MAX:a1[i];
            int min2=(j==n2)?INT_MAX:a2[j];

            int max1=(i==0)?INT_MIN:a1[i-1];
            int max2=(j==0)?INT_MIN:a2[j-1];
            if(min1>=max2&&min2>=max1){//condition that fulfils the conditio that all the elements in left subpart are smaller than all the elements in right subpart

                //if toal elements are odd than the maximum element of left subpart is the median
                if((n1+n2)%2)
                    return max(max1,max2);
                
                // if total no. of elements is even than the median is avg of maximum element of left subpart and minimum element of right subpart
                return ((float)max(max1,max2)+(float)min(min1,min2))/2.0;
            }

            //if a1[i]<a2[j-1] then it means that the required segregating condition is at right subpart
            else if(max1>min2){
                r=i-1;
            }
            //else it means that the required segregating condition is at left subpart
            else l=i+1;
        }
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input_2.txt", "r", stdin);
    freopen("output_2.txt", "w", stdout);
#endif
int t;cin>>t;//no. of test cases
while(t--){
    int n1;//size of first array
    cin>>n1;
    int a1[n1];
    for(int i=0;i<n1;i++)cin>>a1[i];//input into array
    int n2;cin>>n2;//size of second array
    int a2[n2];
    for(int i=0;i<n2;i++)cin>>a2[i];//input into second array
    

    //passing the arguments such that n1 in the function is always smaller than n2
    cout<<fixed<<setprecision(9)<<((n1<n2)?median(a1,a2,n1,n2):median(a2,a1,n2,n1))<<endl;

}
return 0;
}