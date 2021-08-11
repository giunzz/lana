#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;

ll n , m , k  , ans = INT_MAX , pos , cnt ;
string a , b ;

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m >> k;
    cin >> a;
    while (k--)
    {
        cin >> b;
        for (int i = 0 ; i < n ; i++)
        {
            pos = i , cnt = 0 ;
            for (int j = 0 ; j < m ; j++)
            {
                if (pos == n) pos = 0 ;
                cnt += (a[pos] != b[j])  ;
                pos++;
            }
            ans = min(ans,cnt);
        }
    }
    cout << ans;
}