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
const int maxn=3005;
int f[205][105][105];
int a[maxn],b[maxn];
int m,n,need;
void Input()
{
    cin >>m >> n >> need;
    FOR(i,1,m) cin >> a[i];
    FOR(i,1,n) cin >> b[i];
}
int calc(int i, int j, int k)
{
    if (i>need) return 1;
    int &res=f[i][j][k];
    if (res!=-1) return res;
    res=0;
    FOR(x,j,m) //c[i]=a[j]
        res|=calc(i+1,x+1,k);
    FOR(x,k,n)
        res|=calc(i+1,j,x+1);
    return res;
}
void trace(int i, int j, int k)
{
    if (i>need) return;
    int cur=1e9;
    pii pos=mp(0,0);
    FOR(x,j,m)
        if (calc(i+1,x+1,k)&&a[x]<cur) {
            pos=mp(x,0); cur=a[x];
        }
    FOR(x,k,n)
        if (calc(i+1,j,x+1)&&b[x]<cur) {
            pos=mp(x,1); cur=b[x];
        }
    cout << cur << ' ';
    if (pos.se)
        trace(i+1,j,pos.fi+1);
    else
        trace(i+1,pos.fi+1,k);
}
void Solve()
{
    fillchar(f,sizeof(f),255);
    trace(1,1,1);
}
int main()
{
    assign("SEQUENCE.inp","r",input);
    #ifndef meomeomeooooo
        assign("SEQUENCE.out","w",output);
    #endif // meomeomeooooo
    iostream::sync_with_stdio(false);
    cin.tie(0);
    Input();
    Solve();
    return 0;
}
