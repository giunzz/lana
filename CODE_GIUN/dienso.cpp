#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n;
int psum[N] , ssum[N];
char f[N];
main()
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> f[i];
        if(f[i] == '<') psum[i] = psum[i - 1] + 1;
        else psum[i] = 0;
    }
    for (int i = n ; i >= 1 ; i--)
    {
        if(f[i] == '>') ssum[i] = ssum[i + 1] + 1;
        else ssum[i] = 0;
    }
    int res = 0;
    for (int i = 1 ; i <= n+1 ; i++)
        res += max(psum[i - 1] , ssum[i]);
    cout << res;
}
