#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

int n , a[30] , x[30];
long long s , s1 , s2 , ans;

void Kt() 
{
    s2 = 0;
    for (int i = 1; i <= n; i++)
    {
        s2 += (x[i] * a[i]);
    }
    s1 = s - s2;
    if (abs(s1-s2) < ans ) ans = abs(s1-s2);        
}

void chon (int i)
{
    for (int j = 0 ; j <= 1 ; j++)
    {
        x[i] = j;
        if ( i == n ) Kt();
        else chon(i+1);
    }
}

int main()
{
    balabalo;
    giuncute;
    cin >> n ; 
    for (int i = 1 ; i <= n ; i++) 
    {
        cin >> a[i];
        s += a[i];
    }
     ans = s;
    chon(1);
    cout << ans ;
    return 0;
}