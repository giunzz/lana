#include <bits/stdc++.h>
using namespace std;
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define rep(i, a, b) for(int i = (a), _b = (b); i < _b; ++i)
#define fd(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define SZ(x) ((int)(x).size())
#define db(x) cout << #x << " == " << x << endl
#define _ << ", " <<
#define X first
#define Y second
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define endl '\n'
#define pc putchar
#define gc getchar
#define bit(i) (1<<(i))
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
inline void read(int &x){register int c = gc();x = 0;int neg = 0;for (;((c<48 || c>57) && c != '-') ;c = gc());if(c=='-') {neg=1;c=gc();}for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}if(neg) x=-x;}
inline void write(int x){char buffor[12];register int i=0;int neg=0; if (x<0) {neg=1; x= -x;}do{buffor[i++]=(x%10)+'0';x/=10;} while(x);i--;if (neg) pc('-');while(i>=0) pc(buffor[i--]);}
inline void writeln(int x){write(x); pc('\n');}
inline void read(ll &x){register int c = gc();x = 0;int neg = 0;for (;((c<48 || c>57) && c != '-') ;c = gc());if(c=='-') {neg=1;c=gc();}for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}if(neg) x=-x;}
inline void write(ll x){char buffor[21];register int i=0;int neg=0; if (x<0) {neg=1; x= -x;}do{buffor[i++]=(x%10)+'0';x/=10;} while(x);i--;if (neg) pc('-');while(i>=0) pc(buffor[i--]);}
inline void writeln(ll x){write(x); pc('\n');}

const ll INF=1e18;
const int N=1e6+5;
int n,a[N],k;

void enter(){
	cin>>n>>k;
	ff(i,1,n) cin>>a[i];
}

ll sum[N];
ll pre[N],suf[N];

ll get(int lo,int hi){return sum[hi]-sum[lo-1]; }

void process(){
	ff(i,1,n) sum[i]=sum[i-1]+a[i];

	ff(i,1,n) {
		if (i<k) pre[i]=0;
		else pre[i]=max(pre[i-1],get(i-k+1,i));
	}
	
	fd(i,n,1){
		if (n-i+1<k) suf[i]=0;
		else suf[i]=max(suf[i+1],get(i,i+k-1));
	}

	ll ans=INF;
	ff(i,1,n-k+1){
		ans=min(ans,max(pre[i-1],suf[i+k]));
	}
	cout<<ans<<endl;
	// ff(i,1,n) cout<<pre[i]<<' '; cout<<endl;
	// ff(i,1,n) cout<<suf[i]<<' ';cout<<endl;
}

int main(){
	// fast IO thi phai bo
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("gifts.inp","r",stdin);
    freopen("gifts.out","w",stdout);

    enter();
    process();

    return 0;
}