#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 
ll n , m , s = 0 , a[(int) 1e6+7]  , vt , maxn ;
vector<ll> d1,d2;
int main()
{
    giuncute;
    freopen("yellow.inp","r",stdin);
    freopen("yellow.out","w",stdout);
    cin >> m >> n;
    for (int i = 1 ; i <= m ; i++) 
    {
        cin >> a[i];
        if (a[i] > maxn ) vt = i , maxn = a[i];
    }
    int k ;
    if (maxn == 2) k = 1;
    else if (maxn == 3 ) k = -1;
    n++;
    while(n--)
    {
        if(a[vt]==0) s++;
        if(vt==m || vt==1) k*=-1;
        vt+=k;
    }
    cout<<s;
}
