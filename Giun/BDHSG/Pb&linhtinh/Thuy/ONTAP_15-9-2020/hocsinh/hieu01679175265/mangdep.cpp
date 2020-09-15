#include<iostream>
#include<cstdio>
using namespace std;
const long long amax=1e6+5;
int a[amax],x,dem=0;
int d[amax];
int main(){
   freopen("mangdep.inp","r",stdin);
    freopen("mangdep.out","w",stdout);
int n;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>x;
    if((x==4)||(x==8)||(x==15)||(x==16)||(x==23)||(x==42)){
        dem++;
        a[dem]=x;
    }
}
for(int i=1;i<=dem;i++){
    if(a[i]==4) d[4]++;
    if((a[i]==8)&&(d[4]!=0)){
        d[4]--;
        d[8]++;
    }
    if((a[i]==15)&&(d[8]!=0)){
        d[15]++;
        d[8]--;
    }
    if((a[i]==16)&&(d[15]!=0)){
        d[16]++;
        d[15]--;
    }
    if((a[i]==23)&&(d[16]!=0)){
        d[23]++;
        d[16]--;
    }
    if((a[i]==42)&&(d[23]!=0)){
        d[23]--;
        d[42]++;
    }
}
cout<<n-d[42]*6;
return 0;
}
