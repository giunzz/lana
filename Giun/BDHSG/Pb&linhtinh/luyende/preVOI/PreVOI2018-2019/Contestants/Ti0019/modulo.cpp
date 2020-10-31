#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(v,a) for(auto&v:a)
#define batbit(i,a) (a|(1<<(i-1)))
#define tatbit(i,a) (a&~(1<<(i-1)))
#define getbit(i,a) ((a>>(i-1))&1)
#define pii pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define vii vector<pii>
#define pb push_back
#define all(a) a.begin(),a.end()
#define int long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int ran(int l, int r) {return l+rng()%(r-l+1);}
const int N=50;
int a,b,n,k,tg,m;
int x[N],pw[N];
bool ok;
map<int,int> dd;
void ktra()
{
    int A=0;
    forinc(i,1,n)
    {
        if (x[i]) A=A*10+a;
        else A=A*10+b;
    }
    if (A%tg==k) cout<<A,ok=true;
}
void duyet(int i)
{
    if (ok) return;
    if (i==n+1) ktra();
    else
    {
        forinc(j,0,1)
        {
            x[i]=j;
            duyet(i+1);
        }
    }
}
void duyet1(int i)
{
    if (i==m+1)
    {
        int A=0;
        forinc(j,1,m) if (x[j]) A=A*10+a; else A=A*10+b;
        int res=(A*pw[n-m])%tg;
        if (!dd[res]) dd[res]=A;
    }
    else
    {
        forinc(j,0,1)
        {
            x[i]=j;
            duyet1(i+1);
        }
    }
}
void duyet2(int i)
{
    if (ok) return;
    if (i==n+1)
    {
        int A=0;
        forinc(j,m+1,n) if (x[j]) A=A*10+a; else A=A*10+b;
        forv(v,dd) if ((v.fi+A%tg)%tg==k) {cout<<v.se<<A,ok=true; break;}
    }
    else
    {
        forinc(j,0,1)
        {
            x[i]=j;
            duyet2(i+1);
        }
    }
}
 main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    cin>>a>>b>>n>>k; tg=(1<<n);
    pw[0]=1;
    forinc(i,1,n) pw[i]=pw[i-1]*10;
    if (n<=20) duyet(1);
    else
    {
        m=n/2;
        duyet1(1);
        duyet2(m+1);
    }
}
