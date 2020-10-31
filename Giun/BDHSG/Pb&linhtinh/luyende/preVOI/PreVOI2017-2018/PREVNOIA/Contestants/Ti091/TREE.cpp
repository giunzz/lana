#include<bits/stdc++.h>
#define mn 5005
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORE(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
long long n,a[mn],u,v,kq=0,dem=0,cha[mn];
vector <int> d[mn];
void dt(int u)
{
    if(d[u].size()==0)
    {
        if(a[cha[u]]>=2)
            {
                kq+=abs(a[u]-1);
                a[u]=1;
            }
        else
        {
            kq+=a[u];
            a[u]=0;
        }

    }
    else
    {
        long long tam=0;
        FOR(i,0,d[u].size()-1)
        {
            dt(d[u][i]);
            tam+=a[d[u][i]];
        }
        kq+=abs(a[u]-tam);
        a[u]=tam;
    }
}
void nhap()
{
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    while(cin>>u>>v)
    {
        d[u].push_back(v);
        cha[v]=u;
    }
    dt(1);
    cout<<kq;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TREE.inp","r",stdin);
    freopen("TREE.out","w",stdout);
    nhap();
    return 0;
}

