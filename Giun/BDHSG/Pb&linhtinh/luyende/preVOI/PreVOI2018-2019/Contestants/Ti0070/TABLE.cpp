#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define For(i,a,b) for(int i=a;i<=b;i++)
int m,n,k;
int a[310][310];
struct path {
    int u,v,p,q;
}h[310];
void input(){
    freopen("TABLE.INP","r",stdin);
    freopen("TABLE.OUT","w",stdout);
    cin>>m>>n>>k;
    For(i,1,m)
        For(j,1,n){
            scanf("%d",&a[i][j]);
        }
    For(i,1,k)
        scanf("%d%d%d%d",&h[i].u,&h[i].v,&h[i].p,&h[i].q);
}
long long f[31][31];
void sub1(){
    For(tv,1,k){
        int u=h[tv].u;
        int v=h[tv].v;
        int p=h[tv].p;
        int q=h[tv].q;
        long long ans=1e18;
        For(I,u,p)
            For(J,v,q){
                if(I==u&&J==v) continue;
                if(I==p&&J==q) continue;
                For(i,u-1,p+1)
                    For(j,v-1,q+1)
                        f[i][j]=-1e9;
                int du=I,dv=J;
                f[u][v]=a[u][v];
                For(i,u,p)
                    For(j,v,q){
                        if(i==u&&j==v) continue;
                        if(i==du&&j==dv) continue;
                        if(f[i-1][j]!=-1e9) f[i][j]=max(f[i][j],f[i-1][j]+a[i][j]);
                        if(f[i][j-1]!=-1e9) f[i][j]=max(f[i][j],f[i][j-1]+a[i][j]);
                       // cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
                    }
                ans=min(ans,f[p][q]);
            }
            printf("%d\n",ans);
    }
}
int main(){
    input();
    sub1();

}
