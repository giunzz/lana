#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a); i<=(b); ++i)
#define FORR(i,a,b) for (int i=(a); i>=(b); --i)
#define REP(i,b) for (int i=0; i<(b); ++i)
#define input stdin
#define output stdout
#define assign freopen
#define endl '\n'
#define sz(x) (int) x.size()
#define div /
#define mod %
#define fillchar(x,y,z) memset(x,z,y)
#define pii pair<int64,int64>
#define fi first
#define se second
#define mp make_pair
#define sqr(x) ((x)*(x))
typedef long long int64;
typedef unsigned long long qword;
using namespace std;
const int maxn=1e4+5;
struct TNode {
    int L,R,cover;
    int64 val;
};
TNode st[5000000];
int n,m,cntNode;
int64 botx,topx,boty,topy;
pii a[maxn];
pair<pii,pii> b[maxn*2];
void Input()
{
    cin >>n >> m;
    FOR(i,1,n+1) {
        cin >> a[i].fi >> a[i].se;
        //rotate
        int64 x=a[i].fi-a[i].se;
        int64 y=a[i].se+a[i].fi;
        a[i].fi=x; a[i].se=y;
        //cerr << a[i].fi << ' '<< a[i].se << endl;
    }
    botx=a[n+1].fi-m;
    topx=a[n+1].fi+m;
    boty=a[n+1].se-m;
    topy=a[n+1].se+m;
}
void update(int id, int64 l, int64 r, int64 u, int64 v, int val)
{
    if (l>v||r<u) return;
    if (u<=l&&r<=v) {
        st[id].cover+=val;
        if (st[id].cover>=1)
            st[id].val=r-l+1;
        else
            st[id].val=st[st[id].L].val+st[st[id].R].val;
        return;
    }
    int64 mid=(l+r)/2;
    if (mid>=u) {
        if (st[id].L==0) st[id].L=++cntNode;
        update(st[id].L,l,mid,u,v,val);
    }
    if (mid+1<=v) {
        if (st[id].R==0) st[id].R=++cntNode;
        update(st[id].R,mid+1,r,u,v,val);
    }
    if (st[id].cover==0)
        st[id].val=st[st[id].L].val+st[st[id].R].val;
}
bool able(int64 far)
{
    m=0; //m is useless at this time
    FOR(i,1,n) {
        int64 xx1=max(a[i].fi-far,botx);
        int64 xx2=min(a[i].fi+far,topx);
        int64 yy1=max(a[i].se-far,boty);
        int64 yy2=min(a[i].se+far,topy);
        if (xx1>xx2||yy1>yy2) continue;
        b[++m]=mp(mp(xx1,-1),mp(yy1,yy2));
        b[++m]=mp(mp(xx2,1),mp(yy1,yy2));
    }
    if (m==0) return true;
    sort(b+1,b+1+m);
    if (b[1].fi.fi!=botx||b[m].fi.fi!=topx) return true;
    FOR(i,1,cntNode) st[i].L=st[i].R=st[i].val=st[i].cover=0;
    cntNode=1;
    b[0].fi.fi=botx;
    int64 len=topy-boty+1;
    FOR(i,1,m) {
        if (b[i].fi.fi!=b[i-1].fi.fi&&st[1].val!=len)
            return true;
        update(1,1,1e10,b[i].se.fi+5e9,b[i].se.se+5e9,-b[i].fi.se);
    }
    return false;
}
void Solve()
{
    int64 l=0,r=5e9,mid,res=-1;
    while (l<=r) {
        mid=(l+r)>>1;
        if (able(mid))
            res=mid,l=mid+1;
        else
            r=mid-1;
    }
    cout << res+1;
}
int main()
{
    assign("ROBOTS.INP","r",input);
    #ifndef meomeomeooooo
        assign("ROBOTS.out","w",output);
    #endif // meomeomeooooo
    iostream::sync_with_stdio(false);
    cin.tie(0);
    Input();
    Solve();
    return 0;
}
