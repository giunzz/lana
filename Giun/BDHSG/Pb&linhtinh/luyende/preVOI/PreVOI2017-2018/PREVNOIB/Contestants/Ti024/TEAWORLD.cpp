#include<bits/stdc++.h>
#define maxn 20
#define maxm 2005
#define ft first
#define oo int(2e9)
#define sc second
using namespace std ;
int m,n,k;
typedef pair<int,int>II;
typedef pair<II,int>III;
II t[maxm],a1[maxm];
III a2[maxm];
int x[maxm],y[maxm],r[maxm],z[maxm];
int a[maxn],b[maxn],c[maxn],d[maxn];
int gsx,gsy,gsz;
int x1[maxm];
int b1[maxm];
int vitri1;
int vitri2;
int vitri3;
int vitri4;
int a3[maxm];
int ds=0;
bool giao(int i,int j){
   int max1=max(gsx,a[i]);
   int min1=min(gsx,a[i]);
   int dt1=a1[j].ft,dt2=a1[j].sc;
   if(max(min1,dt1)<=min(max1,dt2))return true;
   return false;
}
void xuly(){
   int tong=0;
   int check=0;
   for(int i=1;i<=m;i++)a1[i]=II(a2[i].sc,a2[i].ft.sc);
   for(int i=vitri1;i>=1;i--)if(x1[i]==1)
       for(int j=1;j<=m;j++)if(giao(i,j))check++,a1[j]=II(oo,oo);
   for(int i=vitri2;i<=n;i++)if(x1[i]==1)
       for(int j=1;j<=m;j++)if(giao(i,j))check++,a1[j]=II(oo,oo);
   if(check<=k){
      for(int i=1;i<=n;i++)if(x1[i]==1)tong+=t[i].sc;
      ds=max(ds,tong);
   }
   //cerr<<check<<" ";
}
void thu(int i){
   if(i>n){xuly();return;}
   for(int j=0;j<=1;j++){
       x1[i]=j;
       thu(i+1);
   }
}
void sub1(){
   for(int i=1;i<=m;i++)a2[i]=III(II(x[i],x[i]+d[i]),x[i]-d[i]);
   sort(a2+1,a2+m+1);
   for(int i=1;i<=m;i++)a3[i]=a2[i].ft.ft;
   for(int i=1;i<=n;i++)t[i]=II(a[i],d[i]);
   sort(t+1,t+n+1);
   for(int i=1;i<=n;i++)a[i]=t[i].ft;
   vitri1=lower_bound(a+1,a+n+1,gsx)-a-1;
   vitri2=vitri1+1;
   thu(1);
   printf("%d",ds);
}
int main(){
   freopen("TEAWORLD.inp","r",stdin);
   freopen("TEAWORLD.out","w",stdout);
   scanf("%d %d %d",&m,&n,&k);
   for(int i=1;i<=m;i++){
       scanf("%d %d %d %d",&x[i],&y[i],&z[i],&r[i]);
   }
   for(int i=1;i<=n;i++){
       scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
   }
   scanf("%d %d %d",&gsx,&gsy,&gsz);
   int dd=0;
   for(int i=1;i<=m;i++)if(y[i]!=0||z[i]!=0)dd=1;
   if(dd==0)sub1();
}
