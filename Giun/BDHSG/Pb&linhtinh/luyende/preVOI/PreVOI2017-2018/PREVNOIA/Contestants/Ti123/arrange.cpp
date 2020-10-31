#include <bits/stdc++.h>
#define mh 100004
using namespace std;
int n, t, a[mh];

void sub1()
{
    int m = t/n;
    int ds = 0;
    for ( int i=1; i<=n; i++ )
        if ( a[i] > m ) ds += abs(m-a[i]);
    cout << ds;
}

void sub2 ()
{
    cout << "1";
}

int main ()
{
    freopen("arrange.inp","r",stdin); freopen("arrange.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for ( int i=1; i<=n; i++ )
        cin >> a[i];
    for ( int i=1; i<=n; i++)
        t += a[i];
    if ( t%n == 0 ) sub1();
    else sub2();


}
