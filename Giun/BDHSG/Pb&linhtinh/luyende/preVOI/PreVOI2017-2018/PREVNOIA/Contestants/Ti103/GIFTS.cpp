#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
int n,k;
int a[maxn],b[maxn],f[maxn],g[maxn];
vector<int>s;
void khoitao(){
    freopen("GIFTS.INP","r",stdin);
    freopen("GIFTS.OUT","w",stdout);
}
void dong(){
    fclose(stdin);
    fclose(stdout);
}
void nhap(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
        f[i]=g[i]=0;
    }
}
bool cmp(int a,int b){
    return a>b;
}
void xuli(){
    int tmp;
    int m=n-k+1;
    for(int i=1;i<=k;i++){
        f[1]+=a[i];
    }
    tmp=f[1];
    for(int i=2;i<=m;i++){
        f[i]=f[i-1]+a[i+k-1]-a[i-1];
        tmp=max(tmp,f[i]);
    }
    for(int i=1;i<=m;i++){
        if(f[i]==tmp){
            for(int j=i;j<=n-2;j++){
                b[j]=a[j+2];
            }
            continue;
        }
    }
    for(int i=n;i>n-k;i--) b[i]=0;
    for(int i=1;i<=k;i++){
        g[1]+=b[i];
    }
    for(int i=2;i<=m;i++)
    {
        g[i]=g[i-1]+b[i+k-1]-b[i-1];
    }
    sort(g+1,g+m+1,cmp);
    cout<<g[1];
}
int main(){
    khoitao();
    nhap();
    xuli();
    dong();
}

