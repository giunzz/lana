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

const int INF=1e9+123;
int A,B;

void enter(){
	cin>>A>>B;
}

vector<int> factor(int x){
	vector<int> ret;
	int num=x;
	ff(i,2,sqrt(x)){
		while (num%i==0) {
			ret.push_back(i);
			num/=i;
		}
	}
	if (num>1) ret.push_back(num);
	return ret;
}

vector<int> Refine(vector<int> V){
	vector<int> ret;

	sort(V.begin(),V.end());
	map<int,int> M;
	rep(i,0,SZ(V)) ++M[V[i]];
	for(map<int,int>::iterator it=M.begin();it!=M.end();++it) 
		if ((it->Y)&1) ret.push_back(it->X); 
	return ret;
}

void process(){
	vector<int> prs_a,prs_b,prs;
	prs_a=factor(A);
	prs_b=factor(B);
	prs=prs_a;

	rep(i,0,SZ(prs_b)) prs.push_back(prs_b[i]);

	
	// rep(i,0,SZ(prs)) cout<<prs[i]<<' ';cout<<endl;

	prs=Refine(prs);

	// rep(i,0,SZ(prs)) cout<<prs[i]<<' ';cout<<endl;cout<<endl;

	ll aa=A,bb=B;

	rep(mask,0,bit(SZ(prs))){
		ll acur=1,bcur=1;
		rep(i,0,SZ(prs)) if (bit(i) & mask) acur*=prs[i];
		else bcur*=prs[i];
		if (acur + bcur < aa+bb) {
			aa=acur;
			bb=bcur;
		}
	}

	cout<<aa<<' '<<bb<<endl;
}

int main(){
	// fast IO thi phai bo
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("minsum.inp","r",stdin);
    freopen("minsum.out","w",stdout);

    int T;
    cin>>T;
    while (T--){
   		enter();
   	 	process();
	}

    return 0;
}
