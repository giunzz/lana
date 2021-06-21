#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
const ll maxbit = 1 << 4 ;
ll n , a[407][407] , cnt[maxbit]  , x , y , c  , ans = 0 ;

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin>> n ; 
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> x >> y >> c;
        a[x+200][y+200] = 1 << (c - 1);
    }
    for (int i = 0 ; i <= 400 ; i++)
    {
        for (int j = i+1 ; j <= 400 ; j++)
        {
            set(cnt , 0 , sizeof cnt);
            for (int k = 0 ; k <= 400 ; k++)
            {
                if (a[k][i] && a[k][j])
                {
                    //cerr << 1;
                    ll mask = a[k][i] | a[k][j];
                    //cerr << mask;
                    ans += cnt[maxbit - 1 - mask];
                    ++cnt[mask];
                }
            }
        }
    }
    cout << ans;
}