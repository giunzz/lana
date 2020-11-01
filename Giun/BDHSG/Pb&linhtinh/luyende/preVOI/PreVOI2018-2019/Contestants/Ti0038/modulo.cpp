#include <bits/stdc++.h>

using namespace std;
int n,k,a,b;
long long f[65],x[25];
void xl()
{   long long s=0;
    for (int i=1;i<=n;i++) if (x[i]==0) s=s*10+a;
    else s=s*10+b;
    if (s%f[n]==k) {cout<<s<<endl;exit(0);}
}
void try1(int i)
{
    for (int j=0;j<=1;j++)
    {
        x[i]=j;
        if (i==n) xl();
        else try1(i+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
     f[0]=1;
        cin>>a>>b;
     cin>>n>>k;
       for (int i=1;i<=n;i++) f[i]=f[i-1]*2;
     try1(1);

}
