#include<bits/stdc++.h>
#define maxn 1000001
using namespace std;
int m,n,k,x1,d[2],ds;
typedef pair<int,int> II;
II t[maxn],x[maxn];
int main(){
freopen("teaworld.inp","r",stdin);
freopen("teaworld.out","w",stdout);
cin>>m>>n>>k;
int u,v;
for(int i=1;i<=m;i++)cin>>x[i].first>>u>>v>>x[i].second;
for(int i=1;i<=n;i++)cin>>t[i].first>>t[i].second;
sort(t+1,t+n+1);
sort(x+1,x+m+1);
cin>>x1>>u>>v;
for(int i=1;i<=n;i++)if(x[i].first-x[i].second==x1||x[i].first+x[i].second==x1)k--,d[i]=1;
if(k<0)cout<<0;
else{
for(int i=1;i<=n;i++)ds+=t[i].second;
cout<<ds;
}
}
