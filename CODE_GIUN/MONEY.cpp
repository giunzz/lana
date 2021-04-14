#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
int n , a[30] , x[30];
long long s , s2, dem = 0;
void Kt() 
{
    s2 = 0;
    for (int i = 1; i <= n; i++) s2 += (x[i] * a[i]);
    if (s2 == s) dem++;    
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
    cin >> n  >> s;
    for (int i = 1 ; i <= n ; i++)  cin >> a[i];
    chon(1);
    cout << dem;
    return 0;
}