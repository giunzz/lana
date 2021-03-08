#include <bits/stdc++.h>

using namespace std;
#define oo INT_MAX
#define lap(i,a,b) for (long i=a; i<=b; i++)
ifstream inp ("DIJKSTRA.INP");
int n;
int a[1000][1000],fre[1000],len[1000],pre[1000];
void Solve(int u)
{
    fre[u] = false;
    lap(i,1,n)
    {
        if (a[u][i] != oo && u!=i && fre[i] == true)
        {
            if (len[i] == oo )
            {
                len[i] = len[u] + a[u][i];
                pre[i] = u;
            }
            if ((len[u] + a[u][i]) < len[i])
            {
                len[i] = len[u] + a[u][i];
                pre[i] = u;
            }
            // cerr << /*u << " " <<*/ i << " " << len[i] << endl;
            Solve(i);
            fre[i] = true;
        }
    }
}
void nhap()
{
    cin >> n;
    lap(i,1,n)
    {
        len[i] = oo;
        fre[i] = true;
        lap(j,1,n)
        {
            a[i][j] = oo;
            if (i == j)
                a[i][j] = 0;
        }
    }
    while (!cin.eof())
    {
        int x,y,length;
        cin >> x >> y >> length;
        a[x][y] = length;
        a[y][x] = length;
        // cerr << x << y << length << endl;
    }
}
void Out()
{
    lap(i,1,n)
        cout << len[i] << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(); cout.tie();
    freopen("test.INP","r",stdin);
    freopen("test.OUT","w",stdout);
    nhap();
    pre[1] = 1;
    len[1] = 0;
    Solve(1);
    Out();

    return 0;
}
