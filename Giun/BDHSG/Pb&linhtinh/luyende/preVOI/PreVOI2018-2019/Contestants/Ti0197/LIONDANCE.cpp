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
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define sqr(x) ((x)*(x))
typedef long long int64;
typedef unsigned long long qword;
using namespace std;
const int maxn=4005;
int n,lim;
int L[maxn],R[maxn];
int f[maxn][maxn];
int trace[maxn][maxn];
int b[maxn+maxn];
vector<int> st[maxn*8],adj[maxn*2];
vector<pii> BIT[maxn*8];
void Input()
{
    cin >> n >> lim;
    FORR(i,n,1) cin >> L[i];
    FORR(i,n,1) cin >> R[i];
}
void meomeo(int res, int save, int lim)
{
    if (res==0) return;
    cout << L[save] << ' ';
    FORR(i,lim,1)
        if (f[save][i]==res) {
            meomeo(res-1,trace[save][i],i-1);
            return;
        }
}
void Solve()
{
    int res=0;
    int save=0;
    FOR(i,1,n)
        FOR(j,1,n)
            if (L[i]==R[j]) {
                f[i][j]=1;
                FOR(x,1,i-1)
                    if (abs(L[i]-L[x])<=lim)
                        FOR(y,1,j-1)
                            if (L[x]==R[y]) {
                                if (f[i][j]<f[x][y]+1) {
                                    f[i][j]=f[x][y]+1;
                                    trace[i][j]=x;
                                }
                                if (f[i][j]==f[x][y]+1&&L[trace[i][j]]<=L[x])
                                    trace[i][j]=x;
                            }
                if (res<f[i][j]) {
                    save=i;
                    res=f[i][j];
                }
                if (res==f[i][j]&&L[save]<=L[i]) save=i;
            }
    cout << res << endl;
    meomeo(res,save,n);
}
pii Merge(pii l, pii r)
{
    if (l.fi>r.fi) return l;
    if (l.fi<r.fi) return r;
    if (L[l.se]<L[r.se]) return r;
    if (L[l.se]>L[r.se]) return l;
    return mp(l.fi,max(l.se,r.se));
}
void build(int id, int l, int r)
{
    if (l==r) {
        st[id]=adj[l];
        BIT[id].resize(st[id].size());
        return;
    }
    int mid=(l+r)>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    st[id].resize(st[id<<1].size()+st[id<<1|1].size());
    merge(st[id<<1].begin(),st[id<<1].end(),st[id<<1|1].begin(),st[id<<1|1].end(),st[id].begin());
    BIT[id].resize(st[id].size());
}
void updateBIT(int id, int x, int val, int pos)
{
    for (;x<=sz(BIT[id]); x+=x&-x) {
        pii &tmp=BIT[id][x-1];
        tmp=Merge(tmp,mp(val,pos));
    }
}
pii GetBIT(int id, int x)
{
    pii res=mp(0,0);
    for (;x;x-=x&-x) res=Merge(res,BIT[id][x-1]);
    return res;
}
pii Get(int id, int l, int r, int u, int v, int pos)
{
    if (l>v||r<u) return mp(0,0);
    if (u<=l&&r<=v) {
        int magic=upper_bound(st[id].begin(),st[id].end(),pos)-st[id].begin();
        //cerr << "a" << st[id][magic]-pos << endl;
        return GetBIT(id,magic);
    }
    int mid=(l+r)>>1;
    return Merge(Get(id<<1,l,mid,u,v,pos),Get(id<<1|1,mid+1,r,u,v,pos));
}
void update(int id, int l, int r, int u, int val, int pos, int meo)
{
    if (l>u||r<u) return;
    int magic=lower_bound(st[id].begin(),st[id].end(),pos)-st[id].begin()+1;
    updateBIT(id,magic,val,meo);
    if (l==r)
        return;
    int mid=(l+r)>>1;
    update(id<<1,l,mid,u,val,pos,meo); update(id<<1|1,mid+1,r,u,val,pos,meo);
}
void Task2()
{
    //nen
    int m=0;
    FOR(i,1,n)
        b[++m]=L[i],b[++m]=R[i];
    sort(b+1,b+1+m);
    m=unique(b+1,b+1+m)-b-1;
    FOR(i,1,n) L[i]=lower_bound(b+1,b+1+m,L[i])-b,R[i]=lower_bound(b+1,b+1+m,R[i])-b;
    int save=0,res=0;
    FOR(i,1,n) adj[R[i]].push_back(i);
    build(1,1,m);
    FOR(i,1,n) {
        FOR(j,1,n)
            if (L[i]==R[j]) {
                int val=b[L[i]];
                int l=lower_bound(b+1,b+1+m,val-lim)-b;
                int r=upper_bound(b+1,b+1+m,val+lim)-b-1;
                if (l>r) cerr <<"CaNocCanCap";
                pii tmp=Get(1,1,m,l,r,j-1);
                f[i][j]=tmp.fi+1;
                trace[i][j]=tmp.se;
                if (res<f[i][j]) {
                    save=i;
                    res=f[i][j];
                }
                if (res==f[i][j]&&L[save]<=L[i]) save=i;
            }
        FOR(j,1,n) if (L[i]==R[j])
            update(1,1,m,L[i],f[i][j],j,i);
    }
    FOR(i,1,n) L[i]=b[L[i]],R[i]=b[R[i]];
    cout << res << endl;
    meomeo(res,save,n);
}
int main()
{
    assign("LIONDANCE.inp","r",input);
    #ifndef meomeomeooooo
        assign("LIONDANCE.out","w",output);
    #endif // meomeomeooooo
    iostream::sync_with_stdio(false);
    cin.tie(0);
    Input();
    if (n<=100)
        Solve();
    else
        Task2();
//    #ifdef meomeomeooooo
//        cerr << endl;
//        Task2();
//    #endif // meomeomeooooo
    return 0;
}
