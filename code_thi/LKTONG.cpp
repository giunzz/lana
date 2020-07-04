#include<bits/stdc++.h>

using namespace std;
#define ll long long  
ll  n , a[22] , x[22], ans = 0 , dd[1000000+12]={0};

void giunquay(int vt)
{
    if ( vt == n + 1)
    {
        ll s  = 0; 
        for (int i = 1 ; i <= n ; i++)
        {
            if (x[i] == 1 ) s = (s+a[i]) ; //% (int) 1e9+7;
            if (x[i] == 2 ) s = (s-a[i]) ; //% (int) 1e9+7;
            if (x[i] == 3 ) s = (s*a[i]) ; //% (int) 1e9+7;
        }
        if (dd[s] == 0 ) ans++ , dd[s] = 1;
    }
    else 
    {
        for (int i  = 1 ; i <= 3 ; i++)
        {
            x[vt] = i;
            giunquay(vt+1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n ;
    freopen("giun.inp","r", stdin);freopen("giun.out","w",stdout);
    //freopen("bai22.inp","r", stdin);freopen("bai22.out","w",stdout);
    for (int i = 1 ; i <= n ; i++) cin >> a[i]; // , a[i] = a[i] % (int) 1e9+7;
    for (int i = 1 ; i <= n ; i++) cerr << a[i] << " ";
    giunquay(1);
    cout << ans;
}