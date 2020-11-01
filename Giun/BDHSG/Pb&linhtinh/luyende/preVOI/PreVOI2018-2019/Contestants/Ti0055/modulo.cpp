#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define FOR(i,a,b)  for(int i=a;i<=b;++i)
#define fi first
#define se second
#define maxM 10004
int n,x[65],a[3];
ull k;
ull mod;
void io() {
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
}
void dfs(int u) {
    if(u>n) {
        ull val=0;
        FOR(i,1,n) val=(val*10+(ull)x[i]);
      //  cout<<" val " <<val<<endl;
        if(val%mod==k) {
            cout<<val;
            exit(0);
        }
        return ;
    }
    for(int i=1;i<=2;++i) {
        x[u]=a[i];
        dfs(u+1);
    }
}
void sub1() {
    dfs(1);
}
void sub2(){
    cout<<"-1";

}
int main () {
    ios_base:: sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    io();
    cin>>a[1]>>a[2];
    cin>>n>>k;
    if(k==0&&(a[1]%2==1&&a[2]%2==1)) {
        cout<<"-1";
        return 0;
    }
    mod=(1<<n);
    //cout<<mod<<endl;
    if(n<=19)
        sub1();
    else sub2();
}
