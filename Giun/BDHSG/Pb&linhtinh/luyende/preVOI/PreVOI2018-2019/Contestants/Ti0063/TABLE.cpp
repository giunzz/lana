#include <bits/stdc++.h>
#include <unordered_map>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define UP(i,a,b) for(i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define self (*this)
#define pb push_back
#define CL(x) x<<1
#define CR(x) x<<1|1
#define All(x) x.begin(),x.end()
#define CntBit(x) __builtin_popcount(x)
#define GetBit(x,k) (((x)>>(k))&1)
#define OffBit(x,k) ((x)&(~(1<<(k))))
#define x first
#define y second
#define Kamisama

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const int maxn=3e2+7;
const int maxm=4e4+7;
const int hashTableMod=1e7+7;
const ll mod=1e9+7;
const int inf=1e9+7;
const ll linf=1e16+7;
const double esp=1e-7;
const double pi=acos(-1);

template<typename T> inline void Read(T &x){
    register char c;
    bool neg=false;
    for(c=getchar();c<'0'||c>'9';c=getchar()) if(c=='-') neg=true;
    for(x=0;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
    if(neg) x=-x;
}

template<typename T> inline void Write(T x){
    if(x<0) putchar('-'), x=-x;
    if(x>9) Write(x/10);
    putchar(x%10+'0');
}

int m,n,nTest;
int a[maxn][maxn];
ll f[maxn][maxn];

inline void Enter(){
    Read(m); Read(n); Read(nTest);
    up(i,1,m) up(j,1,n) Read(a[i][j]);
}

inline void Init(){

}

inline void Solve(){
    while(nTest--){
        int u,v,p,q;
        Read(u); Read(v); Read(p); Read(q);
        f[u][v]=a[u][v];
        ll res=linf;
        up(i,u,p){
            up(j,v,q){
                if(i==u && j==v) continue;
                if(i==p && j==q) continue;
                f[u][v]=a[u][v];
                up(x,u,p){
                    up(y,v,q){
                        if(x==u && y==v) continue;
                        if(x==i && y==j) continue;
                        f[x][y]=max(f[x-1][y],f[x][y-1])+a[x][y];
                    }
                }
                res=min(res,f[p][q]);
                memset(f,0,sizeof(f));
            }
        }
        Write(res); putchar('\n');
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
//    #undef Kamisama
    #ifdef Kamisama
    #define task "TABLE"
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    #endif // Kamisama
//

    Enter();
    Init();
    Solve();


    return 0;
}
