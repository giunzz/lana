#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;

long long n,d[10];

int main()
{
	//faster
	//clock_t tStart = clock();
	freopen ("mangdep.inp","r",stdin);
	freopen ("mangdep.out","w",stdout);
	cin >> n;
	int x;
	memset (d,0,sizeof(d));
	for (int i=1;i<=n;i++)
	{
		cin >> x;
		if (x==4) d[0]++;
		if (x==8 && d[0] >= d[1]+1) d[1]++;
		if (x==15 && d[1] >= d[2]+1) d[2]++;
		if (x==16 && d[2] >= d[3]+1) d[3]++;
		if (x==23 && d[3] >= d[4]+1) d[4]++;
		if (x==42 && d[4]>= d[5]+1) d[5]++;
	}
	cout << n-6*d[5];
	//printf("Time taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}