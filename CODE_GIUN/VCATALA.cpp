#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;
ll n, f[100]={0};

void catalan()
{
    f[0] = 1; 
    for (ll i = 1 ; i <= 35 ; i++)
    {

        f[i] = 0 ;
        for (ll j = 0 ; j < i ; j++) f[i] += f[j]*f[i-j-1];
        if (f[i] == n) 
        {
            cout << i;
            break;
        }
    }
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n;
    catalan();
}
