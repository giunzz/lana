#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORD(i,a,b) for(int i=a; i>=b; i--)
#define ii pair<int,int>
#define iii pair<int,ii>
#define F first
#define S second
using namespace std;

const int N=3e3+100;
int m,n,k;
int a[3][N];
int id[3][4*N],vt[3][4*N];
int val,pos;
vector< vector<int> > res;

void kt(int k, int l, int r, int t)
{
    if (l==r)
    {
        id[t][k]=a[t][l];
        vt[t][k]=l;
        return;
    }

    int m=(l+r)/2;
    kt(k*2,l,m,t);
    kt(k*2+1,m+1,r,t);

    id[t][k]=min(id[t][k*2],id[t][k*2+1]);
    if (id[t][k*2]<=id[t][k*2+1]) vt[t][k]=vt[t][k*2];
    else vt[t][k]=vt[t][k*2+1];
}

void tv(int k, int l, int r, int u, int v, int t)
{
    if (u>r || v<l) return;
    if (u<=l && v>=r)
    {
        if (id[t][k]<val) pos=vt[t][k];
        if (id[t][k]==val) pos=min(pos,vt[t][k]);
        val=min(val,id[t][k]);
        return;
    }

    int m=(l+r)/2;

    tv(k*2,l,m,u,v,t);
    tv(k*2+1,m+1,r,u,v,t);

}

bool cmp1(vector<int> a, vector<int> b)
{
    if (a.size()==0) return false;
    if (b.size()==0) return true;
    FOR(i,0,min(a.size(),b.size())-1)
    {
        if (a[i]<b[i]) return true;
        if (b[i]<a[i]) return false;
    }
    return (a.size()<b.size());
}
int main()
{
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>m>>n>>k;
    FOR(i,1,m) cin>>a[1][i];
    kt(1,1,m,1);
    FOR(i,1,n) cin>>a[2][i];
    kt(1,1,n,2);

    FOR(i,0,k)
    {
        int la=i,lb=k-i;
        if (la<=m && lb<=n);
        else continue;

        vector<int> a,b,c;

        pos=0;
        FORD(j,la,1)
        {
            pos++;
            val=1e9;
            tv(1,1,m,pos,m-j+1,1);
            a.push_back(val);
        }

        pos=0;
        FORD(j,lb,1)
        {
            pos++;
            val=1e9;
            tv(1,1,n,pos,n-j+1,2);
            b.push_back(val);
        }

        while (!a.empty() || !b.empty())
        {
            if (cmp1(a,b))
            {
                c.push_back(a[0]);
                a.erase(a.begin());
            }
            else
            {
                c.push_back(b[0]);
                b.erase(b.begin());
            }
        }
        res.push_back(c);

    }

    sort(res.begin(),res.end(),cmp1);

    FOR(i,0,res[0].size()-1)
        cout<<res[0][i]<<' ';
}
