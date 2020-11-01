#include<bits/stdc++.h>
const int N=2006;
int x[N],r[N],a[20],e[20],X,Y,Z,res=0;
int m,n,k;
using namespace std;
int in(int x, int a , int b){
	if (x>=a-b && x<=a+b) return 1;
	else return 0;
}
void scan(int j, int remo, int val){
	if (remo>k) return;
	if (j==n+1){
		res=max(res,val);
		return;
	}
	int ct=0;
	for(int i=1;i<=m;++i)
		if (in(X,x[i],r[i])+in(a[j],x[i],r[i])==1 || 
		(X-(x[i]-r[i]))*(a[j]-(x[i]-r[i]))>0)
		ct++;
	scan(j+1,remo+ct,val+e[j]);
	scan(j+1,remo,val);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("teaworld.inp","r",stdin);
	freopen("teaworld.out","w",stdout);
	cin>>m>>n>>k;
	for(int i=1;i<=m;++i){
		int y,z;
		cin>>x[i]>>y>>z>>r[i];
	}
	for(int i=1;i<=n;++i){
		int b,c;
		cin>>a[i]>>b>>c>>e[i];
	}
	cin>>X>>Y>>Z;
	scan(1,0,0);
	cout<<res;
}
