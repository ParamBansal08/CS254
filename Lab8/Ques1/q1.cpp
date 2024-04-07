#include<bits/stdc++.h>
using namespace std;

struct disj {
    int* p, * r;
    disj(int n) {
        p = new int[n];
        r = new int[n];
        for (int i = 0;i < n;i++) {
            p[i] = i;r[i] = 0;
        }
    }
    int f(int x) {
        if (p[x] == x)return x;
        p[x] = f(p[x]);
        return p[x];
    }
    void u(int x, int y) {
        int x_rep = f(x);
        int y_rep = f(y);
        if (x_rep == y_rep)return;
        if (r[x_rep] < r[y_rep])p[x_rep] = y_rep;
        else if (r[y_rep] < r[x_rep])p[y_rep] = x_rep;
        else { p[y_rep] = x_rep;r[x_rep]++; }
    }
};

struct edge {
    int src, dest, wt;
    edge(int s, int d, int w) {
        src = s;
        dest = d;
        wt = w;
    }
    edge() {
        src = 0;
        dest = 0;
        wt = 0;
    }
};
bool mycmp(edge e1, edge e2) {
    return e1.wt > e2.wt;
}

int kruskal(edge arr[], int v, int e) {
    sort(arr, arr + e, mycmp);
    disj newdisj(v);
    for (int i = 0;i < v;i++) {
        newdisj.p[i] = i;
        newdisj.r[i] = 0;
    }
    int res = 0;
    for (int i = 0, s = 0;s < v - 1;i++) {
        edge e = arr[i];
        int x = newdisj.f(e.src);
        int y = newdisj.f(e.dest);
        if (x != y) {
            res += e.wt;
            newdisj.u(x, y);
            s++;
        }
    }
    return res;
}

int main() {
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int v, e;
        cin >> v >> e;
        edge arr[e];
        for (int i = 0;i < e;i++) {
            int x, y, w;
            cin >> x >> y >> w;
            arr[i].src = x; 
            arr[i].dest = y; 
            arr[i].wt = w; 
        }
        cout << kruskal(arr, v, e) << endl;
    }

    return 0;
}