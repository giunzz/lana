#include<bits/stdc++.h>
#define maxn 1000005
#define Task "TEAWORLD"
#define oo 1000000001

using namespace std ;

int m,n,k,e[maxn],r[maxn],a[maxn],s[maxn],x[maxn],maxab=0,ds=-oo,xs,ys,zs;
int x1[maxn],y1[maxn],z1[maxn],y[maxn],z[maxn];

void sub1(){
sort(x1+1,x1+m+1);
x[0]=-oo;
x1[m+1]=oo;
sort(x+1,x+n+1);
int j=0;
for(int i=1;i<=m+1;++i){
        s[i]=s[i-1];
    while(x[j]<x1[i] && j<=n) {s[i]+=e[j];
    ++j;
    };
};
//for(int i=1;i<=m+1;++i)cout<<s[i]<<" ";
for(int i=1;i<=m-k+1;++i){
    if(x[i]<=xs && xs<=x[i+k-1]){
        ds=max(ds,s[i+k-1]-s[i-1]);
    };
};
if(ds==-oo) cout<<s[2]-s[1];else printf("%d\n",ds);
}

void sub2(){

}

void solve(){
sub1();
}


int main()
{
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    scanf("%d%d%d",&m,&n,&k);
    for(int i=1;i<=m;++i){
        scanf("%d%d%d%d",&x1[i],&y1[i],&z1[i],&r[i]);
    };
    for(int i=1;i<=n;++i) scanf("%d%d%d%d",&x[i],&y[i],&z[i],&e[i]);
    scanf("%d%d%d",&xs,&ys,&zs);
    solve();
    }
