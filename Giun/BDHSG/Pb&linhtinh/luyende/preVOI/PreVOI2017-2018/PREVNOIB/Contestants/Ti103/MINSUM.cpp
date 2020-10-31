#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,f,b;
int tmp;
int a[1000];
int ans;
void khoitao(){
    freopen("MINSUM.INP","r",stdin);
    freopen("MINSUM.OUT","w",stdout);
}
void dong(){
    fclose(stdin);
    fclose(stdout);
}
bool kt(int i){
    for(int j=2;j*j<=i;j++){
        if(i%j==0) return false;
    }
    return true;
}
void sang(){
    tmp=2;
    a[1]=2;a[2]=3;
    for(int i=3;i*i<=100001;i++){
        if(kt(i)){
            tmp++;
            a[tmp]=i;
        }
    }
}
void inkq(){
    cin>>t;
    sang();
    while(t--){
        cin>>f>>b;
        for(int i=1;i<=tmp;i++){
            if(f%a[i]==0){
                ans=a[i];
                cout<<a[i]<<' ';
                break;
            }
        }
        for(int i=1;i<=tmp;i++){
            if((b%a[i]==0) && a[i]!=ans){
                int res=a[i];
                cout<<res;
                break;
            }
        }
        cout<<endl;
    }
}
int main(){
    khoitao();
    inkq();
    dong();
}
