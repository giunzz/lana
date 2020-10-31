#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inp "modulo.inp"
#define out "modulo.out"
#define oo 105
int a,b,n,k,m,f[oo];
bool ok;
void nhap(){
  cin>>a>>b>>n>>k;
}
bool check(int x){
  if(x%m==k) return 1;
  return 0;
}
void inra(){
  int dem=1,ans=0;
  for(int i=1;i<=n;i++){
    if(f[i]==1) ans+=a*dem;
    else ans+=b*dem;
    dem*=10;
  }
  if(check(ans)==1){
    cout<<ans;
    ok=1;
  }
}
void dfs(int x){
  for(int i=1;i<=2;i++){
    if(ok==1) return;
    f[x]=i;
    if(x==n) inra();
    else dfs(x+1);
  }
}
void xuly(){
  m=pow(2,n);
  dfs(1);
  if(ok==0) cout<<-1;
}
void xuly1(){
  cout<<-1;
}
main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen(inp,"r",stdin);
  freopen(out,"w",stdout);
  nhap();
  if(n<20) xuly();
  else xuly1();
}
