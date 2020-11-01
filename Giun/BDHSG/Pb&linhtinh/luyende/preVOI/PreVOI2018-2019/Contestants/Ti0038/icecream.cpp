#include <bits/stdc++.h>

using namespace std;
int a[5],n,nm,x[25],kq=0;
void xl()
{   int b[5];
    for (int i=0;i<=2;i++) b[i]=a[i];
    for (int i=1;i<=n;i++)
    {
        if (x[i]==0) b[0]++;
        if (b[0]>nm) return;
        if (x[i]==1 && b[0]<=0) return;
        if (x[i]==1) b[1]++,b[0]--;
        if (b[1]>nm) return;
        if (x[i]==2)
        {
        if (b[0]>=1 && b[1]>=1) {b[0]--,b[1]--; b[2]++;}
        else if (b[1]==0 && b[0]>=3) {b[0]-=3; b[2]++;} else return;
        if (b[2]>nm) return;
    }
    }
    kq++;
}
void try1(int i)
{
    for (int j=0;j<=2;j++)
    {
        x[i]=j;
        if (i==n) xl();
        else try1(i+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("icecream.inp","r",stdin);
     freopen("icecream.out","w",stdout);
    cin>>n>>nm;
    cin>>a[0]>>a[1]>>a[2];
    try1(1);
    cout<<kq;
}
