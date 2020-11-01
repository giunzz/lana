#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db double
const int nmax = 2000 + 10;
ll m,n,k,sl,dd[nmax],kq,maxx = 0,summ;
struct tt
{
    db x,y,r;
    tt() {}
    tt(db x,db y,db r): x(x),y(y),r(r) {};
};
tt a[nmax],b[nmax],S;

void tinh(int u,int id)
{
    for(int i=1; i<=m; i++)
    {
        if(a[i].x - a[i].r <= S.x && S.x <= a[i].x + a[i].r)
        {
            if(a[i].x - a[i].r <= b[u].x && b[u].x <= a[i].x + a[i].r)continue;
            else
            {
                if(id == 1)
                {
                    if(dd[i] == 0)sl++;
                    dd[i]++;
                }
                else
                {
                    if(dd[i] == 1)sl--;
                    dd[i]--;
                }
            }
        }
        else
        {
            if(a[i].x - a[i].r <= b[u].x && b[u].x <= a[i].x + a[i].r)
            {
                if(id == 1)
                {
                    if(dd[i] == 0)sl++;
                    dd[i]++;
                }
                else
                {
                    if(dd[i] == 1)sl--;
                    dd[i]--;
                }
            }
            else if((S.x <= a[i].x && a[i].x <= b[u].x) || (b[u].x <= a[i].x && a[i].x <= S.x))
            {
                if(id == 1)
                {
                    if(dd[i] == 0)sl++;
                    dd[i]++;
                }
                else
                {
                    if(dd[i] == 1)sl--;
                    dd[i]--;
                }
            }
        }
    }
    if(id == 1)kq += b[u].r;
    else kq -= b[u].r;
}

void BT(int u)
{
    if(u == n+1)
    {
        maxx = max(maxx,kq);
        return;
    }
    for(int i=0; i<=1; i++)
    {
        if(i == 0)
        {
            BT(u+1);
        }
        else
        {
            tinh(u,1);
            if(sl > k)
            {
                tinh(u,0);
                return;
            }
            BT(u+1);
            tinh(u,0);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("TEAWORLD.inp","r",stdin);
    freopen("TEAWORLD.out","w",stdout);
    int ok = 1;
    cin >> m >> n >> k;
    for(int i=1; i<=m; i++)
    {
        ll u;
        cin >> a[i].x >> a[i].y;
        cin >> u;
        if(u != 0)ok = 0;
        cin >> a[i].r;
    }
    for(int i=1; i<=n; i++)
    {
        ll u;
        cin >> b[i].x >> b[i].y;
        cin >> u;
        if(u != 0)ok = 0;
        cin >> b[i].r;
        summ += b[i].r;
    }
    cin >> S.x >> S.y >> S.r;
    if(S.r != 0)ok = 0;
    if(ok == 1)
    {
        BT(1);
        cout << maxx;
    }
    else cout << summ;

    return 0;
}
