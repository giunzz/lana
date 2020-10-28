#include<bits/stdc++.h>
using namespace std;
// ko lien tiep
int n , a[10007] , f[1009]={0},t , ma = 0, ans = 0;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
  //  freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    f[1] = 1;
    for (int i = 2 ; i <= n ; i++ )
    {
        ma = 0;
        for (int j = 1 ; j < i ; j++)
        {
            if (a[j] < a[i]) ma = max (ma,f[j]);
          //  cerr << ma << " ";
        }
        //cerr << endl;
        f[i] = ma+1;
        ans = max (ans,f[i]);
    }
    cout << ans;
}