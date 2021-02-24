#include<bits/stdc++.h>
using namespace std;
const string tenfile = "bai40ql";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

long long n , t  , ok = 0;
bool kt (long long t)
{
    if ( t == 1 || t == 0 ) return 0;
    for (int i = 2 ; i * i <= t ; i++ ) 
        if ( t % i == 0 ) return 0;
    return 1;
}

void giunsieucute( int vt )
{
    for (int i = 0 ; i < 10 ; i++ )
    {
        if ( kt(t * 10 + i) )
        {
            t = t * 10 + i ;
            if ( vt == n ) cout << t << endl , ok = 1;
            else giunsieucute(vt + 1);
            t /= 10;
        }
    }
}

int main()
{
    balabalo;
    giuncute;
    cin >> n ;
    giunsieucute(1);
    if (ok == 0) cout << -1;
}

