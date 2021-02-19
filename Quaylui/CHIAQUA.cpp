#include<bits/stdc++.h>
using namespace std;
const string tenfile = "CHIAQUA";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

long long n , a[30] , s[30] ={0};
long long  t1 = 0  , t2 = 0 ,  t3 = 0 , ans = INT64_MAX;
int ok = 1;

void printhhans()
{
    t1 = 0 , t2 = 0 , t3 = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        if (s[i] == 1) t1 += a[i];
        if (s[i] == 2) t2 += a[i];
        if (s[i] == 3) t3 += a[i];
    }
    if ( t1 != 0 && t2 != 0 && t3 != 0 )
    {
        int mi = min(min(t1,t2),t3);
		int ma =  max(max(t1,t2),t3);
        if (ma - mi < ans) ans = (ma-mi) , ok = 0;
    }
}

void chiaquaa(int i)
{
    for (int j = 1 ; j <= 3 ; j++)
    {
        s[i] = j;
        if (i == n ) printhhans();
        else chiaquaa(i+1);
    }
}

int main()
{
    balabalo;
    giuncute;
    cin >> n ; 
    for (int i = 1 ; i <= n ; i++)  cin >> a[i];
    chiaquaa(1);
    if (ok == 0)  cout << ans ;
    else cout << -1;
    return 0;
}