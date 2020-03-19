#include<bits/stdc++.h>

using namespace std;

long  t , a , b , ans1 = LONG_MAX;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.inp","r",stdin);
    freopen("output.txt","w",stdout);
    //freopen("Arrt.inp","r",stdin);
    //freopen("Arrt.out","w",stdout);

    cin >> t;
    for (int  i = 0 ;   i <= t / 2   ; i++)
    {
        if ( ( (2 * t) % (i + 1) ) == 0)
        {
            //i = t / (i + 1) - 1;
            a =  ( 2 * t /( i + 1) - i ) / 2 ;
            if (a < 0 ) break;
            else  ans1 = a , b = a + i; 
            //cerr << a << " " << b << endl;
            //return 0;
        } 
    }
    cout << ans1 << " " << b;
    return 0;
}