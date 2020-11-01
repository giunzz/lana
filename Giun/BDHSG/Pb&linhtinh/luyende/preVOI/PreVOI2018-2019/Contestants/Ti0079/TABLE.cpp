#include <bits/stdc++.h>
using namespace std;
long long hang,cot,up[301][301],down[301][301],m[301][301],q;
void inp()
{
    cin >> hang >> cot >> q;
    for (int i = 1 ; i <= hang ; i++)
    for (int e = 1 ; e <= cot ;e++) cin >> m[i][e];// , cout <<m[i][e]<<" ";
 //   cout <<""<<endl;
}
void create(long long h1, long long c1 , long long h2 , long long c2)
{
    down[h1][c1] = m[h1][c1];
    for (long long e = h1 ; e <= h2 ; e++)
    for (long long f = c1 ; f <= c2 ; f++)
    {
        if (e == h1 && f == c1) continue;
        down[e][f] = -1e15;
        if (e != h1) down[e][f] = down[e-1][f];
        if (f != c1) down[e][f] = max(down[e][f] , down[e][f-1]);
        down[e][f] += m[e][f];
    //    cout <<"down["<<e<<"]["<<f<<"] : "<<down[e][f]<<"\n";
    }
    up[h2][c2] = m[h2][c2];
    for (long long e = h2 ; e >= h1 ; e--)
    for (long long f = c2 ; f >= c1 ; f--)
    {
        if (e == h2 && f == c2) continue;
        up[e][f] = -1e15;
        if (e != h2) up[e][f] = up[e+1][f];
        if (f != c2) up[e][f] = max(up[e][f] , up[e][f+1]);
        up[e][f] += m[e][f];
    }
}
long long check(long long h1 , long long c1 , long long h2 , long long c2)
{
    long long kq = 1e15 , t = 1e15;
    if (h1 == h2 && c1 == c2) return 0;
    if (h1 == h2 || c1 == c2)
    {
        for (long long e = h1 ; e <= h2 ; e++)
        for (long long f = c1 ; f <= c2 ; f++)
        {
            if (e == h1 && f == c1) continue;
            else if (e == h2 && f == c2) continue;
            t = -1e15;
            if (e != h1) t = max(t , down[e-1][f]);
            if (f != c1) t = max(t , down[e][f-1]);
            kq = min(kq , t);
        }
        return kq;
    }
    for (long long e = h1 ; e <= h2 ; e++)
    for (long long f = c1 ; f <= c2 ; f++)
        {
            long long t = -1e15;
            if (e == h1 && f == c1) continue;
            else if (e == h2 && f == c2) continue;
            if (e != h1 && f != c2) t = max(t , up[e-1][f+1] + down[e-1][f+1] - m[e-1][f+1]);
            if (e != h2 && f != c1) t = max(t , up[e+1][f-1] + down[e+1][f-1] - m[e+1][f-1]);
            kq = min(kq , t);
        }
    return kq;
}
void do_it()
{
    long long k , h1,c1,h2,c2;
    for (long long i = 1 ; i <= q ; i++)
    {
        cin >> h1 >> c1 >> h2 >> c2;
        create(h1,c1,h2,c2);
        cout << check(h1 , c1 , h2 ,c2) <<"\n";
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("TABLE.INP","r",stdin);
    freopen("TABLE.OUT","w",stdout);
    inp();
    do_it();
}
