#include <iostream>
#include <fstream>
#include <queue>
#define int long long
using namespace std;
int n,k,a[101],m,ans=0;
priority_queue<int>q;
main()
{
    freopen("noise.inp","r",stdin);
    freopen("noise.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[x]++;
    }
    for(int i=1;i<=m;i++)
    {
        q.push(a[i]);
        ans+=a[i]*(a[i]+1)/2;
    }
    for(int i=1;i<=k;i++)
    {
        int u=q.top();q.pop();
        ans-=u*(u+1)/2;
        int tmp=u/2;
        ans+=tmp*(tmp+1)/2+(u-tmp)*(u-tmp+1)/2;
        q.push(tmp);
        q.push(u-tmp);
    }
    cout<<ans<<endl;
    return 0;
}
