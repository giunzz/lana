#include<iostream>

using namespace std;

int n , m , a[(int) 1e5+7] , d[(int) 1e6+7]={0};
long long ans = 0;
int main()
{
    //freopen("giun.inp", "r", stdin);
    //freopen("giun.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m ; 
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    for (int i = 1 ; i <= m ; i++)
    {
        int l , r;
        cin >> l >> r;
        for (int i = 1 ; i <= n ; i++) d[a[i]] = 0;
        ans = 0;
        for (int j = l ; j <= r ; j++) d[a[j]]++;
        int k = 1;
        for (int j = 1 ; j <= m ; j++) 
        {
            ans += d[j]*d[j]*k;
            k++;
        }
        cout << ans << endl;
    }
}