#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll m , n , ans = 0 , b , t, mau;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PSNGUYEN.inp","r",stdin);freopen("PSNGUYEN.out","w",stdout);
    //freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
    cin >> m >> n ;
    for (int i = 1 ; i < n ; i++)
    {
        mau = n + i;
        b = mau-(m % mau);
        b = b % mau;
        t = m / mau;
        if(b >= m) continue;
        // cerr << mau << " " << b << " " << t << endl;
        if ( t * mau + b  >= m  )--t;
        if ( b == 0 )--t;
        //cerr << t << " ";
        ans += (t + 1);
    }
    cout << ans;
}