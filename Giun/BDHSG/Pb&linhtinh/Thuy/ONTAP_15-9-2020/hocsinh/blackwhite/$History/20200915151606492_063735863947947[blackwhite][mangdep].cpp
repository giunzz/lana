#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef pair<int,int> ii;

int n,a[1000005],d[6];

int main()
{
	faster
	cin.tie(0);
	cout.tie(0);
	//clock_t tStart = clock();
	freopen ("mangdep.inp","r",stdin);
	freopen ("mangdep.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort (a+1,a+n+1);
	memset (d,0,sizeof(d));
	for (int i = 1; i <= n; ++i)
	{
		if (a[i]==4) d[0]++;
		if (a[i]==8) d[1]++;
		if (a[i]==15) d[2]++;
		if (a[i]==16) d[3]++;
		if (a[i]==23) d[4]++;
		if (a[i]==42) d[5]++;
	}
	sort(d,d+6);
	int minn=d[0];
	int ans=0;
	for (int i=0;i<6;i++)
	{
		ans+=d[i]-minn;
	}
	cout << ans;
	//printf("Time taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}