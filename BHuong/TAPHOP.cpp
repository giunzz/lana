#include<bits/stdc++.h>
using namespace std; 
#define ll long long
ll  n,m,a[10005],b[10005],h1[10004]={0}, g[10004]={0},h2[10004]={0};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> m >> n ;
    for (int i = 1 ; i <= m ; i++) cin >> a[i], h1[a[i]] = 1, g[a[i]]++;
    for (int i = 1 ; i <= n ; i++) cin >> b[i] ,h2[b[i]] = 1, g[b[i]]++;
    for (int i = 1 ; i <= 1000 ; i++)
    {
        if (h1[i] == 1 || h2[i] == 1) cout << i << " ";
    }
    cout << endl;
    for (int i = 1 ; i <= 1000 ; i++)
    {
        if (g[i] == 2) cout << i << " ";
    }
    cout << endl;
    for (int i = 1 ; i <= 1000 ; i++)
    {
        if (h1[i] == 1 && g[i] == 1) cout << i << " ";
    }
}