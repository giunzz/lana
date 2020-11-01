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
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int ran(int l, int r) {return l+rng()%(r-l+1);}
int re(){int x=0; char c; bool neg=false;while (c!='-' && (c<'0'||'9'<c)) c=getchar();if (c=='-') neg=true,c=getchar();while ('0'<=c && c<='9'){x=x*10+c-'0';c=getchar();}if (neg) x=-x;return x;}
const int N=3010;
int n,m,k,mi;
int a[N],b[N],da[N],db[N];
string f[210][110][110];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    cin>>n>>m>>k; mi=3001;
    forinc(i,1,n) cin>>a[i],da[a[i]]++,mi=min(mi,a[i]);
    forinc(i,1,m) cin>>b[i],db[b[i]]++,mi=min(mi,b[i]);
    if (da[mi]+db[mi]>=k)
    {
        forinc(i,1,k) cout<<mi<<" ";
        return 0;
    }
    forinc(i,0,k) forinc(t1,0,n) forinc(t2,0,m) f[i][t1][t2]="A"; f[0][0][0]="0";
    forinc(i,0,k) forinc(t1,0,n) forinc(t2,0,m) if (f[i][t1][t2]!="A")
    {
        if (t1<n && t2<m) f[i][t1+1][t2+1]=min(f[i][t1+1][t2+1],f[i][t1][t2]);
        if (t2<m)
        {
            f[i][t1][t2+1]=min(f[i][t1][t2+1],f[i][t1][t2]);
            if (f[i+1][t1][t2+1]=="A") f[i+1][t1][t2+1]=f[i][t1][t2]+char(b[t2+1]+'0');
            else f[i+1][t1][t2+1]=min(f[i+1][t1][t2+1],f[i][t1][t2]+char(b[t2+1]+'0'));
        }
        if (t1<n)
        {
            f[i][t1+1][t2]=min(f[i][t1+1][t2],f[i][t1][t2]);
            if (f[i+1][t1+1][t2]=="A") f[i+1][t1+1][t2]=f[i][t1][t2]+char(a[t1+1]+'0');
            else f[i+1][t1+1][t2]=min(f[i+1][t1+1][t2],f[i][t1][t2]+char(a[t1+1]+'0'));
        }
    }
    forinc(i,1,k) cout<<f[k][n][m][i]<<" ";
}

