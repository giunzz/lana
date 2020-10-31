#include <bits/stdc++.h>
#define task "LIONDANCE"
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define ii pair< int ,int >
#define fi first
#define se second
#define pb push_back
#define el '\n'
using namespace std;
const int N=4000+7;
int n,d,a[N],cnt,c[N],pos[N];
ii b[N];
vector <int> vt[N],f[N],prv[N];
vector < ii > t[N];
void input()
{
    cin >> n >> d;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n)
    {
        cin >> b[i].fi;
        b[i].se=i;
    }
    b[0]=ii(-1,-1);
}
void _trace(int u,int v)
{
    if(u==0) return;
    _trace(t[u][v].fi,t[u][v].se);
    cout << a[u] << ' ';
}
void process()
{
    sort(b+1,b+n+1);
    FOR(i,1,n)
    {
        if(b[i].fi!=b[i-1].fi) c[++cnt]=b[i].fi;
        vt[cnt].pb(b[i].se);
    }
    FOR(i,1,n)
    {
        int p=lower_bound(c+1,c+cnt+1,a[i])-c;
        if(c[p]==a[i])
        {
            f[i].resize(int(vt[p].size()),0);
            prv[i].resize(int(vt[p].size()),0);
            t[i].resize(int(vt[p].size()),ii(0,0));
            pos[i]=p;
        }
        else
        {
            pos[i]=n+4;
        }
    }
    vt[0].pb(0);
    f[0].pb(0);
    t[0].pb(ii(0,0));
    FOR(i,1,n)
        FORD(j,i-1,0)
            if(abs(a[i]-a[j]) <= d || j==0)
            {
                int cur=0;
                if(cur==int(f[j].size())) continue;
                for(int z=0;z<int(f[i].size());++z)
                {
                    if(z>0)
                    {
                        f[i][z]=f[i][z-1];
                        prv[i][z]=prv[i][z];
                        t[i][z]=t[i][z-1];
                    }
                    while( cur<int(f[j].size()) && vt[pos[j]][cur] < vt[pos[i]][z])
                    {
                        if(f[i][z]==f[j][cur]+1)
                        {
                            if(prv[i][z]<a[j])
                            {
                                prv[i][z]=a[j];
                                t[i][z]=ii(j,cur);
                            }
                        }
                        if(f[i][z]<=f[j][cur])
                        {
                            f[i][z]=f[j][cur]+1;
                            prv[i][z]=a[j];
                            t[i][z]=ii(j,cur);
                        }
                        ++cur;
                    }
                }
            }
    int res=0,resprv;
    ii _end;
    FOR(i,1,n)
            for(int z=0;z<int(f[i].size());++z)
                //cout << f[i][z] << " ";
                if(res<f[i][z])
                {
                    res=f[i][z];
                    resprv=a[i];
                    _end=ii(i,z);
                    //cout << f[i][z];
                }
                else
                    if(res==f[i][z] && resprv<a[i])
                    {
                        resprv=a[i];
                        _end=ii(i,z);
                    }
            //cout << '\n';
    //cout << _end.fi << _end.se;
    cout << res << el;
    _trace(_end.fi,_end.se);
}
int main()
{
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    ios::sync_with_stdio(false);cin.tie(NULL);
    input();
    process();
    return 0;
}
