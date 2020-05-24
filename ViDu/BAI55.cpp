#include<bits/stdc++.h>
using namespace std;
const string tenfile = "BAI55";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

int n , a ;
double ma = -1.0 ;

int UCLN(int x , int yy)
{
    int t;
    while ( yy != 0 )
    {
        t = x % yy ;
        x = yy ;
        yy = t;
    }
    return x;
}
int main()
{
    balabalo;
    giuncute;
    cin >> n ;
    for (int i = 1 ; i <= n / 2 ; i++)
    {
        if ( UCLN(i , n - i ) == 1) 
        {
            //cerr << i << " " << n - i << " " << i / (float) (n - i ) << endl;

            if ( ma <  i /(double) (n-i)  ) ma = i /(double) ( n- i ) , a = i ;
        }
    }
    cout << a <<"/" << n-a;
    return 0;
}