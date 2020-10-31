#include <bits/stdc++.h>
using namespace std;

#define task "teaworld"
#define maxN 2123


struct vt
{
	int x,y,z;
	vt operator - (vt other) {return {x-other.x,y-other.y,z-other.z};}
};

typedef vt pt;

int m,n,k;
pt a[maxN],b[maxN];
pt s;
int r[maxN],c[maxN];
bool f[maxN],dd[maxN];
int ans;

bool pass(int i, int j) {
	if (max(s.x,b[i].x) < a[j].x-r[j]) return true;
	if (min(s.x,b[i].x) > a[j].x+r[j]) return true;
	if (min(s.x,b[i].x) >= a[j].x-r[j] && max(s.x,b[i].x) <= a[j].x+r[j]) return true;
	return false;
}

void check() {
	int cnt = 0;
	int res = 0;
	for (int i=1; i<=m; ++i) f[i] = false;
	for (int i=1; i<=n; ++i) if (dd[i]) {
		for (int j=1; j<=m; ++j) if (!f[j]) {
			if (!pass(i,j)) {
				f[j] = true;
				++cnt;
			}
			if (cnt > k) return;
		}
		res += c[i];
	}
	if (cnt > k) return;
	ans = max(ans,res);
}

void backtrack(int i) {
	if (i==n+1) check();
	else {
		dd[i] = true;
		backtrack(i+1);
		dd[i] = false;
		backtrack(i+1);
	}
}

int main() {
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
	scanf("%d%d%d",&m,&n,&k);
	for (int i=1; i<=m; ++i) scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].z,&r[i]);
	for (int i=1; i<=n; ++i) scanf("%d%d%d%d",&b[i].x,&b[i].y,&b[i].z,&c[i]);
	scanf("%d%d%d",&s.x,&s.y,&s.z);
	backtrack(1);
	printf("%d\n", ans);
}