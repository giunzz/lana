#include <bits/stdc++.h>
#define ii pair <int, int>
#define x first
#define y second
#define db(x) cerr << #x << " = " << x << endl;

using namespace std;

inline void read(int &x){register int c = getchar();x = 0; int neg = 0;for (;((c<48 || c>57) && c != '-') ;c = getchar());if(c=='-') {neg=1;c=getchar();}for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}if(neg) x=-x;}
inline void read(long long &x){register int c = getchar();x = 0; int neg = 0;for (;((c<48 || c>57) && c != '-') ;c = getchar());if(c=='-') {neg=1;c=getchar();}for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}if(neg) x=-x;}
inline void writeln(long long x){char buffor[21];register int i=0;int neg=0; if (x<0) {neg=1; x= -x;}do{buffor[i++]=(x%10)+'0';x/=10;} while(x);i--;if (neg) putchar('-');while(i>=0) putchar(buffor[i--]);putchar('\n');}
inline void write(long long x){char buffor[21];register int i=0;int neg=0; if (x<0) {neg=1; x= -x;}do{buffor[i++]=(x%10)+'0';x/=10;} while(x);i--;if (neg) putchar('-');while(i>=0) putchar(buffor[i--]);putchar(' ');}

const int X = 1e5;
const int N = 1e5 + 7;
const long long oo = 1e18;

bool prime[N], dd[N];
int A, B, ga, gb, g;
int dema[N], pta[N], demb[N], ptb[N], a[N];
long long resA, resB;
vector <int> p;

inline void sieve(){
	memset(prime, true, sizeof(prime));
	prime[1] = false;
	for (int i = 2; i <= trunc(sqrt(X)); i++)
		if (prime[i])
			for (int j = i; j <= X / i; j++)
				prime[i * j] = false;
	for (int i = 2; i < X; i++)
		if (prime[i])
			p.push_back(i);
}

inline void check(){
	long long curA = 1, curB = 1;
	for (int i = 1; i <= g; i++)
		if (dd[i])
			curA *= a[i];
		else
			curB *= a[i];
	if (curA + curB < resA + resB){
		resA = curA;
		resB = curB;
	}
}

void backtrack(int id){
	for (int i = 0; i <= 1; i++){
		dd[id] = i;
		if (id < g)
			backtrack(id + 1);
		else
			check();
	}
}

inline void solve(){
	read(A); read(B);
	int GCD = __gcd(A, B);
	A /= GCD; B /= GCD;
	ga = 0; gb = 0;
	for (int x: p){
		if (A < x) break;
		if (A % x == 0){
			pta[++ga] = x;
			dema[ga] = 0;
			while (A % x == 0){
				dema[ga]++;
				A /= x;
			}
		}
	}
	if (A != 1) {
		pta[++ga] = A;
		dema[ga] = 1;
	}
	for (int x: p){
		if (B < x) break;
		if (B % x == 0){
			ptb[++gb] = x;
			demb[gb] = 0;
			while (B % x == 0){
				demb[gb]++;
				B /= x;
			}
		}
	}
	if (B != 1) {
		ptb[++gb] = B;
		demb[gb] = 1;
	}
	for (int i = 1; i <= ga; i++) dema[i] %= 2;
	for (int i = 1; i <= gb; i++) demb[i] %= 2;
	g = 0;
	for (int i = 1; i <= ga; i++)
		if (dema[i])
			a[++g] = pta[i];
	for (int i = 1; i <= gb; i++)
		if (demb[i])
			a[++g] = ptb[i];
	resA = resB = oo;
	backtrack(1);
	write(resA); writeln(resB);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("minsum.inp", "r", stdin);
	freopen("minsum.out", "w", stdout);
	int Test;
	read(Test);
	sieve();
	for (int i = 1; i <= Test; i++){
		solve();
	}
}