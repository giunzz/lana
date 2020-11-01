#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
#define fi first
#define se second
using namespace std;

const int dx[2]={0,1};
const int dy[2]={1,0};
bool used[305][305];

int m,n,k,u[305],v[305],p[305],q[305];
ll a[305][305],cnt,ans;

void IO() {
    freopen("TABLE.inp","r",stdin);
    freopen("TABLE.out","w",stdout);
}

void dfs(int u,int v,int p,int q,ll s) {
    if (u==p && v==q) {
        cnt=max(s,cnt);
        return;
    }
    For(i,0,1) {
        int uu=u+dx[i];
        int vv=v+dy[i];
        if (uu>p || vv>q || used[uu][vv]) continue;
            dfs(uu,vv,p,q,s+a[uu][vv]);
    }
}

void Solve() {
        For(c,1,k) {
            ans=1e9;
            For(i,u[c],p[c])
                For(j,v[c],q[c]) {
                    if ((i==u[c]&&j==v[c])||(i==p[c]&&j==q[c])) continue;
                    cnt=0;
                    used[i][j]=true;
                    dfs(u[c],v[c],p[c],q[c],a[u[c]][v[c]]);
                    used[i][j]=false;
                    ans=min(ans,cnt);
                }
            cout<<ans<<'\n';
        }
}

void Read() {
    scanf("%d%d%d",&m,&n,&k);
    For(i,1,m)
        For(j,1,n)
            scanf("%lld",&a[i][j]);
    For(i,1,k) {
        scanf("%d%d%d%d",&u[i],&v[i],&p[i],&q[i]);
    }
}

int main() {
    IO();
    Read();
    Solve();
    return 0;
}
