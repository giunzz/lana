#include <bits/stdc++.h>

using namespace std;
    const int maxn = 3000 + 5;
    int m,n,k,a[maxn],b[maxn],con,chua,mi,saved[maxn],d;
    bool f[maxn];
int main()
{
    freopen("SEQUENCE.inp","r",stdin);
    freopen("SEQUENCE.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>n>>k;
    for (int i=1; i<=m; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        cin>>b[i];
    con=m+n;
    chua=k;
    memset(saved,0,sizeof(saved));
    memset(f,true,sizeof(f));
    d=0;
    int j1=0;
    for (int i=1; i<=m; i++)
    {
        if (d==k)
        {
            break;
        }
        if (con==chua)
        {
            d=d+1;
            saved[d]=min(a[i],b[j1]);
            d++;
            saved[d]=max(a[i],b[j1]);
            con=con-2;
            chua=chua-2;
        }
        else
        {
            mi=1e6;
            for (int j=j1+1; j<=n; j++)
            {
                if (b[j]<mi&&f[j]==true)
                {
                    mi=b[j];
                    f[j]=false;
                    j1=j;
                }
            }
            {
                saved[++d]=min(mi,a[i]);
                con--;
                chua--;
            }
        }
    }
    for (int i=1; i<=k; i++)
        cout<<saved[i]<<' ';
}
