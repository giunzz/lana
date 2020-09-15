#include<bits/stdc++.h>
using namespace std;
int n,f[100],pri[100],a[1000005];
int main()
{
	freopen("mangdep.inp","r",stdin);
	freopen("mangdep.out","w",stdout);
	cin >>n;
	if (n%6!=0){
		cout << n ;
		return 0;
	}
	f[0]=1000005;
	f[4]=0;pri[4]=0;
	f[8]=0;pri[8]=4;
	f[15]=0;pri[15]=8;
	f[16]=0;pri[16]=15;
	f[23]=0;pri[23]=16;
	f[42]=0;pri[42]=23;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		f[a[i]]++;
		if (f[a[i]]>f[pri[a[i]]]) f[a[i]]--;
	}
	cout << n-(f[42]*6);
	return 0;
}