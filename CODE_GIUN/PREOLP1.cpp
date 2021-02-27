#include<bits/stdc++.h>
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define ll long long 
using namespace std;

ll n , a[(int)1e5+7] , t , ans , ok ;
void blablalolo()
{
    freopen("PREOLP1.INP","r",stdin);
    freopen("PREOLP1.OUT","w",stdout);
}

int main()
{
    giuncute;
    blablalolo();
    cin >> t;
    while (t--)
    {
        cin >> n >> a[1];
        ans = a[1] , ok = 1;
        for (int i = 2 ; i <= n ; i++) 
        {
            cin >> a[i]; 
            if (a[i] == a[i-1]) ok++;
            ans += a[i];
        }
        if (ok == n) cout << ans << endl;
        else 
        {
            sort(a+1,a+1+n);
            ans = 0;
            ll choose = a[n];
            for (int i = 1 ;  i <= n ; i++)
            {
                if (a[i] == choose) 
                {
                    int j = i-1;
                    while (j != 1 )
                    {
                        if (a[j] != choose)
                        {
                            choose = a[j];
                            break;
                        }
                        j--;
                    }
                    ans += choose;
                }
                else if (a[i] < choose ) ans += choose;
            }
            cout << ans << endl;
        }
    }
}