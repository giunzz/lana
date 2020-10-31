#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> ii;
struct node
{
    int x, y, z, w;
    node() {};
    node(int x, int y, int z, int w): x(x), y(y), z(z), w(w) {};
} shop[16], ball[2002];
struct line
{
    int a, b, c;
    line() {};
    line(int a, int b, int c): a(a), b(b), c(c) {};
};
struct point
{
    int x, y;
    point () {};
    point(int x, int y) : x(x), y(y) {};
};
bool cmp( ii a, ii b )
{
    if ( a.Y==0 && b.Y==0) return shop[a.X].w > shop[b.X].w;
    if ( a.Y==0 ) return 1<2;
    if ( b.Y==0 ) return 1>2;
    if (shop[a.X].w/a.Y == shop[b.X].w/b.Y)
        return a.Y<b.Y;
    else
        return (shop[a.X].w/a.Y) > (shop[b.X].w/b.Y);
}
int n, m, k, xx, yy, zz;
bool s1, s2;
bool check[2002][16], vis[16];
//-----------------------------------------------------------------------------
void check1()
{
    long long res=0, cl; bool tt;
    while (1)
    {
        tt=0;
        vector< ii > V; V.clear();
        for ( int i=1; i<=n; i++ )
        if ( vis[i]==0 )
        {
            int tmp=0;
            for ( int j=1; j<=m; j++ )
                if ( check[i][j] ) tmp++;
            V.push_back(ii(i, tmp));
        }
        sort(V.begin(), V.end(), cmp);
        for ( int i=0; i<V.size(); i++ )
            if ( V[i].Y>k ) continue;
            else
            {
                cl=V[i].X;   k-=V[i].Y;
                res+=shop[V[i].X].w;
                tt=1;   break;
            }
        for ( int j=1; j<=m; j++ )
            if ( check[cl][j] )
            {
                for ( int i=1; i<=n; i++ )
                    if ( i!=cl ) check[i][j]=0;
                check[cl][j]=0;
            }
        vis[cl]=1;
        if ( tt==0 )  break;
    }
    cout << res;
}
void sub1()
{
    for ( int i=1; i<=n; i++ )
    {
        int tmp=0;
        for ( int j=1; j<=m; j++ )
        {
            int ch1=0, ch2=0, le, ri;
            le=ball[j].x-ball[j].z; ri=ball[j].x+ball[j].z;

            if ( shop[i].x<=ri && shop[i].x>=le )  ch1=1;
            if ( xx<=ri && xx>=le )  ch2=1;

            if ( ch1^ch2==1 ) check[i][j]=1;
        }
    }
    check1();
}
line makeline( int x, int y, int u, int v )
{
    int a, b, c;
    a=v-y; b=u-x; c=(v-y)*x+(u-v)*y;
    return line(a, b, -c);
}
void sub2()
{
    cout << 0;
}
//--------------------------------------------------------------------
int main()
{
    freopen("teaworld.inp","r",stdin);
    freopen("teaworld.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> m >> n >> k;
    s1=s2=1;
    for ( int i=1; i<=m; i++ )
    {
        int x, y, z, r;
        cin >> x >> y >> z >> r;
        if ( y!=0 ) s1=0;
        if ( z!=0 ) s2=0;
        ball[i]=(node(x, y, z, r));
    }
    for ( int i=1; i<=n; i++ )
    {
        int x, y, z, r;
        cin >> x >> y >> z >> r;
        if ( y!=0 ) s1=0;
        if ( z!=0 ) s2=0;
        shop[i]=(node(x, y, z, r));
    }
    cin >> xx >> yy >> zz;
    if ( yy!=0 ) s1=0;  if ( zz!=0 ) s2=0;
    if ( s1==1 ) sub1();   else sub2();
}
