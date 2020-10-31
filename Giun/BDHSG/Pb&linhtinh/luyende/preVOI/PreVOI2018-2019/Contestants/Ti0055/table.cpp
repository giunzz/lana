#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,a,b)  for(long long  i=a;i<=b;++i)
#define fi first
#define se second
#define maxN 305
#define INF 1000000000
int n,m,k;
ll dp[maxN][maxN],a[maxN][maxN];
void io() {
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
}
ll solve(int x,int y,int u,int v) {
    ll ans=1e18;
    FOR(i,x,u)
        FOR(j,y,v) {
         //   cout<<"Asf "<<i<<' '<<j<<endl;
            FOR(p,x,u)
                FOR(q,y,v){
                    dp[p][q]=-1e18;
                  //  cout<<" d  dd "<<' '<<p<<' '<<q<<endl;
                }
            //cout<<" dp "<<x<<' '<<y<<endl;
            if((i==x&&j==y)||(i==u&&j==v)) continue;
            dp[x][y]=a[x][y];
            FOR(p,x,u)
                FOR(q,y,v) {
                   // cout<<" dp " <<p<<' '<<q<<' '<<dp[p][q]<<endl;
                    if(p==x&&q==y) continue;
                    if((p==1&&i==1&&q>j)||(q==1&&j==1&&p>i)){
                        dp[i][j]=-1e18;
                        continue;
                    }
                    dp[p][q]=max(dp[p][q-1]+a[p][q],dp[p-1][q]+a[p][q]);
                    if(i==p&&j==q) {
                        dp[p][q]=-1e18;
                        continue;
                    }
                    if(p-1==i&&q==j) {
                        dp[p][q]=dp[p][q-1]+a[p][q];
                        continue;
                    }
                    if(p==i&&q-1==j) {
                        dp[p][q]=dp[p-1][q]+a[p][q];
                    }
                }
//            FOR(p,x,u)
//                FOR(q,y,v)
//                    cout<<" dp " <<p<<' '<<q<<' '<<dp[p][q]<<endl;
//            cout<<" ans " <<i<<' '<<j<<' '<<dp[u][v]<<endl;
            ans=min(ans,dp[u][v]);
        }
    return ans;
}
int main() {
    io();
    cin>>m>>n>>k;
    FOR(i,1,m) {
        FOR(j,1,n) {
            scanf("%lld",&a[i][j]);
        }
    }
    FOR(i,1,k) {
        int x,y,u,v;
        scanf("%d%d%d%d",&x,&y,&u,&v);
       // cout<<"a sd " <<x<<' '<<y<<' '<<u<<' '<<v<<endl;
        printf("%lld\n",solve(x,y,u,v));
    }
  //  cout<<(double) clock()/1000;
}
