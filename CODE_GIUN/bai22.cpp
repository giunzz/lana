
#include <bits/stdc++.h>
using namespace std;
long long  n ,p2[65]={1};

long long dequy(long long vt)
{
    if ( vt == 1 ) return 0;
    long long lap;
    for (int i = 0 ; i <= 63 ; i++)
    {
        if (p2[i] >= vt)
        {
            lap = i ;
            break;
        }
    }
    return ((dequy(vt - p2[lap] / 2) + 1) % 3);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r", stdin);freopen("giun.out","w",stdout);
//    freopen("bai22.inp","r", stdin);freopen("bai22.out","w",stdout);
    for (int i = 1 ; i <= 65 ; i++) p2[i] =  p2[i-1] * 2;
    while ( cin >> n ) cout << dequy(n) << endl;
    return 0;
}
