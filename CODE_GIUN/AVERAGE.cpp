#include<bits/stdc++.h>
using namespace std;
double a = 0,x[(int)1e5+7], s = 0,n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> x[i], s += x[i];
    sort(x+1,x+1+(int)n);
    // 2 2 4 5
    for (int i = 2 ; i <= n ; i++)
    {
        a = (x[i] + x[i-1])/2.0;
        x[i] = (x[i] + x[i-1])/2.0;
        //cerr << a << " " << x[i] << " " << x[i-1] << endl;
    }
    cout << setprecision(5) << fixed << a*n - s;
}