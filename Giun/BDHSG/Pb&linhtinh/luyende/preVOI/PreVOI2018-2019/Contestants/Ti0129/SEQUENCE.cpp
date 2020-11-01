#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 5;

int n, m, k, a[N], b[N], c[N];

struct State {
    int val, idx;
    State (int val = 0, int idx = 0): val(val), idx(idx) {}
    bool operator < (const State &rhs) const {
        if (val != rhs.val) return val > rhs.val;
        return idx < rhs.idx;
    }
};

int main(){
    #ifndef Futymy
        freopen("SEQUENCE.inp", "r", stdin);
        freopen("SEQUENCE.out", "w", stdout);
    #endif // Futymy
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
    priority_queue <State, vector <State> > pq;
    if (k <= m) {
        for (int i = 1; i <= m; i++) pq.push({b[i], i});
        int cnt = 0;
        while (cnt < k) {
            cnt++;
            int idx = pq.top().idx, val = pq.top().val; pq.pop();
            c[idx] = val;
        }

        vector <int> vec;
        for (int i = 1; i <= m; i++) if (c[i]) vec.push_back(c[i]);
        for (auto i: vec) printf("%d ", i);
    }
    else {
        for (int i = 1; i <= n; i++) pq.push({a[i], i});
        int cnt = 0;
        deque <int> vec;
        while (cnt < k - m) {
            cnt++;
            int idx = pq.top().idx, val = pq.top().val; pq.pop();
            c[idx] = val;
        }

        for (int i = 1; i <= n; i++) if (c[i]) vec.push_back(c[i]);
        bool f = true;
        for (int i = 1; i <= m; i++) {
            if (b[i] <= vec[0] && f) vec.push_front(b[i]);
            else vec.push_back(b[i]), f = false;
        }

        for (auto i: vec) printf("%d ", i);
    }
    return 0;
}
/*
7 4 9
1 2 1 3 1 2 1
1 2 3 1
*/
