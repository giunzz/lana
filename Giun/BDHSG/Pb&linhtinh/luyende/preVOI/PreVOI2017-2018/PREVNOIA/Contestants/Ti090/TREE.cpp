#include <bits/stdc++.h>

using namespace std;

const int maxN=5011;
const long long oo=1e18+11;

int n, maxlv;
long long a[maxN], val[maxN], res;
vector<int> vt[maxN], lv[maxN], leaf;

void Visit(int x, int parx, int lvx)
{
    lv[lvx].push_back(x);
    maxlv=max(maxlv, lvx);
    for (int i=0; i<vt[x].size(); i++)
    {
        int y=vt[x][i];
        if (y==parx)
        {
            vt[x][i]=vt[x].back();
            vt[x].pop_back();
            i--;
            continue;
        }
        Visit(y, x, lvx+1);
    }
    if (vt[x].size()==0) leaf.push_back(x);
}

void check()
{
    long long ope=0;
    for (int i=maxlv; i>=1; i--)
        for (int j=0; j<lv[i].size(); j++)
        {
            int x=lv[i][j], siz=vt[x].size();
            if (siz==1) val[x]=val[vt[x][0]];
            if (siz==2) val[x]=val[vt[x][0]]+val[vt[x][1]];
            ope+=abs(a[x]-val[x]);
        }
    res=min(res, ope);
}

void Try(int i)
{
    for (int j=0; j<=1; j++)
    {
        val[leaf[i]]=j;
        if (i==leaf.size()-1) check();
        else Try(i+1);
    }
}

int main()
{
    freopen("TREE.INP", "r", stdin);
    freopen("TREE.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=n-1; i++)
    {
        int u, v; cin>>u>>v;
        vt[u].push_back(v);
        vt[v].push_back(u);
    }
    if (n<=30)
    {
        res=oo;
        Visit(1, 1, 1);
        Try(0);
        cout<<res;
    }
    return 0;
}
