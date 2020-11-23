#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;
ll n, f[155]={0},ok = 1;
void check ()
{
    f[1] = 1 , f[2] = 1;
    if (n == 2) cout << 1;
    else for (int i = 3 ; i <= 151 ; i++)
    {
        f[i] = f[i-1] + f[i-2];
        if (n == f[i])
        {
            cout << i;
            ok = 0;
            break;
        }
    }
}
int main()
{
    giuncute;
    freopen("VFIBO.inp","r",stdin);
    freopen("VFIBO.out","w",stdout);
    cin >> n;
    check();
    if (ok == 1) cout << -1;
}
