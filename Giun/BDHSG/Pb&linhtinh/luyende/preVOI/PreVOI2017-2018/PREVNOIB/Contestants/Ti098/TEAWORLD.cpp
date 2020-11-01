#include <bits/stdc++.h>
#define FILE "TEAWORLD"
const int N = 15,M = 2007,oo = 1e9+7;
using namespace std;
int m,n,k,e[N],dd[N][M],f[(1<<N)],bit[(1<<N)][M],tam[M],ans;
struct point
{
    int x,y,z,e;
    double r;
} a[N],b[N],s;

int getbit(int i,int j)
{
    return ((i>>j)&1);
}

point vect(point a,point b)
{
    point tmp;
    tmp.x = (b.x-a.x);
    tmp.y = (b.y-a.y);
    return tmp;
}

double calc_1(point a,point b)
{
    return (sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}

double calc_2(point a,point b,point c)
{
    double kc1 = calc_1(a,b),kc2 = calc_1(a,c),kc3 = calc_1(b,c);
    double tmp = (kc1 + kc2 + kc3)/2;
    double tmp2 = (sqrt(tmp*(tmp-kc1)*(tmp-kc2)*(tmp-kc3))/ kc3)* 2;
    return tmp2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin.tie(0);cout.tie(0);
    cin >> m >> n >> k;
    for (int i=1;i<=m;++i) cin >> a[i].x >> a[i].y >> a[i].z >> a[i].r;
    for (int i=1;i<=n;++i) cin >> b[i].x >> b[i].y >> b[i].z >> b[i].e;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
        {
            double tmptmp1 = calc_1(s,a[j]);
            double tmptmp2 = calc_1(b[i],a[j]);
            if (tmptmp1<=a[j].r && tmptmp2<=a[j].r) continue;
            else
            {
                double tmp = calc_2(a[j],b[i],s);
                if (tmp!=0)
                {
                    if (a[j].r>=tmp) dd[i][j] = 1;
                } else
                {
                    double tmp1 = calc_1(s,a[j])+calc_1(a[j],b[i]);
                    double tmp3 = calc_1(s,b[i]);
                    if (tmp1==tmp3) dd[i][j] = 1;
                }
            }
        }
    for (int i=0;i<(1<<n);++i)
    {
        if (f[i]==-oo) continue;
        for (int j=0;j<n;++j) if (!getbit(i,j))
        {
            int tmp = 0;
            for (int kk=1;kk<=m;++kk)
            {
                tam[kk] = bit[i][kk];
                if (dd[j+1][kk]==1) tam[kk] = 1;
                if (tam[kk]) tmp++;
            }
            if (tmp<=k)
            {
                if (f[i+(1<<j)] < f[i]+b[j+1].e)
                {
                    f[i+(1<<j)] = f[i]+b[j+1].e;
                    for (int kk=1;kk<=m;++kk) if (tam[kk]==1) bit[i+(1<<j)][kk] = tam[kk];
                }
            } else f[i+(1<<j)] = -oo;
        }
    }
    for (int i=0;i<(1<<n);++i) ans = max(ans,f[i]);
    cout << ans;
    return 0;
}
