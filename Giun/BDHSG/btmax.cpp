#include<bits/stdc++.h>
using namespace std;
long long n , a[(int) 1e6+3] , k , s1 = 0 , s2 = 0 , t1 = 0 , t2 = 0 , b[(int) 1e6+3] ={0};
vector<long long> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("f.inp","r",stdin); freopen("f.out","w",stdout);
    freopen("BTMAX.INP", "r", stdin);freopen("BTMAX.OUT", "w", stdout);
    cin >> n >> k;
    q.resize(n);
    for (int i = 0; i < n ; i++) cin >> q[i];
    sort ( q.begin() + 1 , q.end());
    for (int i = 1 ; i <= n ; i++ ) b[i] = b[i-1] + q[i - 1];
    cout <<max (abs(b[n] - 2*(b[k + 1] - b[1])) , abs(b[n] - 2*(b[n] - b[n - k])) );
    return 0;
}