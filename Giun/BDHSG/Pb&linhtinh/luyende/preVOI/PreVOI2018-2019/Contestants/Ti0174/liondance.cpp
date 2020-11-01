#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define endl "\n"
#define task "liondance"
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
const int N=4005;
int n,l[N],r[N],dt,tra[N][N],trb[N][N],f[N][N],vta[N],vtb[N],tr[N][N];
vector <vector<int> > v;
void trace(int i, int j)
{
    if (i>0 && j>0)
    {
        if (f[i][j]==f[tra[i][j]][trb[i][j]]+1)
            {
                trace(tra[i][j],trb[i][j]);
                //v.back().push_back(l[i]);
                cout<<l[i]<<" ";
            }
        else
            if (f[i][j]==f[i-1][j])
                trace(i-1,j);
        else if (f[i][j]==f[i][j-1])
            trace(i,j-1);
    }
}
bool cmp(vector <int> a, vector <int> b)
{
    for (int i=0; i<a.size(); ++i)
        if (a[i]<b[i]) return 1;
    return 0;
}
void sub1()
{
        for (int i=1; i<=n; ++i)
        {
            for (int j=1;j<=n;++j)
            {
                if (l[i]==r[j])
                {
                    int mx=0;
                    for (int k=1; k<i; ++k)
                    for (int h=1; h<j; ++h)
                    {
                        if (abs(r[j]-r[h])<=dt && abs(l[i]-l[k])<=dt && mx<=f[k][h])
                            {mx=f[k][h];
                            tra[i][j]=k;
                            trb[i][j]=h;
                            tr[i][j]=k;
                            }
                    }
                    f[i][j]=mx+1;
                }
                else
                {
                    f[i][j]=max(f[i-1][j],f[i][j-1]);
                }
                //vta[f[i][j]]=i;
                //vtb[f[i][j]]=j;
                //cout<<f[i][j]<<" ";
            }
            //cout<<endl;
        }
    cout<<f[n][n]<<endl;
    trace(n,n);
    /*for (int i=1; i<=n; ++i)
    {
        for (int j=1; j<=n; ++j)
            if (f[i][j]==f[n][n])
        {v.PB(vector<int>());
            trace(i,j);
        }
    }*/
    /*if (!v.empty())
    {
        sort(v.begin(),v.end(),cmp);
        for (auto x:v.back())
            cout<<x<<" ";
    }*/
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>dt;
    for (int i=1; i<=n; ++i) cin>>l[i];
    for (int i=1;i<=n;++i) cin>>r[i];
    if (n<=20)
    {
        sub1();
        return 0;
    }
    return 0;
}
