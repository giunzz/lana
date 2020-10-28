#include<bits/stdc++.h>
using namespace std; 
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
#define ballolo freopen("SIEUNTO.inp","r",stdin) , freopen("SIEUNTO.out","w",stdout) ; 
#pragma GCC optimize("Ofast")
const ll nmax = 1e7 + 7;
ll sang[nmax], n , x;

void xaysang()
{
    sang[0] = 1; sang[1] = 1;
    for (int i = 2; i * i <= 1e7; i++)
        if (!sang[i]) 
           for (int j = i * 2; j <= 1e7; j += i) sang[j] = 1;
}

bool check (ll k)
{
    while (k != 0)
    {
 //       cerr << k << " " <<  sang[k] << endl;
        if (!sang[k]) k/=10;
        else return false;
    }
 //   cerr << endl;
    return true;
}
int main()
{
    giuncute;
    ballolo;
    cin >> n ;
    xaysang();
    // cerr << clock();
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> x;
        if (check(x) == true) cout << 1;
        else cout << 0;
    }
}