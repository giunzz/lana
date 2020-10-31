#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=100005;
int n;
ll a[maxn];
ll tmp,res;
ll ans;
ll h1,h2;

void khoitao(){
    freopen("ARRANGE.INP","r",stdin);
    freopen("ARRANGE.OUT","w",stdout);
}
void dong(){
    fclose(stdin);
    fclose(stdout);
}
void nhap(){
    cin>>n;
    ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans+=a[i];
    }
}
bool kt(int i){
    return i>=1 && i<=n;
}
void dao1(int i){
    tmp=(-tmp);
    a[i]-=tmp;
}
void dao2(int i){
    tmp=(-tmp);
    a[i]+=tmp;
}
void tru(int k){
    int r=0,i,j;
    a[k]=h2;
    i=j=k;
    while(tmp>0){
        i--;j++;
        if(a[i]<h2 && kt(i)){
            tmp-=(h2-a[i]);
            res+=(r+h2-a[i]);
            a[i]=h2;
            if(tmp<0){ dao2(i);tmp=0;}
        }
        if(a[j]<h2 && kt(i)){
            tmp-=(h2-a[j]);
            res+=(r+h2-a[j]);
            a[j]=h2;
            if(tmp<0){ dao2(j);tmp=0;}
        }
        r++;
    }
}
void cong(int k){
    int r=1,i,j;
    a[k]=h1;
    i=j=k;
    while(tmp>0){
        i--;j++;
        if(a[i]==h2 && kt(i)){
            tmp--;
            res+=r;
            if(tmp<0){ dao1(i);tmp=0;}
        }
        if(a[j]==h2 && kt(i)){
            tmp--;
            res+=r;
            if(tmp<0){ dao1(j);tmp=0;}
        }
        r++;
    }
}
void xuli(){
    h1=ans/n;h2=h1+1;
    res=0;
    for(int i=1;i<=n;i++){
        if(a[i]>h2){
            tmp=a[i]-h2;
            tru(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]<h1){
            tmp=h1-a[i];
            cong(i);
        }
    }
    cout<<res;
}
int main(){
    khoitao();
    nhap();
    xuli();
    dong();
}
