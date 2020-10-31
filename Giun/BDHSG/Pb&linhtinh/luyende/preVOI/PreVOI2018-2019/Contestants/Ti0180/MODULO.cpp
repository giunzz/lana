#include <bits/stdc++.h>

using namespace std;

int n,k,a,b,x[100],dd;
int64_t du;

void inkq()
{
    int64_t P=0;
    for (int i=1; i<=n; i++)
        if (x[i]==0) P=P*10+a; else P=P*10+b;
    if (P%du==k) {cout<<P; dd=1; return;}
}

void Try(int i)
{
    if (dd==1) return;
    for (int j=0; j<=1; j++)
    {
        x[i]=j;
        if (i>=n) inkq(); else Try(i+1);
    }
}

void xuly1()
{
    dd=0; Try(1);
    if (dd==0) cout<<-1;
}

int main()
{
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.out","w",stdout);
    scanf("%d %d",&a,&b);
    scanf("%d %d",&n,&k);
    du=1<<n;
    if (n<=20) {xuly1(); return 0;}
    else cout<<-1;
}
