#include <bits/stdc++.h>
#define forr(i,a,b) for( int i=(a);i<=(b);++i)
#define ford(i,a,b) for( int i=(a);i>=(b);--i)
#define f first
#define s second
#define ll long long
#define pii pair<int,int>
#define task "ARRANGE"

using namespace std;

const long long mod=1e14+7;
const long dad=2e6 ;
int n,a[dad],k,dem1,dem2,id,l,mn=mod,mx,kt[dad],r;
ll ans;
pii b[dad] ;
vector<int> p[dad] ;
bool kk;

int getint()
{
   int ww = 0; char cc = getchar();
   while (cc > '9' || cc < '0') cc = getchar();
   while (cc >= '0' && cc <= '9') { ww = ww * 10 + cc - '0'; cc = getchar(); }
   return ww;
}

ll getll()
{
   ll ww = 0; char cc = getchar();
   while (cc > '9' || cc < '0') cc = getchar();
   while (cc >= '0' && cc <= '9') { ww = ww * 10 + cc - '0'; cc = getchar(); }
   return ww;
}

int getbit(int bit,int id)
{
    return bit>>id&1;
}

void build(int mn,int mx)
{
    k=dem1=dem2=0;
    b[0]={-1,-1};
    for(auto v:p[mn])
    if (a[v]==mn) b[++k]={v,0},++dem1;
    for(auto v:p[mx])
    if (a[v]==mx) b[++k]={v,1},++dem2;
    sort(b+1,b+k+1);
    id=dem1>dem2?1:0;
    forr(i,1,k) kt[i]=0;
    forr(i,1,k)
    if (b[i].s==id)
    {
        l=i;r=i;
        while (l>=1&&(kt[l]==1||b[l].s==id)) --l;
        while (r<=k&&(kt[r]==1||b[r].s==id)) ++r;
        if (l==0) l=r;else
        if (r!=k+1)
        {
            l=b[i].f-b[l].f<b[r].f-b[i].f?l:r;
        }
        kt[l]=1;
        ans=(ll)ans+abs(b[i].f-b[l].f);
        a[b[i].f]+=id==0?1:-1;
        a[b[l].f]+=id==0?-1:1;
        p[a[b[i].f]].push_back(b[i].f);
        p[a[b[l].f]].push_back(b[l].f);
    }
//    forr(i,1,n) cout<< a[i] << " ";
//    cout<< endl;
}

void check(int mn,int mx)
{
    if (mx==mn+1) return;
    build(mn,mx);
    if (dem1==dem2) check(mn+1,mx-1);else
    if (id==0) check(mn+1,mx);else check(mn,mx-1);
}


void input()
{
    n=getint();
    if (n==1||n==0)
    {
        cout<< 0;
        return ;
    }
    forr(i,1,n)
    {
        a[i]=getint();
        if (a[i]%n!=0) kk=1;
    }
    if (kk==0)
        forr(i,1,n) a[i]/=n;
    forr(i,1,n)
    {
        mn=min(mn,a[i]);
        mx=max(mx,a[i]);
        p[a[i]].push_back(i);
    }
    check(mn,mx);
    if (kk==0)
    {
        if (ans==0)
        {
            cout<< n/2;
        }else cout<< ans*n;
    }else cout<< ans;
}

void output()
{

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen( task".inp" , "r" , stdin );
    freopen( task".out" , "w" , stdout );
    input();
    output();
    return 0;
}
