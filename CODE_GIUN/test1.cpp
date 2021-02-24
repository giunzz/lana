#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long
ll n , a[30] , s[30] ={0} , k , ok = 0 ;
void check()
{
    ll  l = k , r = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        if (s[i] == 1) l += a[i];
        if (s[i] == 2) r += a[i];
    }
    if (l == r) 
    {
        cout << "YES";
        ok = 1;
    }
}

void quaylui(int i)
{
    if (ok == 1) return;
    for (int j = 1 ; j <= 3 ; j++)
    {
        s[i] = j;
        if (i == n ) check();
        else quaylui(i+1);
    }
}

int main()
{
    balabalo;
    giuncute;
    cin >> n ; 
    for (int i = 1 ; i <= n ; i++)  cin >> a[i];
    quaylui(1);
    if (ok == 0 ) cout << "NO";
    return 0;
}