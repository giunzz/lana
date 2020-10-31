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

const int N=1e6+5;
const ll INF=1e18;

int n;
ll a[N];

void enter(){
	cin>>n;
	ff(i,1,n) cin>>a[i];
}

ll sub1(int aver,int lo,int hi){
	ll ans=0;

	ll s=0;

	ff(i,1,n){
		ans+=abs(s);
		if (i>=lo && i<=hi) {
			s+=a[i]-(aver+1);
		}
		else s+=a[i]-aver;
	}
	// db(s);
	return ans;
}

void sub2(int trail,int aver){
	ll ans=INF;
	ff(i,1,n-trail+1) {
		// db(i _ i+trail-1 _ sub1(aver,i,i+trail-1));
		ans=min(ans,sub1(aver,i,i+trail-1));
	}

	cout<<ans<<endl;  
}

void process(){
	ll s=0;
	ff(i,1,n) s+=a[i];

	int trail=s % n,aver=s/n;
	
	// db(trail _ aver);

	if (trail==0){ 
		cout<<sub1(aver,-1,-1)<<endl;
	}
	else {
		sub2(trail,aver);
	}
}

int main(){
	// fast IO thi phai bo
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("arrange.inp","r",stdin);
    freopen("arrange.out","w",stdout);

    enter();
    process();

    return 0;
}