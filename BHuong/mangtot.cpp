#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 
ll n , a[(int)2e5+7]  , f[(int)2e5+7] ={0} , b[(int)2e5+7] , l[(int)2e5+7]={0} , t;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> n ;
        for (int i = 1 ; i <= n ; i++) cin >> a[i], b[i] = -a[i] , f[i] = 0 , l[i] = 0;
        for (int i = 1 ; i <= n ; i++) cerr << a[i] << " ";
        cerr << endl;
        for (int i = 1 ; i <= n ; i++) cerr << b[i] << " ";
        cerr << endl;
        f[1] = 1 , l[1] = 1;
        ll ma1 , ans1 = INT_MIN , ans2 = INT_MIN , ma2;
        for (int i =  n; i >= 1 ; i++ )
        {
            ma1 = 0 , ma2 = 0;
            for (int j = 1 ; j < i ; j++)
            {
                if (a[j] < a[i]) ma1 = max (ma1,f[j]);
                if (b[j] < b[i]) ma2 = max(ma2,l[j]);
            }
            l[i] = ma2+1 , f[i] = ma1+1;
            ans1 = max(ans1,f[i]) , ans2 = max(ans2,l[i]);
        }
        cout << ans1 << " " << ans2 << " " << n << endl;
    }
}    
