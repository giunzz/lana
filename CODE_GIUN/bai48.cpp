#include <bits/stdc++.h>

using namespace std;

long  long n  , a[10005] , v[10005] = {0} , s;
int main() {
    int t = 10000;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("bai48.inp","r",stdin);
    freopen("bai48.out","w",stdout);
    //freopen("input.inp","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> a[1] >> n; 
    for (int i = 2 ; i <= 10000 ; i++)
    {
        a[i] = (a[i-1] * a[i-1] ) % 10000;
        if (v[a[i]] != 0)
        {
            t = v[a[i]];
            s = i;
            break;
        }
        v[a[i]] = i; 
    }
    if ( n >= t )
    {
        n = (n - t) % (s-t) + t;
    }
    cout << a[n];
    return 0;
}