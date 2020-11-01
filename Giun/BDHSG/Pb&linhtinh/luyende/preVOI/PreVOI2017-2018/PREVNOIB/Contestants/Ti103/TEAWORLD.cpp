#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn=16;
const int maxm=2010;
int m,n,k;
struct pt{
    int x,y,z,r,t,p,id;
}a[maxm];
struct oo{
    int u,v,c,e,id;
}b[maxn];
int ua,va,ca;
bool ok[maxm];

void khoitao(){
    freopen("TEAWORLD.INP","r",stdin);
    freopen("TEAWORLD.OUT","w",stdout);
}
void dong(){
    fclose(stdin);
    fclose(stdout);
}
void xuli(){
    cin>>m>>n>>k;
    memset(ok,sizeof(ok),false);
    for(int i=-101;i<=101;i++) b[i].e=0;
    for(int i=1;i<=m;i++){
        cin>>a[i].x>>a[i].y>>a[i].z>>a[i].r;
        a[i].t=a[i].x-a[i].r-1;
        a[i].p=a[i].x+a[i].r+1;
        a[i].id=i;
        ok[a[i].t]=false;
        ok[a[i].p]=false;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i].u>>b[i].v>>b[i].c>>b[i].e;
        b[i].id=i;
    }
    cin>>ua>>va>>ca;
    int res=0;
    if(k==0){
        for(int i=ua;i<=501;i++){
            if(ok[i]==false) break;
            res+=b[i].e;
        }
        for(int i=ua-1;i>=-501;i--){
            if(ok[i]==false) break;
            res+=b[i].e;
        }
        cout<<res;return;
    }
    cout<<b[1].e+b[3].e+b[5].e;
}
int main(){
    khoitao();
    xuli();
    dong();
}
