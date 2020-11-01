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

const int maxn=1e3+7;
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

int m,n,k;
int a[maxn],b[maxn];

inline void Enter(){
    cin>>m>>n>>k;
    up(i,1,m) cin>>a[i];
    up(i,1,n) cin>>b[i];
}

inline void Init(){
    sort(a+1,a+m+1);
    sort(b+1,b+n+1);
}

inline void Solve(){ /// thuat xam can test
    if(k<=m) up(i,1,k) cout<<a[i]<<' ';
    else{
        up(i,1,m) cout<<a[i]<<' ';
        k-=m;
        up(i,1,k) cout<<b[i]<<' ';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
//    #undef Kamisama
    #ifdef Kamisama
    #define task "SEQUENCE"
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    #endif // Kamisama
//

    Enter();
    Init();
    Solve();


    return 0;
}
