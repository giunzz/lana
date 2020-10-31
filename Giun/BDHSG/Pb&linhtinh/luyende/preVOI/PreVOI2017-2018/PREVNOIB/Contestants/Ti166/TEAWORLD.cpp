#include <bits/stdc++.h>
#define forr(i,a,b) for( int i=(a);i<=(b);++i)
#define ford(i,a,b) for( int i=(a);i>=(b);--i)
#define f first
#define s second
#define ll double
#define pii pair<int,int>
#define task "TEAWORLD"

using namespace std;

const long long mod=1e9+7;
const long dad=5000 ;
struct yasu
{
    ll x,y,z,t;
}a[dad],b[dad];
int n,m,k,kk[dad] ;
ll ans;
bool kt=0,kt1=0;

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

bool getget(int u,int v)
{
    return (b[u].x-a[v].x)*(b[u].x-a[v].x)+(b[u].y-a[v].y)*(b[u].y-a[v].y)<=(a[v].t*a[v].t);
}

bool check(int u,int v,int z)
{
    ll dem1=getget(u,z);
    ll dem2=getget(v,z);
    if (dem1&&dem2) return 0;
    if ((dem1&&!dem2)||(!dem1&&dem2)) return 1;
    ll a1=b[v].y-b[u].y;
    ll b1=b[u].x-b[v].x;
    ll c1=-b[u].x*(a1)+b[u].y*-b1;
    ll a2=-b1;
    ll b2=a1;
    ll c2=-a2*a[z].x-b2*a[z].y;
    ll y1=(-a2*c1+a1*c2)/(a2*b1-a1*b2);
    ll x1=(-b1*y1-c1)/a1;
    return (a[z].x-x1)*(a[z].x-x1)+(a[z].y-y1)*(a[z].y-y1)<(a[z].t*a[z].t);
}


ll buil(int bit)
{
    ll res=0;int k1=0;
    forr(i,1,n) kk[i]=0;
    forr(i,1,m)
    if (getbit(bit,i-1))
    {
        res+=b[i].t;
        forr(j,1,n)
        if (kk[j]==0&&check(i,m+1,j))
        {
            ++k1;
            kk[j]=1;
        }
    }
    if (k1<=k) return res;
    else return 0;
}

void buffalo()
{
    forr(bit,1,(1<<m)-1)
    {
        ans=max(ans,buil(bit));
    }
    cout<< ans;
}

bool check1(int u,int v,int z)
{
    int u1=min(b[u].x,b[v].x);
    int v1=max(b[u].x,b[v].x);
    if (u1<=a[z].x&&a[z].x<=v1&&(a[z].t<a[z].x-u1||a[z].t<v1-a[z].x)) return 1;
    return 0;
}

ll buil1(int bit)
{
    ll res=0;int k1=0;
    forr(i,1,n) kk[i]=0;
    forr(i,1,m)
    if (getbit(bit,i-1))
    {
        res+=b[i].t;
        forr(j,1,n)
        if (kk[j]==0&&check1(i,m+1,j))
        {
            ++k1;
            kk[j]=1;
        }
    }
    if (k1<=k) return res;
    else return 0;
}

void cow()
{
    forr(i,1,m) ans+=b[i].t;
    cout<< ans ;
}

void low()
{
    forr(bit,1,(1<<m)-1)
    {
        ans=max(ans,buil1(bit));
    }
    cout<< ans;
}


void input()
{
    cin>>n>>m>>k;
    forr(i,1,n)
    {
        cin>>a[i].x;
        cin>>a[i].y;
        cin>>a[i].z;
        cin>>a[i].t;
        if (a[i].y==0) kt1=1;
        if (a[i].z!=0) kt=1;
    }
    forr(i,1,m+1)
    {
        cin>>b[i].x;
        cin>>b[i].y;
        cin>>b[i].z;
        cin>>b[i].t;
        if (b[i].y==0) kt1=1;
        if (b[i].z!=0) kt=1;
    }
    if (kt1==1) low();else
    if (kt) cow();
    else buffalo();
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
