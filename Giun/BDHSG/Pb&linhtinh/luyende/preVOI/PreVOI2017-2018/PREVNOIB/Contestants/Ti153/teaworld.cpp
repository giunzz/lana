#include <bits/stdc++.h>
#define maxn 100001
using namespace std;
int n,m,k,x1[maxn],y1[maxn],z1[maxn],r1[maxn],x2[maxn],y2[maxn],z2[maxn],e2[maxn];
int x3,y3,z3,x[maxn];
int ds=0;
typedef pair<double,double> II;
double kc(II w,II u,II v){
    double a,b,c;
    if(u.first-v.first) b=1,a=(v.second-u.second)/(u.first-v.first),c=-(a*u.first+b*u.second);
    else b=0,a=1,c=-(a*u.first);
    double o=1e12;
    for(double i=min(u.first,v.first);i<=max(u.first,v.first);i=i+0.1){
        double j;
        if(a==0) j=-c/b;
        else j=-(a*i+c)/b;
        o=min(o,sqrt((w.first-i)*(w.second-i)+(w.second-j)*(w.second-j)));
    }
    return o;
}
void thu1(int u){
    if(u>n){
      int o=0,kkk=0;
      for(int i=1;i<=n;i++)if(x[i]) o+=e2[i];
        for(int j=1;j<=m;j++){
            int ok=0;
        for(int i=1;i<=n;i++){
            if(x[i]&&kc(II(x1[j],y1[j]),II(x2[i],y2[i]),II(x3,y3))<(double)r1[j])ok=1;
            if(x[i]&&kc(II(x1[j],y1[j]),II(x2[i],y2[i]),II(x3,y3))==(double)r1[j]
               &&x1[j]>min(x2[i],x3)&&x1[j]<max(x2[i],x3))ok=1;
        }
            kkk+=ok;
      }
      if(kkk<=k) ds=max(ds,o);
      return;
     }
    for(int i=0;i<=1;i++){
        x[u]=i;
        thu1(u+1);
    }
}
void sub1(){
    thu1(1);
    printf("%d",ds);
}
void sub2(){}
int main(){
    freopen("teaworld.inp","r",stdin);
    freopen("teaworld.out","w",stdout);
    scanf("%d%d%d",&m,&n,&k);
    for(int i=1;i<=m;i++) scanf("%d%d%d%d",&x1[i],&y1[i],&z1[i],&r1[i]);
    for(int i=1;i<=n;i++) scanf("%d%d%d%d",&x2[i],&y2[i],&z2[i],&e2[i]);
    scanf("%d%d%d",&x3,&y3,&z3);
    sub1();
}
