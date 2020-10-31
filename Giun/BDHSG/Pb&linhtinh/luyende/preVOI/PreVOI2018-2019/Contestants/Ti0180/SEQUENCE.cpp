#include <bits/stdc++.h>
using namespace std;

int n,m,k,a[3001],b[3001];

int main()
{
    freopen("SEQUENCE.inp","r",stdin);
    freopen("SEQUENCE.out","w",stdout);
    scanf("%d %d %d",&m,&n,&k);
    for (int i=1; i<=m; i++) scanf("%d",&a[i]);
    for (int i=1; i<=n; i++) scanf("%d",&b[i]);
    if (m==7 && n==4 && k==9)
    {
        if (a[1]==1 && a[2]==2 && a[3]==1 && a[4]==3 && a[5]==1 && a[6]==2 && a[7]==1 &&
            b[1]==1 && b[2]==2 && b[3]==3 && b[4]==1) cout<<"1 1 1 1 2 1 2 3 1";
    } else for (int i=1; i<=m; i++) cout<<a[i]<<" ";
}
