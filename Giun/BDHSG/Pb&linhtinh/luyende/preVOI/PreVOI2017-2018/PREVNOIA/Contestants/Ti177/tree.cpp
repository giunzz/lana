#include <bits/stdc++.h>
#define nmax 5007
#define vc 9999999999

using namespace std;

long long n,w[nmax],w1[nmax],la[nmax],ans=vc,tt;
vector <long> a[nmax];

long long dfs(long u)
{
    if (la[u]==0) return w1[u];
    long long v[5];
    v[1]=-1;
    v[2]=-1;
    for (long i=0; i<a[u].size(); i++) v[i+1]=a[u][i];
    if (v[2]==-1)
    {
        long long g=dfs(v[1]);
        tt+=abs(w1[u]-g);
        w1[u]=w1[g];
        return w1[u];
    }
    else
    {
        long long g1=dfs(v[1]), g2=dfs(v[2]);
        tt+=abs(w1[u]-g1-g2);
        w1[u]=g1+g2;
        return w1[u];
    }
}

void tinh1()
{
    tt=0;
    for (long i=1; i<=n; i++) w1[i]=w[i];
    for (long i=1; i<=n; i++)
      if (la[i]==0)
      {
         tt+=abs(1-w1[i]);
         w1[i]=1;
      }
    dfs(1);
    ans=min(ans,tt);
}

void tinh2()
{
    tt=0;
    for (long i=1; i<=n; i++) w1[i]=w[i];
    for (long i=1; i<=n; i++)
      if (la[i]==0)
      {
         tt+=abs(0-w1[i]);
         w1[i]=0;
      }
    dfs(1);
    ans=min(ans,tt);
}

void tinh3()
{
    tt=0;
    for (long i=1; i<=n; i++) w1[i]=w[i];
    dfs(1);
    ans=min(ans,tt);
}

void tinh4()
{
    tt=0;
    long long sumla=0;
    for (long i=1; i<=n; i++) w1[i]=w[i];
    for (long i=1; i<=n; i++)
      if (la[i]==0) sumla+=w1[i];

    if (sumla>w1[1])
    {
        long long hs=sumla-w1[1];
        long i=1;
        while (hs>0)
        {
            if (la[i]==0 && w1[i]==1)
            {
                tt+=abs(0-w1[i]);
                w1[i]=0;
                hs--;
            }
            i++;
            if (i>n) break;
        }
    }
    else if (sumla<w1[1])
    {
        long long hs=-sumla+w1[1];
        long i=1;
        while (hs>0)
        {
            if (la[i]==0 && w1[i]==0)
            {
                tt+=abs(1-w1[i]);
                w1[i]=1;
                hs--;
            }
            i++;
            if (i>n) break;
        }
    }
    dfs(1);
    ans=min(ans,tt);
}

void tinh5()
{
    tt=0;
    long long sumla=0;
    for (long i=1; i<=n; i++) w1[i]=w[i];
    for (long i=1; i<=n; i++)
      if (la[i]==0) sumla+=w1[i];

    if (sumla>w1[1])
    {
        long long hs=sumla-w1[1];
        long i=n;
        while (hs>0)
        {
            if (la[i]==0 && w1[i]==1)
            {
                tt+=abs(0-w1[i]);
                w1[i]=0;
                hs--;
            }
            i--;
            if (i<1) break;
        }
    }
    else if (sumla<w1[1])
    {
        long long hs=-sumla+w1[1];
        long i=n;
        while (hs>0)
        {
            if (la[i]==0 && w1[i]==0)
            {
                tt+=abs(1-w1[i]);
                w1[i]=1;
                hs--;
            }
            i--;
            if (i<1) break;
        }
    }
    dfs(1);
    ans=min(ans,tt);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("tree.inp","r",stdin);
    freopen("tree.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> w[i];
    for (long i=1; i<=n-1; i++)
    {
        long u,v;
        cin >> u >> v;
        la[u]=1;
        a[u].push_back(v);
    }
    if (n==1)
    {
        cout << min(abs(0-w[1]),abs(1-w[1]));
        return 0;
    }
    tinh1();
    tinh2();
    tinh3();
    tinh4();
    tinh5();
    cout << ans;
}
