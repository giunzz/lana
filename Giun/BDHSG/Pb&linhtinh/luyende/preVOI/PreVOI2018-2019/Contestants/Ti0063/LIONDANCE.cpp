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
const ll linf=1e17+7;
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

int n,delta;
int a[maxn],b[maxn],f[maxn][maxn],id1[maxn],id2[maxn];
vector<int> trace[maxn][maxn];

inline void Enter(){
    Read(n); Read(delta);
    up(i,1,n) Read(a[i]);
    up(i,1,n) Read(b[i]);
}

inline void Init(){
    up(i,1,n){
        down(j,i-1,1) if(abs(a[i]-a[j])<=delta){
            id1[i]=j;
            break;
        }
    }

    up(i,1,n){
        down(j,i-1,1) if(abs(b[i]-b[j])<=delta){
            id2[i]=j;
            break;
        }
    }

    up(i,1,n){
        up(j,1,n){
            if(a[i]!=b[j]){
                if(f[i-1][j]>f[i][j-1]) f[i][j]=f[i-1][j],trace[i][j]=trace[i-1][j];
                else if(f[i-1][j]<f[i][j-1]) f[i][j]=f[i][j-1],trace[i][j]=trace[i][j-1];
                else f[i][j]=f[i-1][j],trace[i][j]=max(trace[i][j-1],trace[i-1][j]);
                if(f[i][j]<f[i-1][j-1]) f[i][j]=f[i-1][j-1],trace[i][j]=trace[i-1][j-1];
                else if(f[i][j]==f[i-1][j-1]) trace[i][j]=max(trace[i][j],trace[i][j]);
                continue;
            }
            if(f[i-1][j]>f[i][j-1]) f[i][j]=f[i-1][j],trace[i][j]=trace[i-1][j];
            else if(f[i-1][j]<f[i][j-1]) f[i][j]=f[i][j-1],trace[i][j]=trace[i][j-1];
            else if(f[i-1][j]==f[i][j-1]) trace[i][j]=max(trace[i-1][j],trace[i][j-1]);
            int k1,k2;
            k1=id1[i];
            k2=id2[j];
            if(f[i][j]<f[k1][k2]+1)
                f[i][j]=f[k1][k2]+1,trace[i][j]=trace[k1][k2],trace[i][j].pb(a[i]);
            else trace[i][j]=max(trace[i][j],trace[k1][k2]);
        }
    }
}

inline void Solve(){
    Write(f[n][n]); putchar('\n');
    for(int x: trace[n][n]) Write(x),putchar(' ');
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
//    #undef Kamisama
    #ifdef Kamisama
    #define task "LIONDANCE"
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    #endif // Kamisama
//

    Enter();
    Init();
    Solve();


    return 0;
}
