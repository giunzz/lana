// MR.J
#include<bits/stdc++.h>
#define maxn 1000005
#define maxC 1000000000
#define MOD 1000000007
#define mp make_pair
#define PB push_back
#define F first
#define S second
#define pii pair<int, int>
#define ll long long
#define rep(i, a, b) for(int i=(a) ; i<=(b) ; ++i)
#define repd(i, a, b) for(int i=(a) ; i>=(b) ; --i)
#define Task "gifts"
using namespace std;
int n, k;
ll tt[maxn], b[maxn], ans = 1000000000000000ll;

struct IntervalTree {
    ll tree[maxn*6];

    void build(int l, int r, int node) {
        if(l == r) {
            tree[node] = b[l];
            return;
        }
        int mid = (r + l) >> 1;
        build(l, mid, node*2);
        build(mid+1, r, node*2+1);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }

    ll getAns(int l, int r, int node, int u, int v) {
        if(v < l || r < u) return -maxC;
        if(u <= l && r <= v) return tree[node];
        int mid = (r + l) >> 1;
        return max(getAns(l, mid, node*2, u, v), getAns(mid+1, r, node*2+1, u, v));
    }
} IT;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> k;
    rep(i, 1, n) {
        int a;
        cin >> a;
        tt[i] = tt[i-1] + 1ll*a;
        if(i >= k) b[i] = tt[i] - tt[i-k];
    }
    IT.build(1, n, 1);
    rep(i, k, n) {
        int x1 = i - k;
        int x2 = i + k;
        ll sumLef = 0, sumRig = 0;
        if(x1 > 0) sumLef = IT.getAns(1, n, 1, 1, x1);
        if(x2 <= n) sumRig = IT.getAns(1, n, 1, x2, n);
        ans = min(ans, max(sumLef, sumRig));
    }
    cout << ans;
    return 0;
}
