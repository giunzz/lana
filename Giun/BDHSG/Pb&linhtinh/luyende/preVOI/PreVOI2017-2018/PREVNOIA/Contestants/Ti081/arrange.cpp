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

const int N = 1e5 + 7;

int n, a[N];
long long sum, Avg, res;
bool flag, cc;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("arrange.inp", "r", stdin);
	freopen("arrange.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++){
		read(a[i]);
		sum += a[i];
		if (a[i] % n != 0){
			cc = true;
		}
	}
	Avg = sum / n;
	if (sum % n == 0)
		flag = true;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j < i; j++)
			while (a[j] < Avg && a[i] > Avg){
				if (a[i] == Avg + 1 && !flag) break;
				res += abs(i - j);
				a[j]++;
				a[i]--;
			}
	}
	for (int i = n; i >= 1; i--){
		for (int j = n; j > i; j--)
			while (a[j] < Avg && a[i] > Avg){
				if (a[i] == Avg + 1 && !flag) break;
				res += abs(i - j);
				a[j]++;
				a[i]--;
			}
	}
	for (int i = 1; i <= n; i++)
		if (a[i] < Avg){
			int L = -1, R = -1;
			for (int j = i - 1; j >= 1; j--)
				if (a[j] > Avg){
					L = j;
					break;
				}
			for (int j = i + 1; j <= n; j++)
				if (a[j] > Avg){
					R = j;
					break;
				}
			if (L == -1){
				a[R]--;
				a[i]++;
				res++;
				continue;
			}
			if (R == -1){
				a[L]--;
				a[i]++;
				res++;
				continue;
			}
			if (L != -1 && R != -1){
				if (i - L + 1 > R - i + 1){
					a[R]--;
					a[i]++;
					res++;
				}
				else{
					a[L]--;
					a[i]++;
					res++;
				}
			}
		}
	// for (int i = 1; i <= n; i++)
	// 	write(a[i]);
	for (int i = 1; i <= n; i++){
		a[i] -= Avg;
		if (a[i] > 0)
			res += ((a[i] - 2) * (a[i] - 1)) / 2;
	}
	writeln(res);
}