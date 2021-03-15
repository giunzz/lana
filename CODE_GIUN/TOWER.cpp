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
    for (int i = 1; i <= n ; i++) cin >> s[i];
    sort(s+1,s+1+n);
    f[1] = 1;
    for (int i = n ; i >= 1 ; i--)
    {
        int x = 0 ;
        
        for (int j = 1 ; j < i ; j++)
            if (s[j] >= s[i]-D) x++;
        f[i] = f[i-1]*(x+1);
    }
    cout << f[n];
}