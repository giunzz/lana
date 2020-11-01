#include <bits/stdc++.h>
#define ll long long
#define N 4005

using namespace std;

map<ll,ll> t;
ll n,k,a[N],b[N],f[N][N],res,res1,MAX,kq[N];

int main()
{
    ios::sync_with_stdio(false);
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    res=-1e17;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        if (a[i]==b[j])
        {
            MAX=-1e17;
            f[i][j]=1;
            for(int x=1;x<=i-1;x++)
                for (int y=1;y<=j-1;y++)
                    if (a[x]==b[y] && abs(a[x]-a[i])<=k){
                        if (f[i][j]<f[x][y]+1)
                        {
                            f[i][j]=f[x][y]+1;
                            t[i]=x;
                            MAX=a[x];
                        }
                        else
                        if (f[i][j]==f[x][y]+1 && a[x]>MAX) {
                                MAX=a[x];
                                t[i]=x;
                        }
                    }

            if (f[i][j]>res) {
                res=f[i][j];
                res1=i;
            }
        }
    cout<<res<<"\n";
    ll d=0;
    while (t[res1]>0)
    {
        kq[++d]=a[res1];
        res1=t[res1];
    }
    kq[++d]=a[res1];
    for (int i=d;i>=1;i--) cout<<kq[i]<<" ";
    return 0;
}
