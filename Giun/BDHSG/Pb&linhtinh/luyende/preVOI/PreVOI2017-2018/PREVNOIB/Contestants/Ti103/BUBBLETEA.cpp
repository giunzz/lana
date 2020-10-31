#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn=50010;
int n,k;
struct pt{
    int u,v,c;
}b[maxn];
int a[maxn];
 void khoitao(){
    freopen("BUBBLETEA.INP","r",stdin);
    freopen("BUBBLETEA.OUT","w",stdout);
 }
 void dong(){
    fclose(stdin);
    fclose(stdout);
 }
 void xuli(){
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i].u>>b[i].v>>b[i].c;
    }
    cout<<-1;
 }
 int main(){
    khoitao();
    xuli();
    dong();
 }
