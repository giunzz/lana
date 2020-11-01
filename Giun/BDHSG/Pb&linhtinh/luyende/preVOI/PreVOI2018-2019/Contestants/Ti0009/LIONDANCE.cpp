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
const int N=110;
int n,del,top,kq;
int a[N],b[N],x[N],ans[N],X[N],f[N][3*N],A[N],B[N],pos[3*N],tr[3*N],F[N][N][3*N];
struct aa{int i,j,t;};
aa pre[N][N][3*N],vt[N][N][3*N];
vi ad;
void ktra()
{
    int si=0,j=1; bool ok=false;
    forinc(i,1,n)
    {
        if (x[i])
        {
            if (f[j][A[i]]<=n && (!si||abs(pos[A[i]]-pos[X[si]]<=del))) X[++si]=A[i],j=f[j][A[i]]+1;
            else {ok=true; break;}
        }
    }
    if (!ok)
    {
        if (si>=top)
        {
            if (si==top)
            {
                forinc(i,1,si) if (ans[i]>X[i]) {ok=true; break;} else if (X[i]>ans[i]) break;
            }
            if (ok) return;
            top=si;
            forinc(i,1,si) ans[i]=X[i];
        }
    }
}
void duyet(int i)
{
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
void tv(int i, int j, int t)
{
    fordec(k,kq,1)
    {
        ans[k]=pos[t];
        aa tg=pre[i][j][t];
        i=tg.i,j=tg.j,t=tg.t;
    }
    forinc(k,1,kq) cout<<ans[k]<<" ";
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    cin>>n>>del;
    forinc(i,1,n) cin>>a[i],ad.pb(a[i]);
    forinc(i,1,n) cin>>b[i],ad.pb(b[i]);
    sort(all(ad)); ad.erase(unique(all(ad)),ad.end());
    forinc(i,1,n)
    {
        A[i]=lower_bound(all(ad),a[i])-ad.begin()+1; pos[A[i]]=a[i];
        B[i]=lower_bound(all(ad),b[i])-ad.begin()+1; pos[B[i]]=b[i];
    }
    int m=ad.size();
    fordec(i,n+1,1)
    {
        forinc(j,1,m)
        {
            if (j==B[i]) tr[j]=i;
            if (!tr[j]) tr[j]=n+1;
            f[i][j]=tr[j];
        }
    }
    if (n<=20)
    {
        duyet(1);
        cout<<top<<"\n";
        forinc(i,1,top) cout<<pos[ans[i]]<<" ";
    }
    else
    {
        memset(F,-1,sizeof(F));
        forinc(i,1,n)
        {
            int j=f[1][A[i]];
            F[i][j][A[i]]=1; vt[i][j][A[i]]={i,j,A[i]};
        }
        forinc(i,1,n-1) forinc(j,1,n) forinc(t,1,m) if (F[i][j][t]!=-1)
        {
            if (F[i+1][j][t]<F[i][j][t])
            {
                F[i+1][j][t]=F[i][j][t];
                vt[i+1][j][t]=vt[i][j][t];
            }
            int _j=f[j+1][A[i+1]];
            if (_j<=n && abs(pos[A[i+1]]-pos[t])<=del && F[i+1][_j][A[i+1]]<F[i][j][t]+1)
            {
                pre[i+1][_j][A[i+1]]=vt[i][j][t]; vt[i+1][_j][A[i+1]]={i+1,_j,A[i+1]};
                F[i+1][_j][A[i+1]]=F[i][j][t]+1;
            }
        }
        forinc(i,1,n) forinc(j,1,n) forinc(t,1,m) kq=max(kq,F[i][j][t]);
        cout<<kq<<"\n";
        forinc(i,1,n) forinc(j,1,n) forinc(t,1,m) if (kq==F[i][j][t]){tv(i,j,t); return 0;}
    }
}

