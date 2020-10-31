#include <bits/stdc++.h>
using namespace std;
unsigned long long n,k,a,b,s,m;
void xl1(){
    for (int i=0;i< (1<<n);i++){
        s=0;
        for (int j=1;j<=n;j++){
            if (1&(i>>(j-1))) s=s*10+a;else s=s*10+b;}
        if (s%m==k) {cout<<s<<endl;return;}
    }
    cout<<-1<<endl;
    return;
}
int main()
{
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.out","w",stdout);
    cin>>a>>b>>n>>k;
    m=1;
    for (int i=1;i<=n;i++) m=m*2;
    xl1();
    return 0;
}
