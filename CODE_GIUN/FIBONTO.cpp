#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n , d = 0, f[(ll) 1e5+7]={0};

bool find( int k)
{
    if (k < 2) return false;
    for (int i = 2 ;  i <= sqrt(k) ; i++)
    {
        if (k % i == 0 ) return false;
    }
     return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FIBONTO.inp","r",stdin);
    freopen("FIBONTO.out","w",stdout);
    cin >> n;
    f[0]=f[1] = 1 , f[2] = 1;
     for (int i = 3 ; i <= n ; i++)f[i] = f[i-1] + f[i-2];
    for (int i = 1 ; i <= n ; i++) if (find(f[i]) == true) d++;
    cout << d;
    return 0;
}
