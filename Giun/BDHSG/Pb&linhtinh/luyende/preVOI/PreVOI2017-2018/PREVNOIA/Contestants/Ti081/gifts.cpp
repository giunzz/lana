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

const int N = 1e6 + 7;
const int LOG = log2(N) + 2;
const long long oo = 1e18 + 7;

int n, k, a[N];
long long pre[N], mx[N][LOG + 3], res;

long long rmq(int l, int r){
	int LOG2 = log2(r - l + 1);
	return max(mx[l][LOG2], mx[r - (1 << LOG2) + 1][LOG2]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("gifts.inp", "r", stdin);
	freopen("gifts.out", "w", stdout);
	read(n); read(k);
	for (int i = 1; i <= n; i++){
		read(a[i]);
		pre[i] = pre[i - 1] + a[i];
	}
	for (int i = 1; i < k; i++)
		mx[i][0] = -oo;
	for (int i = k; i <= n; i++)
		mx[i][0] = pre[i] - pre[i - k];
	for (int j = 1; j <= LOG; j++)
		for (int i = 1; i + (1 << (j - 1)) - 1 <= n; i++)
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
	res = oo;
	for (int l = 1; l + k - 1 <= n; l++){
		int r = l + k - 1;
		long long cur = 0;
		if (l - 1 >= k)
			cur = max(cur, rmq(1, l - 1));
		if (n - r >= k)
			cur = max(cur, rmq(r + k, n));
		res = min(res, cur);
	}
	writeln(res);
}