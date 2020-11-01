#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,a,b)  for(int i=a;i<=b;++i)
#define fi first
#define se second
#define maxM 10004
int n,mmax,m50,m1,m2,x[306],M50,M1,M2;
ll ans=0;
const int mod=1e9+9;
void io() {
    freopen("icecream.inp","r",stdin);
    freopen("icecream.out","w",stdout);
}
ll check() {
    m50=M50;
    m1=M1;
    m2=M2;
   // cout<<endl<<" check " <<endl;
   // FOR(u,1,n){
       // cout<<x[u]<<' ';
   // }
    FOR(u,1,n) {
       // cout<<" for "<<x[u]<<endl;
        if(x[u]==1){
            if(m50<mmax)
                m50++;
            else return 0;
        }
        if(x[u]==2) {
            if(m1==mmax||m50==0) return 0;
            m1++;
            m50--;
        }
        if(x[u]==3) {
            if(m2==mmax) return 0;
            if(min(m1,m50)>0) {
                m1--;
                m50--;
                m2++;
                continue;
            }
            if(m50>=3) {
                m50-=3;
                m2++;
                continue;
            }
            return 0;
        }
       // cout<<" ok "<<endl;
    }
    return 1;
}
void dfs(int u) {
    if(u>n) {
        ans=(ans+check())%mod;
        return;
    }
    for(int i=1;i<=3;++i) {
        x[u]=i;
        dfs(u+1);
    }
}
int main () {
    ios_base:: sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    io();
    cin>>n>>mmax;
    cin>>M50>>M1>>M2;
    dfs(1);
    cout<<ans;

}
