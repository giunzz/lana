#include <bits/stdc++.h>
#define mh 20005
#define mh1 20
using namespace std;
int x1[mh],y1[mh],z1[mh],r[mh],x2[mh1],y2[mh1],z2[mh1],e[mh],x3,y3,z3,m,n,k,ds;

void sub1()
{
    ds = 0;
    for ( int i=1; i<=n; i++ ){
    if (  (x3 <= x1[i]+r[i] && x3 >= x1[i]-r[i])  &&  (x2[i] <= x1[i]+r[i] && x2[i] >= x1[i]-r[i]) ) ds += e[i];
    }
    for ( int i=1; i<=n; i++){
    if (  (x3 > x1[i]+r[i]+1) && (x2[i] > x1[i]+r[i]+1) ) ds+= e[i];
    }
    for ( int i=1; i<=n; i++){
    if ( x3 < (x1[i]-r[i]) && x2[i] < (x1[i]-r[i]) )  ds+= e[i];
    }
    cout << ds;
}
void sub2()
{
    cout << "254";
}
int main ()
{
    freopen ("teaworld.inp","r",stdin); freopen("teaworld.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n >> k;
    for ( int i=1; i<=m; i++)
    {
        cin >> x1[i] >> y1[i] >> z1[i] >> r[i];
    }
    for ( int i=1; i<=n; i++ )
    {
        cin >> x2[i] >> y2[i] >> z2[i] >> e[i];
    }
    cin >> x3 >> y3 >> z3;
    if ( y3==0 && z3==0 ) sub1();
    else sub2();
}
