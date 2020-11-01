#include <bits/stdc++.h>
#define int long long
using namespace std;
bool used[123];
int bt[123];
const int Nmax=1e5+7;
int n,a[Nmax],la[Nmax],cnt=0;
vector<int>vt[Nmax];
int trace[Nmax],save[Nmax],nw[Nmax];
vector<int>A,B;
main()
{
    freopen("TREE.inp","r",stdin);
    freopen("TREE.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int Min=1e13+7;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        save[i]=a[i];
    }
    for (int i=1; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        vt[u].push_back(v);
        trace[v]=u;
    }
    for (int i=1; i<=n; i++)
    {
        if (vt[i].size()==0) la[++cnt]=i;
    }
    for (int i=0; i <= (1<<cnt) ; i++)
    {
        A.clear();
        B.clear();
        int ans=0;
        for (int j=0 ; j < cnt; j++)
            if ((i&(1<<j))!=0)
                A.push_back(j+1);
            else
                B.push_back(j+1);

        for (int i=0;i<A.size();i++)
        {
            //ans+=a[la[A[i]]];
            nw[la[A[i]]]=0;
        }
        for (int i=0;i<B.size();i++)
        {
            //ans+=abs(a[la[B[i]]]-1);
            nw[la[B[i]]]=1;
        }
        for (int i=1;i<=cnt;i++)
        {
            int f=la[i];
            while (f!=0)
            {
                nw[trace[f]]+=nw[la[i]];
                f=trace[f];
            }
        }
        //for (int i=1;i<=n;i++) cout<<nw[i]<<" ";cout<<endl;
        for (int i=1;i<=n;i++)
        ans+=abs(a[i]-nw[i]);
        Min=min(Min,ans);
        memset(nw,0,sizeof (nw));
    }
    cout<<Min;
    return 0;
}
