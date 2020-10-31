#include<bits/stdc++.h>
#define maxn 2005
using namespace std;

struct data
{
    int x, y, z, r;
};
int n, m, k, xs, ys, zs, L[maxn], R[maxn], S[20][20];
long long F[20][20];
data a[maxn], b[maxn];

void solve()
{
    long long cmax = 0;
    for(int i=1;i<=m;i++)
    {
        for(int j=i;j<=m;j++)
        {
            if( b[i].x <= xs && xs <= b[j].x && S[i][j] <= k)
            {
                cmax = max(cmax, F[i][j]);
            }
        }
    }
    cout << cmax;
}

int cmp(data a,data b)
{
    return a.x < b.x;
}

void init()
{
    for(int i=1;i<=m;i++)
        for(int j=i;j<=m;j++)
        {
            F[i][j] = F[i][j-1] + b[j].r;
            for(int k=1;k<=n;k++)
            {
                int x = a[k].x + a[k].r;
                int y = a[k].x - a[k].r;
                if( b[i].x <= x && x <= b[j].x )
                    ++S[i][j];
                else if( b[i].x <= y && y <= b[j].x )
                    ++S[i][j];
            }
        }
}

int main()
{
    freopen("TEAWORLD.inp","r",stdin);
    freopen("TEAWORLD.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) // ball
    {
        cin>>a[i].x>>a[i].y>>a[i].z>>a[i].r;
    }
    for(int i=1;i<=m;i++) // milk
    {
        cin>>b[i].x>>b[i].y>>b[i].z>>b[i].r;
    }
    sort(b+1,b+m+1,cmp);
    cin>>xs>>ys>>zs;
    init();
    solve();
}
