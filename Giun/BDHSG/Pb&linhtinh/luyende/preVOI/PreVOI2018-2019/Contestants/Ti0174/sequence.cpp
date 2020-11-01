#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define endl "\n"
#define task "sequence"
using namespace std;
template <typename T> inline void R(T &x)
{
    bool neg=false;
    register int c;
    x=0;
    c=getchar();
    if (c=='-')
    {
        neg=true;
        c=getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        x=(x>>1)+(x>>3)+c-48;
    if (neg) x=-x;
}
const int M=3005;
const int N=M;
const int mx=1<<20;
int n,m,a[M],b[N],k,c[N],bb[2*N];
int get(int x, int i)
{
    return (x>>i)&1;
}
vector <int> m1[N],m2[N],v;
vector <int>::iterator it;
vector <vector<int> >ans;
bool cmp(vector <int> a, vector<int>b)
{
    if (a.size()!=b.size()) {
    return (a.size()<b.size());
    }
    else
    {
        for (int i=0; i<a.size(); ++i)
        if (a[i]<b[i]) return 1;
        return 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>m>>n>>k;
    v.resize(n+m+1);
    for (int i=1; i<=m; ++i) cin>>a[i];
    for (int j=1; j<=n; ++j) cin>>b[j];
    //sort(a+1,a+1+m);
    //sort(b+1,b+1+n)
    for (int x=0; x<(1<<m); ++x)
    {
        for (int i=1; i<=m; ++i)
            if (get(x,i-1))
            {
                m1[x].push_back(a[i]);
            }
    }
    for (int x=0; x<(1<<n); ++x)
    {
        for (int i=1; i<=n; ++i)
            if (get(x,i-1))
            {
                m2[x].push_back(b[i]);
            }
    }
    for (int x=0; x<(1<<m); ++x)
    {
        for (int s=0; s<(1<<n); ++s)
        {
            int mm=m1[x].size(), nn=m2[s].size();
            int last=0;
            int d=0;
            fill(bb+1,bb+1+n+m,0);
            for (int j=1; j<=nn; ++j)
                bb[j]=m2[s][j-1];
            bool stop=0;
            for (int k=0; k<mm; ++k)
            {
                bool ok=0;
                for (int j=last+1; j<=nn; ++j)
                {
                    if (bb[j]>=m1[x][k])
                    {
                        for (int jj=j+1; jj<=nn+1; ++jj)
                            bb[jj]=bb[jj-1];
                        bb[j]=m1[x][k];
                        last=j;
                        ++nn;
                        ok=1;
                        break;
                    }
                }
                if (!ok){for (int t=k; t<mm; ++t)
                    {
                        ++nn;
                        bb[nn]=m1[x][t];
                    }
                stop=1;}
                if (stop) break;
            }
            v.clear();
            ans.push_back(vector<int>());
            for (int j=0; j<nn; ++j)
                ans.back().push_back(bb[j+1]);
        }
    }
    //for (auto x:ans[0]) cout<<x<<" ";
    sort(ans.begin(),ans.end(),cmp);
    for (auto x:ans[0]) cout<<x<<" ";
    return 0;
}
