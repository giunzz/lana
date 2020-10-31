#include<iostream>
#include<fstream>
using namespace std;
int da,n,m,a[4],f[4];
void xuli(int i){
    if(i==n+1){
        da++;
        return;
    }
    if(a[1]<m){
        a[1]++;
        f[i]=50;
        xuli(i+1);
        a[1]--;
    }
    if(a[1]>0&&a[2]<m){
        a[1]--; a[2]++;
        f[i]=1;
        xuli(i+1);
        a[1]++; a[2]--;
    }
    if(a[1]>0&&a[2]>0&&a[3]<m){
        a[1]--; a[2]--; a[3]++;
        f[i]=2;
        xuli(i+1);
        a[1]++; a[2]++; a[3]--;
    }
    else if(a[1]>=3&&a[3]<m){
        a[1]-=3; a[3]++;
        f[i]=2;
        xuli(i+1);
        a[1]+=3; a[3]--;
    }
}
int main(){
    freopen("ICECREAM.inp","r",stdin);
    freopen("ICECREAM.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=3;i++){
        cin>>a[i];
    }
    xuli(1);
    cout<<da;
}
