#include <bits/stdc++.h>
#define ii pair <long long, long long>
#define x first
#define y second
#define db(x) cerr << #x << " = " << x << endl;
#define sqr(x) (1LL * (x) * (x))
using namespace std;

inline void read(int &x){register int c = getchar();x = 0; int neg = 0;for (;((c<48 || c>57) && c != '-') ;c = getchar());if(c=='-') {neg=1;c=getchar();}for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}if(neg) x=-x;}
inline void read(long long &x){register int c = getchar();x = 0; int neg = 0;for (;((c<48 || c>57) && c != '-') ;c = getchar());if(c=='-') {neg=1;c=getchar();}for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}if(neg) x=-x;}
inline void writeln(long long x){char buffor[21];register int i=0;int neg=0; if (x<0) {neg=1; x= -x;}do{buffor[i++]=(x%10)+'0';x/=10;} while(x);i--;if (neg) putchar('-');while(i>=0) putchar(buffor[i--]);putchar('\n');}
inline void write(long long x){char buffor[21];register int i=0;int neg=0; if (x<0) {neg=1; x= -x;}do{buffor[i++]=(x%10)+'0';x/=10;} while(x);i--;if (neg) putchar('-');while(i>=0) putchar(buffor[i--]);putchar(' ');}

const double eps = 1e-8;
const int M = 2007;
const int N = 20;
const int MaxN = 1e6 + 7;

int m, n, k, ga, gb;
long long res;
bool CHECK[M][N];
bool Choose[N], dd[M];
ii A[MaxN], B[MaxN];

struct circle{
	int x, y, z, r;
	circle() {}
	circle(int x, int y, int z, int r): x(x), y(y), z(z), r(r) {}
}c[M];

struct point{
	int x, y, z, e;
	point() {}
	point(int x, int y, int z, int e): x(x), y(y), z(z), e(e) {}
}p[N], PVH;

long long sqrDist(point A, point B){
	return sqr(A.x - B.x) + sqr(A.y - B.y);
}

bool CheckIntersect(circle t, point A, point B){
	point O = point(t.x, t.y, t.z, 0);
	double Dist = 1.0 * abs((B.y - A.y) * O.x - (B.x - A.x) * O.y + A.y * B.x - A.x * B.y) / sqrt((B.y - A.y) * (B.y - A.y) + (B.x - A.x) * (B.x - A.x));
	int InOut = (sqrDist(O, A) <= sqr(t.r)) + (sqrDist(O, B) <= sqr(t.r)); 
	return (InOut == 1) || (InOut == 0 && t.r - Dist >= eps && ((O.x - A.x) * (O.x - B.x) < 0) || (O.y - A.y) * (O.y - B.y) < 0);
}

inline void check1(){
	int Intersect = 0;
	int sum = 0;
	for (int i = 1; i <= m; i++)
		dd[i] = false;
	for (int i = 1; i <= n; i++)
		if (Choose[i]){
			for (int j = 1; j <= m; j++)
				if (!dd[j]){
					if (CHECK[j][i]){
						dd[j] = true;
						Intersect++;
					}
				}
			sum += p[i].e;
		}
	A[++ga] = ii(Intersect, sum);
}

void backtrack1(int id){
	for (int i = 0; i <= 1; i++){
		Choose[id] = i;
		if (id < n)
			backtrack1(id + 1);
		else
			check1();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("teaworld.inp", "r", stdin);
	freopen("teaworld.out", "w", stdout);
	read(m); read(n); read(k);
	for (int i = 1; i <= m; i++){
		read(c[i].x); read(c[i].y); read(c[i].z); read(c[i].r);
	}
	for (int i = 1; i <= n; i++){
		read(p[i].x); read(p[i].y); read(p[i].z); read(p[i].e);
	}
	read(PVH.x); read(PVH.y); read(PVH.z);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			CHECK[i][j] = CheckIntersect(c[i], PVH, p[j]);
	backtrack1(1);
	// db(CheckIntersect(c[2], PVH, p[1]));
	sort(A + 1, A + ga + 1);
	for (int i = 1; i <= ga; i++)
		// cout << A[i].x << ' ' << A[i].y << endl;
	for (int i = 1; i <= ga; i++)
		if (A[i].x <= k){
			res = max(res, A[i].y);
		}
	writeln(res);
}