#include<bits/stdc++.h>
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=1e4+10;
int n,m,X,Y,U,V,t[12*N],mem[12*N],lim;
pii a[N],b[N],r;
bool cmp(pii u,pii v) {return u.se<v.se;}
void build(int s,int l,int r)
{
    if(l==r)
    {
        t[s]=Y-3;
        return;
    }
    int mid=(l+r)/2;
    build(2*s,l,mid);
    build(2*s+1,mid+1,r);
    t[s]=min(t[2*s],t[2*s+1]);
}
void trans(int s)
{
    if(mem[s]==lim) return;
    t[2*s]=max(t[2*s],mem[s]);
    mem[2*s]=max(mem[2*s],mem[s]);
    t[2*s+1]=max(t[2*s+1],mem[s]);
    mem[2*s+1]=max(mem[2*s+1],mem[s]);
    mem[s]=lim;
}
void update(int s,int l,int r,int u,int v,int x)
{
    if(v<l||r<u) return;
    if(l>=u&&r<=v)
    {
        t[s]=max(t[s],x);
        mem[s]=max(mem[s],x);
        return;
    }
    trans(s);
    int mid=(l+r)/2;
    update(2*s,l,mid,u,v,x);
    update(2*s+1,mid+1,r,u,v,x);
    t[s]=min(t[2*s],t[2*s+1]);
}
int get(int s,int l,int r,int u,int v)
{
    if(v<l||r<u) return 1e17;
    if(l>=u&&r<=v) return t[s];
    trans(s);
    int mid=(l+r)/2;
    return min(get(2*s,l,mid,u,v),get(2*s+1,mid+1,r,u,v));
}
vector<int> e;
int vt(int x)
{
    return lower_bound(e.begin(),e.end(),x)-e.begin()+1;
}
bool cheq(int x)
{
    e.clear();
    memset(mem,-127,sizeof(mem));
    lim=mem[1];
    e.pb(X);e.pb(X+1);e.pb(U);
    forinc(i,1,n)
    {
        e.pb(a[i].fi-x);
        e.pb(a[i].fi+x);
        e.pb(a[i].fi+x+1);
    }
    sort(e.begin(),e.end());
    int X1=vt(X),U1=vt(U);
    int _n=e.size();
    build(1,1,_n);
    forinc(i,1,n) if(a[i].se+x>=Y&&a[i].se-x<=V)
    {
        int l=max(X1,vt(a[i].fi-x));
        int r=min(U1,vt(a[i].fi+x));
        if(get(1,1,_n,l,r)<a[i].se-x-1) return 1;
        update(1,1,_n,l,r,a[i].se+x);
    }
    return (get(1,1,_n,X1,U1)<V);
}
void sub1()
{
    int kq=0;
    forinc(i,r.fi-m,r.fi+m)
    {
        int cl=m-abs(r.fi-i);
        //cout<<i<<" "<<cl<<endl;
        forinc(j,r.se-cl,r.se+cl)
        {
            int res=4e9;
            forinc(t,1,n) res=min(res,abs(i-b[t].fi)+abs(j-b[t].se));
            kq=max(kq,res);
            //if(res==13) cout<<i<<" "<<j<<" "<<endl;
        }
    }
    cout<<kq;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("ROBOTS.inp","r",stdin);
    freopen("ROBOTS.out","w",stdout);
    cin>>n>>m;
    forinc(i,1,n+1)
    {
        int x,y;
        cin>>x>>y;
        b[i]={x,y};
        a[i].fi=x+y;
        a[i].se=x-y;
    }
    r=b[n+1];
    if(m<=200) {sub1();return 0;}
    r=a[n+1];
    sort(a+1,a+n+1,cmp);
    X=r.fi-m,Y=r.se-m;
    U=r.fi+m,V=r.se+m;
    int l=0,r=6e9,kq;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(cheq(mid)) {kq=mid;l=mid+1;}
        else r=mid-1;
    }
    cout<<kq+1;
}
