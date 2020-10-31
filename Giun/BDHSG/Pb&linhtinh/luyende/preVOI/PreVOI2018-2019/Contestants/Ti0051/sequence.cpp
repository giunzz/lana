#include <bits/stdc++.h>
#define PII pair<int,int>
#define F first
#define S second
#define LL long long
using namespace std;
int m,n,k,a[3001],b[3001],f[6001];
vector <int> vec,v[3001];
int main()
{
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    ios_base::sync_with_stdio();
    cin.tie(0);cout.tie(0);
    cin>>m>>n>>k;
    for (int i=1;i<=m;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=k;i++) f[i]=1e9;
    for (int i=1;i<=m;i++)
    if (i<=k)
    {
        int d=i;
        deque <int> q;
        for (int j=1;j<=m;j++)
        {
            while (!q.empty()&&a[q.back()]>a[j]) q.pop_back();
            q.push_back(j);
            if (j==m-d+1) v[i].push_back(a[q.front()]),q.pop_front(),d--;
        }
    }
    for (int i=0;i<=n;i++)
    if (i<=k&&k-i<=m)
    {
        int d=i;
        vec.clear();
        deque <int> q;
        for (int j=1;j<=n;j++)
        {
            while (!q.empty()&&b[q.back()]>b[j]) q.pop_back();
            q.push_back(j);
            if (j==n-d+1) vec.push_back(b[q.front()]),q.pop_front(),d--;
        }
        int c=k-i,i1=0,i2=0,i3=0,tt=0;
        while (i3<k)
        {
            int x=i1,y=i2,kt=0;
            i3++;
            while  (x<vec.size()&&y<v[c].size()&&vec[x]==v[c][y]) x++,y++;
            if (x==vec.size()||(y<v[c].size()&&vec[x]>v[c][y])) kt=1;
            if (i1<vec.size()) x=vec[i1];
            if (i2<v[c].size()) y=v[c][i2];
            if (kt==0)
            {
                if (x>f[i3]&&tt==0) break;
                else
                {
                    if (tt==0&&x<f[i3]) tt=1;
                    f[i3]=x;
                }
                i1++;
            }
            else
            {
                if (y>f[i3]&&tt==0) break;
                else
                {
                    if (tt==0&&y<f[i3]) tt=1;
                    f[i3]=y;
                }
                i2++;
            }
        }
    }
    //cout<<v[c]
    for (int i=1;i<=k;i++) cout<<f[i]<<" ";
    return 0;
}
