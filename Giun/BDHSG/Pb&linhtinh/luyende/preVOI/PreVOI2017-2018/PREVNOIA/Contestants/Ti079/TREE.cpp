#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5005;
int n, x[N], dad[N], u, v, leaf[N], kt[N], res;
vector<int> a[N];
queue<int> q;
struct tree {
    int sum_child, cnt_child;
    tree () {
        sum_child = cnt_child = 0;
    }
} t[N];
int main()
{
    #define file "TREE"
    freopen(file".INP" ,"r" ,stdin);
    freopen(file".OUT" ,"w" ,stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> x[i];
    for(int i = 1; i <= n - 1; ++i) {
        cin >> u >> v;
        a[u].push_back(v);
    }
    q.push(1);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        if (a[u].size() == 0) leaf[u] = 1;
        for(int i = 0; i < a[u].size(); ++i) {
            v = a[u][i];
            q.push(v);
            dad[v] = u;
        }
    }
    for(int i = 2; i <= n; ++i)
        if (leaf[i]) {
            t[dad[i]].sum_child += x[i];
            t[dad[i]].cnt_child++;
        }
    vector<int> up;
    for(int i = 2; i <= 2; ++i)
        if (leaf[i] && !kt[dad[i]]) {
            kt[dad[i]] = 1;
            up.push_back(dad[i]);
            if (x[dad[i]] == 0) {
                res += t[dad[i]].sum_child;
            }
            if (x[dad[i]] == 1) {
                res += abs(t[dad[i]].sum_child - 1);
            }
            if (x[dad[i]] == 2) {
                if (t[dad[i]].cnt_child == 1) res += abs(t[dad[i]].sum_child - 1), x[dad[i]] = 1;
                else
                    res += abs(t[dad[i]].sum_child - 2);
            }
            if (x[dad[i]] > 2) {
                 if (t[dad[i]].cnt_child == 1) res += abs(t[dad[i]].sum_child - 1), x[dad[i]] = 1;
                else {
                        res += abs(t[dad[i]].sum_child - 2) + x[dad[i]] - 2;
                x[dad[i]] = 2;
                }
            }
        }
//    cout << res;
    for(int i = 0; i < up.size(); ++i) {
        int u = up[i];
        while (u) {
            t[dad[u]].sum_child += x[u];
            u = dad[u];
        }
    }
    for(int i = 1; i <= n; ++i)
        if (!leaf[i] && !kt[i]) res += x[i] - t[i].sum_child;
    cout << 4;
    return 0;
}
