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
//const ll mod=1e9+7;
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

int a,b,n,bit[maxn],cnt;
pii res;
unordered_map<ll,int> d;
vector<ll> d1,d2;
ll k,mod,p10;

inline void Enter(){
    cin>>a>>b;
    cin>>n>>k;
}

inline ll Mul(const int &x, const int &y){
    if(y==0) return 0;
    ll res=Mul(x,y/2);
    res=(res+res)&(mod-1);
    if(y&1) return (res+x)&(mod-1);
    return res;
}

inline void Init(){
    mod=(1ll<<n);
    p10=1;
    up(i,1,n-n/2) p10=Mul(p10,10);
}

inline void Try1(const int &pos){
    if(pos>n/2){
        ll rem=0;
        ll p=p10;
        down(i,n/2,1){
            rem=(rem+Mul(bit[i],p))&(mod-1);
            p=Mul(p,10);
        }
        d1.pb(rem);
        return;
    }
    bit[pos]=a,Try1(pos+1);
    bit[pos]=b,Try1(pos+1);
}

inline void Try2(const int &pos){
    if(pos>n){
        ll rem=0;
        ll p=1;
        down(i,n,n/2+1){
            rem=(rem+Mul(bit[i],p))&(mod-1);
            p=Mul(p,10);
        }
        d2.pb(rem);
        return;
    }
    bit[pos]=a,Try2(pos+1);
    bit[pos]=b,Try2(pos+1);
}

inline void Trace1(const int &pos){
    if(cnt>res.x) return;
    if(pos>n/2){
        cnt++;
        if(cnt==res.x) down(i,n/2,1) cout<<bit[i];
        return;
    }
    bit[pos]=a,Trace1(pos+1);
    bit[pos]=b,Trace1(pos+1);
}

inline void Trace2(const int &pos){
    if(cnt>res.y) return;
    if(pos>n){
        cnt++;
        if(cnt==res.y) down(i,n,n/2+1) cout<<bit[i];
        return;
    }
    bit[pos]=a,Trace2(pos+1);
    bit[pos]=b,Trace2(pos+1);
}

inline void Solve(){
    Try1(1);
    Try2(n/2+1);
    rep(i,0,d1.size()) if(d[d1[i]]==0) d[d1[i]]=i+1;
    res=pii(-1,-1);
    rep(i,0,d2.size()){
        if(k==0 && d[mod-d2[i]]!=0){
            res=pii(d[mod-d2[i]],i+1);
            break;
        }
        if(d[k-d2[i]]!=0){
            res=pii(d[k-d2[i]],i+1);
            break;
        }
    }
    if(res.x!=-1){
        cnt=0;
        Trace1(1);
        cnt=0;
        Trace2(n/2+1);
    }
    else cout<<-1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
//    #undef Kamisama
    #ifdef Kamisama
    #define task "MODULO"
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    #endif // Kamisama
//

    Enter();
    if(n<=40){
        Init();
        Solve();
    } else cout<<-1;

    return 0;
}
