#include<bits/stdc++.h>
using namespace std;

//greedy approach is not the optimal approach

//here we give priority to those items which have more value/weight value
struct comparator {//custom comparator function for the map so that we get our desired order
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return (a.first / a.second) > (b.first / b.second);
    }
};
//greedy approach is to choose in order of best value/weight value 
int greedy_maxval(int weight[], int val[], int n, int W) {
    multimap<pair<int, int>, int, comparator>m;//multimap  which stores the pair of val and weight and the weight with our custom comparator function for the desired order
    for (int i = 0;i < n;i++)
        m.insert(pair<pair<int, int>, int>({ val[i],weight[i] }, weight[i]));//inserting all the elements into the map
    int ans = 0;
    for (auto x : m) {
        if (x.second <= W) {//if the weight of current element is less than the weight left then add it to the bag
            W -= x.second;
            ans += x.first.first;
        }
    }
    return ans;
}

int main() {
    freopen("input1_greedy.txt", "r", stdin);
    freopen("output_greedy.txt", "w", stdout);
    int t;cin >> t;//number of test cases
    while (t--) {
        int n;cin >> n;//no of items
        int weight[n], val[n];
        for (int i = 0;i < n;i++)cin >> weight[i];//input weight of each item
        for (int i = 0;i < n;i++)cin >> val[i];//input value of each item
        int W;
        cin >> W;//input maximum allowable weight
        cout << greedy_maxval(weight, val, n, W) << endl;//outputing result
    }
    return 0;
}