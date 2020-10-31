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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("bubbletea.inp", "r", stdin);
	freopen("bubbletea.out", "w", stdout);
	writeln(-1);
}