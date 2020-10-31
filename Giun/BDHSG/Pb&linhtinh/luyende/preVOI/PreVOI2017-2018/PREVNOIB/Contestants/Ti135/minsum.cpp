#include <bits/stdc++.h>
#define maxp 1000000
using namespace std;
int t,e[maxp+1],p[maxp+1],d[maxp+1],h[maxp+1],c[maxp+1],np;
int ds,x,y,n;
void ankin(){
    for(int i=1;i<=maxp;i++)e[i]=i;
    np=0;
    for(int i=2;i<=maxp;i++){
        if(e[i]==i) p[++np]=i;
        int j=1;
        while(j<=np&&p[j]<=e[i]&&p[j]<=maxp/i){
            e[p[j]*i]=p[j];
            j++;
        }
    }
}
void xuli(){
    int x1=1,y1=1;
    for(int i=1;i<=n;i++)if(h[i]==0) x1*=c[i];else y1*=c[i];
    if(x1+y1<ds) ds=x1+y1,x=x1,y=y1;
}
void thu(int u){
    if(u>n){xuli();return;}
    for(int i=0;i<=1;i++){
        h[u]=i;
        thu(u+1);
    }
}
int main(){
    freopen("minsum.inp","r",stdin);
    freopen("minsum.out","w",stdout);
    ankin();
    scanf("%d",&t);
    while(t--){
        int a,b;scanf("%d%d",&a,&b);
        for(int i=1;i<=np;i++) while(a>1&&a%p[i]==0) d[i]++,a/=p[i];
        if(a>1) d[++np]++,d[np]=a;
        for(int i=1;i<=np;i++) while(b>1&&b%p[i]==0) d[i]++,b/=p[i];
        if(b>1) d[++np]++,d[np]=b;
        n=0;
        for(int i=1;i<=np;i++)if(d[i]%2) c[++n]=p[i];
        ds=2e9,x=0,y=0;
        thu(1);
        printf("%d %d %d\n",x,y,x+y);
        for(int i=1;i<=np;i++) d[i]=0;
    }
}
