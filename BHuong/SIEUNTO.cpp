#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
#define ballolo freopen("giun.inp","r",stdin) , freopen("giun.inp","r",stdin) ; 

const int maxn = 1e7; 
ll  n , sang[maxn+7] ={0} , x ; 


void ss()
{
    sang[1] = 1 , sang[0] = 1 ;
    for (int i = 2  ; i*i <= maxn ; i++)
        if (!sang[i])
            for (int j = i*2 ; j <= maxn ; j +=i) sang[j] = 1;
}

bool check (ll k)
{
    while (k != 0)
    {
        if (sang[k] == true) k/=10;
        else return false;
    }
    return true;
}
int main()
{
    giuncute;
    ballolo;
    cin >> n ;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> x;
        if (check(x) == true) cout << 1;
        else cout << 1;
    }
}