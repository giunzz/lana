#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;
ll n, f[155]={0};
void check ()
{
    f[1] = 1 , f[2] = 1;
    if (n == 0) cout << 0;
    else if (n == 1) cout << 1;
    else for (int i = 3 ; i <= 151 ; i++) 
    {
        f[i] = f[i-1] + f[i-2];
        if (n == f[i])
        {
            cout << i;
            break;
        }
    }
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n;
    check();
}