#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a, b, d , tmp1 , tmp , ok = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r", stdin);freopen("giun.out","w",stdout);
    //freopen("change.inp","r", stdin);freopen("change.out","w",stdout);
    cin >> a >> b;
    for (ll i = b-1 ; i >= 0; i--) 
    { 
        ll k  = a >> i;
        ll k1 = b >> i; 
        if (k & 1) tmp = 1;
        else tmp = 0;
        if (k1 & 1) tmp1 = 1;
        else tmp1 = 0;
        cerr << tmp << " " << tmp1 << endl ;
        if ( tmp == 1 or tmp1 == 1 or ok == 1) 
        {
            if  ( tmp != tmp1  ) d++ ;
            ok =1;
        }
        //cerr << ok << " ";
    }
    if ( d % 2 != 0 ) cout <<-1;
    else cout << d;
    return 0;
}
