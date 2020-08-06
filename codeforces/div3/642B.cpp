#include <bits/stdc++.h>
using namespace std;
int n , t , s = 0 ,k,a[100],b[100];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
 //   freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> k ;
        s = 0;
        for (int i = 1 ; i <= n ; i++) cin >> a[i];
        for (int i = 1 ; i <= n ; i++) cin >> b[i] ;
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        for (int i = 1 ; i <= n ; i++)
        {
            if (i <= k ) s+= max(a[i],b[n-i+1]);
            else s +=a[i];
        }
        cout << s << endl;
    }
}