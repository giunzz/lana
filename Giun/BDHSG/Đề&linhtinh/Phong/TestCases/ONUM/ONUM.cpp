#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,n;
	freopen("onum.inp","r",stdin);
	freopen("onum.out","w",stdout);
	cin>>n>>a>>b;
	long long rest=(b*(n-1)+a)-(a*(n-1)+b)+1;
	if (a<=b) cout<<rest;
	else cout<<0;
	return 0;
}