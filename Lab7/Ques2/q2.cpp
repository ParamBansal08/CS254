#include<bits/stdc++.h>
using namespace std;

//here the greedy approach is that we choose jobs in order of maximum profits and fit them according to deadline which is optimissed using priority queue

//the main idea is
//it should be noted that if deadline is 1 then only one job can be done
// for deadline 2 , either 1 job of deadline 1 and 1 job of deadline 2 or 2 jobs of deadline 2 can be done
//similarly, for deadline 3, either 3 jobs of deadline 3, or 2 jobs of deadline 2 and 1 job of deadline 3 or 2 jobs of deadline 3 and 1 job of deadline 1 or 2 jobs of deadline 3 and 1 job of deadline 2 or ...

//in each case it can be noted that for deadline x, maximum x jobs of deadline x can be done
//so lets say we have deadlines 1,3,4,6
//so we can do maximum 1 job of deadline 1 and maximum 3 jobs of deadline 3 and maximum4 jobs of deadline 4 and maximum 6 jobs of deadline 6
//and overall maximum 6 jobs can be done
//so basically we can use a priority queue which store the jobs profit in descending order
//such that maximum 1 job of deadline 1 , 2 jobs of deadline 2 and so on
//and also , if 1 job of deadline 1 is done then maximum 1 job of deadline 2 , maximum 2 jobs of deadline 2 and so on


//custom comparator operation which order the jobs according to descending order of their profits
//for minheap 
struct comparator {
    bool operator ()(const pair<int, pair<int, char>>& p1, const pair<int, pair<int, char>>& p2) {
        return p1.first > p2.first;
    }
};

int maxprofit(map<int, vector<pair<int, char>>>& m) {//map of deadline and pairs of profit and name of job

    //minheap of pair of profit and pair of deadline and name of job
    priority_queue<pair<int, pair<int, char>>, vector<pair<int, pair<int, char>>>, comparator >pq;
    //minheap of jobs according to their profits
    int ans = 0;
    for (auto x : m) {
        int curr = x.first;//curr is the maximum size of pq for this iteration
        //it should be noted that in the previous iteration size of pq is acording to that iteration
        //so our constraint will remain valid
        int size = (int)(x.second).size();//size of vector

        for (int i = 0;i < size;i++) {
            if ((int)pq.size() < curr) {//if size of heap is less than maximum size for this iteration, simply add the job
                pq.push({ x.second[i].first,{x.first,x.second[i].second} });
                ans += x.second[i].first;//updating ans(maximum profit)
            }
            else if (pq.top().first < x.second[i].first) {//if size of heap is equal to maximum size and the current job gives more profit
                ans -= pq.top().first;//pop the minimum profit job in the heap and update the ans(max profit)
                pq.pop();

                pq.push({ x.second[i].first,{x.first,x.second[i].second} });//insert the current job and update the ans(maximum profit)
                ans += x.second[i].first;
            }
        }
    }
    multimap<int, char>dl;//for printing the sequence of job we make a multimap of deadline and name of job and contain all the elements of heap
    while (!pq.empty()) {
        dl.insert(pq.top().second);
        pq.pop();
    }
    for (auto q : dl) {
        cout << q.second << ' ';//outputing sequence
    }
    cout << endl;

    return ans;//returning maximum profit

}

int main() {
    // freopen("input2.txt", "r", stdin);
    // freopen("output2.txt", "w", stdout);
    int t;cin >> t;//number of test cases
    while (t--) {
        int n;
        cin >> n;//number of jobs
        map<int, vector<pair<int, char>>>m;
        for (int i = 0;i < n;i++) {
            char c;//name of job
            int d, p;//deadline and profit
            cin >> c >> d >> p;
            m[d].push_back({ p,c });//inserting into map
        }
        cout << maxprofit(m) << endl << endl;
    }
    return 0;
}