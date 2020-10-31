#include<bits/stdc++.h>
const int N=1e5+2;
int a,b,T,ct[N];
using namespace std;
void solve(int a){
	for(int i=2;i<=sqrt(a);++i){
		while (a%i==0){
			a/=i;
			ct[i]++;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("minsum.inp","r",stdin);
	freopen("minsum.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>a>>b;
		int x=__gcd(a,b);
		a/=x;b/=x;
		solve(a);
		int a1=1;bool ok=false;
		for(int i=2;i<=sqrt(a);++i)
			if (ct[i]>0){
				ok=true;
				if (ct[i]%2==1) a1*=i;
				ct[i]=0;
			}
		if (ok) a=a1;
		int b1=1;
		solve(b);ok=false;
		for(int i=2;i<=sqrt(b);++i)
			if (ct[i]>0){
				ok=true;
				if (ct[i]%2==1) a1*=i;
				ct[i]=0;
			}
		if (ok) b=b1;
		for(int i=2;i<=sqrt(a);++i)
			if (a%i==0){
				if (a/i+b*i<a+b){
					a/=i;
					b*=i;
				}
			}
		for(int i=2;i<=sqrt(b);++i)
			if (b%i==0){
				if (a*i+b/i<a+b){
					a*=i;
					b/=i;
				}
			}
		cout<<a<<" "<<b<<'\n';
	}
}
