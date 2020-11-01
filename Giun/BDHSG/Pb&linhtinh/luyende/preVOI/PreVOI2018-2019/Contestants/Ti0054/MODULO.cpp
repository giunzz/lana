#include <bits/stdc++.h>
using namespace std;
int A,B,N,K;
int x[22],T,res,t[22]={1};
bool kt;
void update()
{
    int s=0;
    for(int i=1;i<=N;++i)
        if(x[i]) s+=B*t[N-i];
        else s+=A*t[N-i];
    if(s%T==K) {kt=1; res=s;}
}
void xaydung(int i)
{
    if(kt) return;
    for(int j=0;j<=1;++j)
    {
        x[i]=j;
        if(i==N) update();
        else xaydung(i+1);
        if(kt) return;
    }
}
void sub1()
{
    T=1<<N;
    for(int i=1;i<N;++i) t[i]=t[i-1]*10;
    xaydung(1);
    if(kt) cout<<res;
    else cout<<-1;
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("MODULO.INP","r",stdin);
    freopen("MODULO.OUT","w",stdout);
    cin>>A>>B>>N>>K;
    if(N<=26) {sub1(); return 0;}
    cout<<-1;
}
