#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mn=4e3+5;
int n,del;
int l[mn],r[mn];
int f[mn];
int tr[mn];
int maxk,maxt;
void vet(int u)
{
    if(tr[u]!=0)vet(tr[u]);
        cout<<r[u]<<" ";
}
int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    cin>>n>>del;
    for(int i=1;i<=n;i++)cin>>l[i];
    for(int i=1;i<=n;i++)cin>>r[i];
    for(int i=1;i<=n;i++)
    {
        maxt=0;
        for(int j=1;j<=n;j++)
            {
              maxk=maxt;
              if(abs(r[j]-l[i])<=del)
                {
                    if(f[maxt]<f[j])maxt=j;
                    else if(f[maxt]==f[j])if(r[maxt]<r[j]&&maxt>0) maxt=j;
                }
              if(l[i]==r[j])
                {
                    if(f[j]<f[maxk]+1)
                    {
                        f[j]=max(f[j],f[maxk]+1);
                        tr[j]=maxk;
                    }
                }
            }
    }
int res=0;
    for(int i=1;i<=n;i++)
        if(f[res]<f[i])res=i;
        cout<<f[res]<<'\n';
        vet(res);
    return 0;
}

