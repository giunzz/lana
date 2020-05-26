#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define lpdk(a, b, c, d) for(ll a = b; c; d)
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
using namespace std;
cll MOD = 1e9 + 7;
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e7 + 3;
ll n, q, a, b, k, ans;

void fs(ll &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if(c == ' ') fs(number);
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}

struct Node{
    ll lazy;
    ll val;
}st[4 * maxn];

void down(int id){
    int t = st[id].lazy;
    st[id * 2].lazy += t;
    st[id * 2].val += t;
    st[id * 2 + 1].lazy += t;
    st[id * 2 + 1].val += t;
    st[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, ll val){
    if (v < l || r < u) return;
    if (u <= l && r <= v){
        st[id].val += val;
        st[id].lazy += val;
        return;
    }
    int mid = (l + r) / 2;
    down(id);
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    st[id].val = max(st[id * 2].val, st[id * 2 + 1].val);
}

ll getmax(ii id, ii l, ii r, ii u, ii v){
    if(v < l || r < u) return INT_MIN;
    if(u <= l && r <= v){
        return st[id].val;
    }
    ii mid = (l + r) / 2;
    down(id);
    return max(getmax(id * 2, l, mid, u, v), getmax(id * 2 + 1, mid + 1, r, u, v));

}

int main(){
    file;
    fs(n); fs(q);
    lp(i, 1, q){
        fs(a); fs(b); fs(k);
        update(1, 1, n, a, b, k);
    }
    ans = getmax(1, 1, n, 1, n);
    printf("%I64d", ans);
}
