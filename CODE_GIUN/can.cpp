#include <bits/stdc++.h>
using namespace std;
int ans = 0 , n , k;
int A[30],X[30];

void check()
{
	int l = k, r =0;
	for (int i = 1; i <=n ;i++)
	{
		if (X[i]==1) l+=A[i];
		else if (X[i]==2) r+=A[i];
	}
	if (l == r) ans++;
}

void ql(int vt)
{
	for (int i = 1; i <= 3; i++)
	{
		X[vt] = i;
		if ( vt == n ) check();
		else ql( vt + 1 );
	}
}
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
    freopen("can.inp","r",stdin);
	freopen("can.out","w",stdout);
	scanf("%d %d" , &n , &k);
	for (int i=1; i<=n; i++) scanf("%d" , &A[i]);
	ql(1);
	if (ans > 0) printf("%d",ans);
	else printf("%d",-1);
	return 0;
}