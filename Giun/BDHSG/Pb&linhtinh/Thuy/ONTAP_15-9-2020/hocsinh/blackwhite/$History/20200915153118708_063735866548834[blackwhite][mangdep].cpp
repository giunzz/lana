#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;

int n,a[1000005],d[6];

int main()
{
	//faster
	//clock_t tStart = clock();
	freopen ("mangdep.inp","r",stdin);
	freopen ("mangdep.out","w",stdout);
	cin >> n;
	memset (d,0,sizeof(d));
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		if (a[i]==4) d[0]++;
		if (a[i]==8 && d[0] > 0) d[1]++;
		if (a[i]==15 && d[1] > 0) d[2]++;
		if (a[i]==16 && d[2] > 0) d[3]++;
		if (a[i]==23 && d[3] > 0) d[4]++;
		if (a[i]==42 && d[4] > 0) d[5]++;
	}
	cout << n-6*d[5];
	//printf("Time taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}