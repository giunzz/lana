#include <bits/stdc++.h>
#define maxn 400
#define maxm 20000
#define base 1000000009
using namespace std;
int m3,m1,m2,n,mm;
long long kq, f[100][27][27][27];

void xl1(){
    kq=0;
    for (int j1=0;j1<=mm;j1++)
    for (int j2=0;j2<=mm;j2++)
    for (int j3=0;j3<=mm;j3++) f[n+1][j1][j2][j3]=1;
    for (int i=n;i>=1;i--)
    for (int j1=0;j1<=mm;j1++)
    for (int j2=0;j2<=mm;j2++)
    for (int j3=0;j3<=mm;j3++){
        f[i][j1][j2][j3]=0;
        if (j1<mm) f[i][j1][j2][j3]=(f[i][j1][j2][j3]+f[i+1][j1+1][j2][j3])%base;
        if (j2<mm && j1>0) f[i][j1][j2][j3]=(f[i][j1][j2][j3]+f[i+1][j1-1][j2+1][j3])%base;
        if (j3<mm)
            if (j1>0 && j2>0) f[i][j1][j2][j3]=(f[i][j1][j2][j3]+f[i+1][j1-1][j2-1][j3+1])%base;
        else if (j1>2) f[i][j1][j2][j3]=(f[i][j1][j2][j3]+f[i+1][j1-3][j2][j3+1])%base;
    }
    cout<<f[1][m1][m2][m3]<<endl;
}
int main()
{
    freopen("ICECREAM.inp","r",stdin);
    freopen("ICECREAM.out","w",stdout);
    cin>>n>>mm>>m1>>m2>>m3;
    xl1();
    return 0;
}
