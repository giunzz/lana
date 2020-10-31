#include<bits/stdc++.h>
using namespace std;
const int N=2e6+6;
int a[N],n,k;
long long l[N],r[N],res=1e18;
int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
void solve(){
	long long s=0;
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	for(int i=1;i<=k;++i)
		s=s+a[i];
	l[k]=s;
	for(int i=k+1;i<=n;++i){
		s=s-a[i-k]+a[i];
		l[i]=max(l[i-1],s);
	}
	s=0;
	for(int i=n;i>=n-k+1;--i)
		s=s+a[i];
	r[n-k+1]=s;
	for(int i=n-k;i>=1;--i){
		s=s-a[i+k]+a[i];
		r[i]=max(r[i+1],s);
	}
	for(int i=1;i<=n;++i)
		res=min(res,max(l[i-1],r[i+k]));
	cout<<res;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("gifts.inp","r",stdin);
	freopen("gifts.out","w",stdout);
	n=readInt();k=readInt();
	for(int i=1;i<=n;++i) a[i]=readInt();
	solve();
}
