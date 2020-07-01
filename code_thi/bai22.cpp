#include <bits/stdc++.h>
using namespace std;
long long  n , a[1000],b[1000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r", stdin);freopen("giun.out","w",stdout);
   // freopen("bai22.inp","r", stdin);freopen("bai22.out","w",stdout);
    cin >> n;
    a[0] = 0 , a[1] = 1;
    b[0] = 0;
    for (int i = 1 ; i <= 10 ; i++)
    {
        b[i] = (a[i] + 1 ) % 3;

    }
    cout << a[n];
    return 0;
}
