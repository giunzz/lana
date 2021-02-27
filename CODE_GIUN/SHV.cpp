#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;
ll p,x,f[] = {1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600},ans=1,n=0,a[20],v[]={1,2,3,4,5,6,7,8,9,10,11,12};
ll vt[]={1,2,3,4,5,6,7,8,9,10,11,12};
int main()
{
    giuncute;
    //freopen("giun.inp","r",stdin);
    //freopen("giun.out","w",stdout);
    while (cin >> x) a[++n] = x;
    p = a[n] ,n--;
    for (int i = 1 ; i <= n ; i++) 
    {
        ans += (v[a[i]]-2)*f[n-i-1];
        for (int j = a[i]+1; j <= n; j++) v[j]--;
        //cerr << ans << " " << v[a[i]] << " " << f[n-i-1] << endl;
    }
    cout << ans << endl;
    int t = 1 , l;
    for (int i=1;i<=n;i++) 
    {
        for (int j=1;j<=n;j++)
            if (t + j * f[n-i-1] > p) 
            {
                l = j-1;
                break;
            }
        t += l*f[n-i];
        a[i] = vt[l+1];
        for (int j=l+1;j<=n;j++) vt[j] = vt[j+1];
    }
    for (int i = 1 ; i <= n ; i++) cout << a[i]-1 << " ";
}