#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
const int maxn = 1e5;
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

int n , m , a[maxn + 7] , l , r , d1[maxn+7], d2[maxn+7], d3[maxn+7];

int main()
{
    balabalo;
    giuncute;
    cin >> n >> m ;
    d1[0] = 0 , d2[0] = 0 , d3[0] = 0;
    for (int i = 1 ; i <= n ; i++) 
    {
        cin >> a[i] ;
        if (a[i] == 1)  d1[i] = d1[i-1] + 1;
        else d1[i] = d1[i-1];
        if (a[i] == 2 ) d2[i] = d2[i-1] + 1;
        else d2[i] = d2[i-1];
        if (a[i] == 3 ) d3[i] = d3[i-1] + 1;
        else d3[i] = d3[i-1];
    }
    for (int i = 1 ; i <= n ; i++) cerr << i << " :  " <<  d1[i] << " " << d2[i] <<" " << d3[i] << endl;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> l >> r;
        cout << d1[r] - d1[l-1] << " " << d2[r] - d2[l-1] << " " << d3[r] - d3[l-1] << endl;
    }
    return 0;
}

