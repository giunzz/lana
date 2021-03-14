#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
ll n , x , q;
stack<ll> d;
int main()
{
    giuncute;
    freopen("jump.inp","r",stdin);
    freopen("jump.out","w",stdout);
    cin >> n >> q;
    vector<ll> a(n) , f(n, 0);
    // for (int i = 1 ; i <= n ; i++) f[i] = 0;
    for (int i = 0 ; i < n ; i++) cin >> a[i] ;
    reverse(a.begin(),a.end());
    for (int i = 0; i < n; i++)
    {
        while (d.size() > 0 && a[d.top()] <= a[i]) d.pop() ;
        if(d.size()) f[i] = f[d.top()] + 1;
        d.push(i);
    }
    reverse(f.begin() , f.end());
    for (int i = 0 ; i < q ; i++) cin >> x , cout << f[x - 1] << endl;
}
