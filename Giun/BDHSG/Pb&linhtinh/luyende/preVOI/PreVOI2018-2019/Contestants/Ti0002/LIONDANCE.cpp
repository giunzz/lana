#include <bits/stdc++.h>
inline int in()
{
    int x=0;char c=getchar();bool neg=0;
    while(('0'>c||c>'9') && c!='-') c=getchar();
    if(c=='-') neg=1,c=getchar();
    while('0'<=c&&c<='9') x=10*x+c-'0',c=getchar();
    if(neg) x=-x;
    return x;
}
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}
#define task "LIONDANCE"
#define forinc(a,b,c) for(int a=b,__key=c;a<=__key;++a)
#define fordec(a,b,c) for(int a=b,__key=c;a>=__key;--a)
#define forv(a,b) for(auto&a:b)
#define ii pair<int,int>
#define i3 pair<int,ii>
#define fi first
#define se second
#define nd second.first
#define rd second.second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define mt make_tuple
#define bit(x,i) ((x>>(i-1))&1)
#define on(x,i) (x|(1<<(i-1)))
#define off(x,i) (x&~(1<<(i-1)))
#define reset(f,x) memset(f,x,sizeof(f))
#define all(a) a.begin(),a.end()
#define max(a,b) ((a)>(b)?(a):(b))
const int N=4010;
int n,k;
int a[N],b[N],c[N],d[N],cx[N],cy[N];
int f[N][N],nx[N][N],ny[N][N];
vi v,val;
vii sf[2*N];
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    n=in(),k=in();
    forinc(i,1,n) a[i]=in(),v.pb(a[i]);
    forinc(i,1,n) b[i]=in(),v.pb(b[i]);
    sort(all(v)),v.erase(unique(all(v)),v.end());
    forinc(i,1,n) c[i]=lower_bound(all(v),a[i])-v.begin()+1,
                  val.pb(c[i]),
                  d[i]=lower_bound(all(v),b[i])-v.begin()+1;
    forinc(x,1,v.size()) cx[x]=cy[x]=n+1;
    fordec(i,n,1)
    {
        cx[c[i]]=i,cy[d[i]]=i;
        forinc(j,1,v.size()) nx[i][j]=cx[j];
        forinc(j,1,v.size()) ny[i][j]=cy[j];
    }
    fordec(i,n,1) fordec(j,n,1)
    {
        if(c[i]==d[j])
        {
            int best=0;
            int down=lower_bound(all(v),a[i]-k)-v.begin()+1;
            int up  =upper_bound(all(v),a[i]+k)-v.begin();
            forinc(t,down,up)
                forv(w,sf[t]) if(w.fi>i && w.se>j) best=max(best,f[w.fi][w.se]);
            f[i][j]=best+1;
            sf[c[i]].pb({i,j});
        }
        else f[i][j]=max(f[i+1][j],f[i][j+1]);
    }
    int kq=f[1][1],l=1,r=1,last=-1;
    cout<<kq<<"\n";
    sort(all(val),greater<int>());
    while(kq--)
    {
        int i=0;
        forv(x,val)
        {
            if((last==-1 || abs(v[x-1]-last)<=k) && nx[l][x]<=n && ny[r][x]<=n && f[nx[l][x]+1][ny[r][x]+1]+1>=f[l][r])
            {
                i=x;
                break;
            }
        }
        cout<<v[i-1]<<" ";
        l=nx[l][i]+1,r=ny[r][i]+1;
    }
}


