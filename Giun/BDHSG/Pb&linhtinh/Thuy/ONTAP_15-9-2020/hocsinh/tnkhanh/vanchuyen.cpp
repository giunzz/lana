#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int n,k,ans;
vector<pair<int,int> >a;
vector<int>c;
priority_queue<int>q;
main()
{
    freopen("vanchuyen.inp","r",stdin);
    freopen("vanchuyen.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    a.resize(n);
    c.resize(k);
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    for(int i=0;i<k;i++)cin>>c[i];
    sort(a.begin(),a.end());
    sort(c.begin(),c.end());
    int l=0;
    for(int i=0;i<k;i++)
    {
        while(l<n&&c[i]>=a[l].first)
        {
            q.push(a[l].second);
            l++;
        }
        if(!q.empty()){ans+=q.top();q.pop();}
    }
    cout<<ans<<endl;
    return 0;
}
