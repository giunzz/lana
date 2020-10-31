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


struct Circle{
	int x,y,z,r;
};

struct shop{
	int x,y,z,e;
};

const int M=2005,N=20;
int m,n,k;
Circle ball[M];
shop tea[N];

void enter(){
	cin>>m>>n>>k;

	ff(i,1,m){
		cin>>ball[i].x>>ball[i].y>>ball[i].z>>ball[i].r;
	}
	
	
	ff(i,1,n){
		cin>>tea[i].x>>tea[i].y>>tea[i].z>>tea[i].e;
	}

	int stx,sty,stz;
	cin>>stx>>sty>>stz;

	ff(i,1,m){
		ball[i].x-=stx;
		ball[i].y-=sty;
		ball[i].z-=stz;
	}

	ff(i,1,n){
		tea[i].x-=stx;
		tea[i].y-=sty;
		tea[i].z-=stz;
	}
}

bool Destroy[M];

bool Intersect(Circle p,shop q){
	int l1=0,r1=q.x;
	if (l1>r1) swap(l1,r1);

	int l2=p.x - p.r, r2= p.x + p.r;
	if (l1 > r2 || r1 < l2) return false ;
	if (l2 <= l1 && r1 <= r2) return false;
	return true;
}

void process(){
	ll ans=0;

	ff(mask,1,bit(n)){
		ff(i,1,m) Destroy[i]=0;

		ll cur=0;

		ff(i,1,n) if (bit(i-1) & mask){
			cur+=tea[i].e;

			ff(j,1,m) if (Intersect(ball[j],tea[i])) Destroy[j]=1;
		}

		int cnt=0;
		ff(i,1,m) if (Destroy[i]) ++cnt;
		// db(mask _ cnt);
		if (cnt<=k) ans=max(ans,cur);
	}
	cout<<ans<<endl;
}

int main(){
	// fast IO thi phai bo
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("teaworld.inp","r",stdin);
    freopen("teaworld.out","w",stdout);

    enter();
    process();

    return 0;
}