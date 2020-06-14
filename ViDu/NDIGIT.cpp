#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std;
const string tenfile = "NDIGIT";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
int m , n , dem [20] = {0} ;
int main()
{
    ios_base::sync_with_stdio(0) , cin.tie(0);
    balabalo;
    cin >> m >> n ;
    for (int i = m ; i <= n ; i++)
    {
        int t = i;
        while ( t != 0 )
        {
            int x = t % 10;
            t = t / 10 ;
            dem[x]++;
        }
    }
    for (int i = 0 ; i <= 9 ; i++) cout << dem[i] << " ";
    return 0;
}
