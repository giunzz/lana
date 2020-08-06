#include<bits/stdc++.h>
using namespace std;
int n , q , a, b, k ;
long long ans = INT64_MIN, m[(int) 1e7+7]={0};
int main()
{ 
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("arrm.inp","r",stdin);freopen("arrm.out","w",stdout);
    cin >> n >> q;
    for (int i = 1 ; i <= q ; i++)
    {
        cin >> a >> b >> k ;
        m[a] += k , m[b+1] -=k;
    }
    for (int i = 2 ; i <= n ; i++)
    {
            m[i] += m[i-1];
            ans = max (ans,m[i]);
    }
    cout << ans;
}
