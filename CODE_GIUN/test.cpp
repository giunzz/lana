#include<bits/stdc++.h>
#define R register
#define N 1000201
 
int z,f,a[N],b[N];
 
inline void solve(){
	z=-1,f=-1;
	R int n;
	scanf("%d",&n);
	for(R int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(R int i=1;i<n;++i){
		R int qwq=a[i+1]-a[i];
		if(qwq>0){
			if(z==-1) z=qwq;
			else if(qwq!=z){
				printf("-1\n");
				return ;
			}
		} else{
			qwq=-qwq;
			if(f==-1) f=qwq;
			else if(qwq!=f){
				printf("-1\n");
				return;
			}
		}
	}
	if(f==-1||z==-1) return (void)printf("0\n");
	R int m=z+f;
	b[1]=a[1];
	if(a[1]>=m){
		printf("-1\n");
		return;
	}
	for(R int i=2;i<=n;++i){
		b[i]=(b[i-1]+z)%m;
		if(b[i]!=a[i]){
			printf("-1\n");
			return;
		}
	}
	printf("%d %d\n",m,z);
	
}
int main(){
	R int T;
	std::cin>>T;
	while(T--)
		solve();
}