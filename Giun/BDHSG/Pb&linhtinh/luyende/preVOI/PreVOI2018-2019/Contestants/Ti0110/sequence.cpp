#include <bits/stdc++.h>
using namespace std;
int a[3001],b[3001],m,n,k;
int ans[6001] , ans2[6001];
int main()
{
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    cin>>m>>n>>k;
    for (int i=1;i<=m;i++) cin>>a[i];
    sort(a+1,a+1+m);
    for (int i=1;i<=n;i++) cin>>b[i];
    sort(b+1,b+1+n);
    for (int i=1;i<=m;i++)
    {
            if (a[i] > b[1] && k-i+1 <= n)
            {
                for (int j=i;j<=k;j++)
                {
                    ans[j] = b[j-i+1];
                }
                break;
            }
            else ans[i] = a[i];
    }
  //  for (int i=1;i<=k;i++) cout<<ans[i]<<" ";cout<<endl;

    for (int i=1;i<=n;i++)
    {
            if (b[i] > a[1] && k-i+1 <= m)
            {
                for (int j=i;j<=k;j++)
                {
                    ans2[j] = a[j-i+1];
                }
                break;
            }
            else ans2[i] = b[i];
    }
  //  for (int i=1;i<=k;i++) cout<<ans2[i]<<" ";cout<<endl;
    bool kt = false;
    for (int i=1;i<=k;i++)
    if (ans[i] != ans2[i])
    {
        kt = ans[i] < ans2[i];
        break;
    }
    if (kt == true) for (int i=1;i<=k;i++) cout<<ans[i]<<" ";
    else for (int i=1;i<=k;i++) cout<<ans2[i]<<" ";cout<<endl;

    return 0;
}
