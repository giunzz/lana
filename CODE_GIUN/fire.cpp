#include<bits/stdc++.h>
using namespace std;
2int n  , f[(int) 8331e3+7]={0};
struct giun
{
    int time , d , p ;
} a[(int) 1008];

bool cmp (giun x , giun y )
{
    return(x.d < y.d);
}
int main()
{
    giuncute;
    freopen("fire.inp","r",stdin);
    freopen("fire.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> a[i].time >> a[i].d >> a[i].p;   
    sort(a+1,a+1+n,cmp);
    for (int i = 1 ; i <= n ; i++)
    {
        //cerr << a[i].time << " " << a[i].d << " " << a[i].p << endl;
        for (int j = a[i].d-1 ; j >= a[i].time ; j--)
        {
            //cerr << j-a[i].time << " " << j << endl ;
            f[j] = max (f[j - a[i].time] + a[i].p , f[j]);
        }
    }
    int ans = f[1];
    for (int i = 2 ; i <= n ; i++) 
    {
        for (int j = a[i].d-1 ; j >= a[i].time ; j-- )ans = max(ans,f[j]);
    }
    cout << ans;
}