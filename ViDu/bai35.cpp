#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long

ll d1, m1 , y1 , d2 , m2 , y2;

bool nhuan( ll  x)
{
    if ( x % 400 ) return true;
    if ( x % 100 ) return false;
    if ( x % 4  ) return true;
    return false;
}

ll doiso ( ll d , ll m , ll y)
{
    ll t =  ( y - 1) / 4 - (y - 1) / 100 + (y-1) / 400; 
    ll res = t * 366 + (y - 1 - t) *365;
    for (int i = 1 ; i <= m - 1)
    {
        switch (i)
        {
            case 1: 
            case 3:
            case 5: 
            case 7:
            case 8: 
            case 10:
            case 12: 
                res += 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                res += 30;    
                break;
            case 2:
                if ( nhuan(y) ) res += 29;
                else res += 28;
        }
    }
    return (res + d);
}

bool han (ll n )
{
    if ( n % 23 == 1  && n % 27 == 1 ) return true;
    if ( n % 23 == 1  && n % 33 == 1 ) return true;
    if ( n % 27 == 1  && n % 33 == 1 ) return true;
    return false;
}

void doingay (ll n  , ll &d , ll &m , ll &y)
{
    ll dem = 0  , truoc;
    y = 0;
    while ( dem < n )
    {
        truoc = dem ;
        y++
        if (nhuan(y)) dem += 366;
        else dem += 365;
    }
    n -= truoc;
    dem = 0 , m = 0 , truoc = 0;
    while ( dem < n )
    {
        truoc = dem ;
        m++;
        switch (i)
        {
            case 1: 
            case 3:
            case 5: 
            case 7:
            case 8: 
            case 10:
            case 12: 
                res += 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                res += 30;    
                break;
            case 2:
                if ( nhuan(y) ) res += 29;
                else res += 28;
        }
    }
    n -= truoc;
    d = n ;
}

void  giunxinhdep()
{
    ll i , dem , y , start , stop , n ;
    giuncute;
    balabalo;
    cin >> d1 >> m1 >> y1 >> y;
    n = doiso ( d1 , m1 , y1);
    start = doiso(1,1,y);
    stop( 31 , 12 , y);
    dem = 0;
    for (int i = start ; i <= stop ; i++)
    {
        if han(i - n + 1)
        {
            dem++:
            doingay(i,d2,m2,y2);
            cout << d2 << " " << m2 << " " << y2;
        }
    if ( dem == 0 ) cout << "lucky";
    }
}

int main()
{
    giunxinhdep();
    return 0;
}
