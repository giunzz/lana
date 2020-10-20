#include <bits/stdc++.h>
using namespace std;

const int MAX=1e6+5,MOD=1e9+7;
int n,rs=0,f[MAX];

int main() {
	freopen("giun.inp","r",stdin),freopen("giun.out","w",stdout);
	cin>>n;
	f[0]=1;
	int x;
	for(int i=1;i<=n;i++) {
		cin>>x;
		if(x>n)
			continue;
		f[x]=(f[x]+f[x-1])%MOD;
	}
	for(int i=1;i<=n;i++)
		rs=(rs+f[i])%MOD;
	cout<<rs;
}
