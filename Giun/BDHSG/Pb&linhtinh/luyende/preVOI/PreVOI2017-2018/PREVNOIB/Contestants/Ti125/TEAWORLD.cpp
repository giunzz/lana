#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxm=2001, maxn = 16;
int m, n, k;
int gr[maxm], vl[maxm], gv[maxm];
bool br[maxm];
struct TPoint
{
    int x, y, z, c;
    TPoint(int x = 0, int y = 0, int z = 0, int c = 0) : x(x), y(y), z(z), c(c) {}
};

TPoint c[maxm], t[maxn], xp;

int read_int()
{
    int kq = 0, sign = 1;
    char c = getchar();
    while (c <'0' || c > '9')
    {
        if (c == '-')
            sign = -1;
        c = getchar();
    }
    while (c >= '0' && c <='9')
        kq = kq*10+c-'0', c = getchar();
    return kq*sign;
}
int s = 0;
int main()
{
    freopen("TEAWORLD.INP", "r", stdin);
    freopen("TEAWORLD.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    m = read_int();
    n = read_int();
    k = read_int();
    memset(vl, 0, sizeof(vl));
    bool nX = true, nY = true, nZ = true;
    for (int i = 1; i<=m; i++)
    {
        int x = read_int()+500, y = read_int(), z = read_int(), v = read_int();
        c[i].x = x;
        c[i].y = y;
        c[i].z = z;
        c[i].c = v;
    }
    for (int i = 1; i<=n; i++)
    {
        int x = read_int()+500, y = read_int(), z = read_int(), v = read_int();
        t[i].x = x;
        t[i].y = y;
        t[i].z = z;
        t[i].c = v;
        vl[x]+=v;
        nX = nX && !x;
        nY = nY && !y;
        nZ = nZ && !z;
        //cout << x << " " <<y << " " << z << " " << v<< endl;
        s+=v;
    }
    int tx = read_int(), ty = read_int(), tz = read_int();
    xp = TPoint(tx+500,ty,tz,0);
    if (k == m)
        cout << s;
    else if (/*nY && nZ*/true)
    {
        for (int i = 1; i<=m; i++)
        {
            for (int j = c[i].x-c[i].c; j<=c[i].x+c[i].c; j++)
                gr[j] = i;
        }
        if (k == 0)
        {
            int c = vl[xp.x], i= xp.x-1;
            while (gr[i] == gr[xp.x])
                c+=vl[i], i--;
            i = xp.x+1;
            while (gr[i] == gr[xp.x])
                c+=vl[i], i++;
            cout << c;
        }
        else
        {
            int c = vl[xp.x], i= xp.x-1;
            if (gr[xp.x] !=0)
            {
                k--;
                br[gr[xp.x]]= true;

                while (gr[i] == gr[xp.x] || gr[i] == 0)
                    c+=vl[i], i--;

                i = xp.x+1;
                while (gr[i] == gr[xp.x] || gr[i] == 0)
                    c+=vl[i], i++;
            }
            int b = xp.x, og = 0, bg = 0, l, r;
            while (gr[xp.x] == gr[b] || 0 == gr[b])
                b++;
            r =b;
            for (int i = b; i<=1000; i++)
            {
                if (og != gr[i]&& gr[i] !=0)
                    og = gr[i], bg = i;
                gv[bg]+= vl[i];
            }

            b = xp.x, og=0, bg=0;
            while (gr[xp.x] == gr[b] || 0 == gr[b])
                b--;
            l = b;
            for (int i = b; i>=0; i--)
            {
                if (og != gr[i] && gr[i] !=0)
                    og = gr[i], bg = i;
                gv[bg]+= vl[i];
            }
            /*cout << endl;
            for (int i = 0; i<=1000; i++)
                cout << i << " " << vl[i] << endl;
            */
            while (k)
            {
                while (gv[r] == 0 && r <1000)
                    r++;
                while (gv[l] == 0 && l >=0)
                    l--;
                if (gv[r] > gv[l])
                    c+=gv[r], gv[r] = 0;
                else
                    c+=gv[l], gv[l] = 0;
                k--;
            }
            cout << c;
        }
    }
    return 0;
}
