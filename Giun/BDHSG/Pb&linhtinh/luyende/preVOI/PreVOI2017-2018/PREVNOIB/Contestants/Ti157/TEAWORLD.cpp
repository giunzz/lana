#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define ii pair<int, int>
#define mod 1e9+7;
#define HANH "TEAWORLD"
using namespace std;
int m, n, k, f[5000], s[5000], sua[5000], u, v, c, h, hanh[5000], th[5000];
vector <int> nho[5000];
int main()
{
    ios_base::sync_with_stdio(0);
    freopen(HANH".inp", "r", stdin);
    freopen(HANH".out", "w", stdout);
    cin >>m >>n >>k;
    for(int i=1; i<=m; ++i)
    {
        cin >>u >>v >>c >>h;
        ++f[u+1000-h];
        ++f[u+1000+h];
        ++s[u+1000-h];
        ++s[u+1000+h];
        nho[u+1000-h].push_back(u+1000+h);
        nho[u+1000+h].push_back(u+1000-h);
    }
    for(int i=1; i<=n; ++i) cin >>u >>v >>c >>h, sua[u+1000]+=h;
    h=0;
    cin >>u >>v >>c;
    u+=1000;nho[u+1000-h].push_back(u+1000+h);
    for(int i=u; i<=1500; ++i)
    {
        hanh[h]+=sua[i];
        if(f[i]>0)
        {
            int hh=h;
            h+=f[i];
            f[i]=0;
            for(int j=hh+1; j<h; ++j) hanh[j]=hanh[hh];
            for(int j=0; j<nho[i].size(); ++j) --f[nho[i][j]];
        }
    }
    h=0;
    for(int i=u-1; i>=500; --i)
    {
        th[h]+=sua[i];
        if(s[i]>0)
        {
            int hh=h;
            h+=s[i];
            s[i]=0;
            for(int j=hh+1; j<h; ++j) th[j]=th[hh];
            for(int j=0; j<nho[i].size(); ++j) --s[nho[i][j]];
        }
    }
    int kq=0;
    for(int i=0; i<=k; ++i) kq=max(kq, hanh[i]+th[k-i]);
    cout <<kq;
}
