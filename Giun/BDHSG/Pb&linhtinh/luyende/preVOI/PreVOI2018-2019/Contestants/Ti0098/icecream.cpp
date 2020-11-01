#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inp "icecream.inp"
#define out "icecream.out"
#define oo 305
int n,maxx,x1,x2,x3,a[oo],m1,m2,m3,res;
void nhap(){
  cin>>n>>maxx>>x1>>x2>>x3;
}
bool check(){
  if(m1>maxx || m2>maxx || m3>maxx) return 0;
  return 1;
}
void inra(){
  m1=x1;
  m2=x2;
  m3=x3;
  for(int i=1;i<=n;i++){
    if(a[i]==1) m1++;
    if(a[i]==2){
      if(m1>0){
        m1--;
        m2++;
      }
      else return;
    }
    if(a[i]==3){
      if(m1>0 && m2>0){
        m1--;
        m2--;
        m3++;
        continue;
      }
      else{
        if(m1>2){
          m1-=3;
          m3++;
        }
        else return;
      }
    }
    if(check()==0) return;
  }
  res++;
}
void dfs(int x){
  for(int i=1;i<4;i++){
    a[x]=i;
    if(x==n) inra();
    else dfs(x+1);
  }
}
void xuly(){
  if(m1>maxx || m2>maxx || m3>maxx){
    cout<<0;
    return;
  }
  dfs(1);
  cout<<res;
}
main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen(inp,"r",stdin);
  freopen(out,"w",stdout);
  nhap();
  xuly();
}
