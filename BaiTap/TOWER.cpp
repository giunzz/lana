#include<bits/stdc++.h>
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
#define ll long long
using namespace std;
ll n , d , a[(int) 1e6+7] , f[(int) 1e6+7]={0};
int main()
{
    giuncute;
    //freopen("giun.inp","r",stdin);
    //freopen("giun.inp","r",stdin);
    cin >> n >> d;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    sort(a+1,a+1+n);
    int jmin = 1;
    for (int i = 1 ; i <= n ; i++)
    {
        if (s[i] - s[jmin] < d) jmin++:
        else {break;}
    }
    f[0] = 1;
    f[1] = 1;
    int vtmin = 1 , x;
    for (int i = 2; i <= n ; i++)
    {
        if (a[i] - vtmin < d) vtmin = i ;
        else
        {
            x =
        }
        if (a[i] - a[vtmin] >= d)
        {
             x = i-vtmin+1;

            f[i] = f[i-1]*x;
            cerr << x << " " << f[i] << endl;
        }
        else vtmin = i;
    }
    cout << f[n];
}
