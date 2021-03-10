#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
ll n , s[(int) 1e6+7] , D , f[(int) 1e6+7] ={0};
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> D;
    int vtmin = 0 ;
    for (int i = 1; i <= n ; i++) cin >> s[i];
    sort(s+1,s+1+n);
    for (int i = n ; i >= 1 ; i--)
    {
        if (vtmin != 0 || s[i] - s[vtmin] >= D )
        {
            for (int j = vtmin+1 ; i <= n ; i++)
                if (s[i]-s[j] >= D) vtmin = j;
        }
        f[i] = f[i-1]*(i-vtmin+1);
    }
    cout << f[n];
}