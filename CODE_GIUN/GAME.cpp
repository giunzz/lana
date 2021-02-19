#include<bits/stdc++.h>
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
#define ll long long 
using namespace std;
ll n , sum = 0 ,a, ans;
char c;
pair<ll,ll> vt;
int main()
{
    giuncute;
    freopen("GAME.inp","r",stdin);
    freopen("GAME.out","w",stdout);
    cin >> n;
    int giun = 1;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> c >> a;
        if (c == 'W') sum += a;
        else sum -= a;
        if (ans < sum || ans == sum)
        {
            ans = sum ;
            vt.first = giun;
            vt.second = i;
        }
        if (sum < 0) 
        {
            sum = 0;
            giun = i + 1;
        }
    }
    if (ans <= 0) cout << 0;
    else cout << ans << endl << vt.first << " "<< vt.second;
}