#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int n , k , a[30] , sp = 0,dd[30]={0}, ok = 0 , st, test;

void quaylui(int can)
{
    if ( st == sp || ok )
    {
        // test = sp;
        ok = 1;
        return;
    }
    if( can > n ) return;
    for (int i = 0 ; i <= 1 ; i++)
    {
        if ( i && st < sp )
        {
            st += a[can];
            dd[can] = 1;
            sp -=a[can];
            quaylui(can+1);
            dd[can] = 0;
            st -= a[can] , sp += a[can];
        }
        else quaylui(can+1);        
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CANK.inp","r",stdin);freopen("CANK.out","w",stdout);
    //freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
    cin >> n >> k ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] , sp+= a[i];
    st = k;
    quaylui(1);
    if (ok == 1 ) cout << "YES";
    else cout << "NO";
    // cerr << test;
} 