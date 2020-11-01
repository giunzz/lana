#include<iostream>
#define int long long
using namespace std;
int a,b,n,k,mul[23],ar[23],mod=1;
string s="";
char char2int(int x){
	return x+'0';
}
void to_int(){
	for(int i=1;i<=n;i++){
		if(ar[i]==1){
			s+=char2int(a);
		}
		else{
			s+=char2int(b);
		}
	}
	cout<<s;
}
void check(){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(ar[i]==1){
			sum=(sum+mul[n-i]*a)%mod;
		}
		else{
			sum=(sum+mul[n-i]*b)%mod;
		}
	}
	if(sum==k){
		to_int();
		exit(0);
	}
	return;
}
void back(int i){
	if(i==n+1){
		check();
	}
	else{
		back(i+1);
		ar[i]=1;
		back(i+1);
		ar[i]=0;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("MODULO.inp","r",stdin);
	freopen("MODULO.out","w",stdout);
	cin>>a>>b>>n>>k;
	mul[0]=1;
	for(int i=1;i<=n;i++){
		mod=mod*2;
	}
	for(int i=1;i<=n;i++){
		mul[i]=(mul[i-1]*10)%mod;
	}
	back(1);
	cout<<-1;
}
