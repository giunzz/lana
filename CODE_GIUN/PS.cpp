#include<bits/stdc++.h>
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;
ll n ;
struct giun
{
    ll tu , mau;
}a[(int) 1e5+7];

bool cpr (giun &x , giun &y)
{
    return (x.tu*y.mau <= y.tu*x.mau);
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) 
    {
        cin >> a[i].tu >> a[i].mau;
        int k = __gcd(a[i].tu,a[i].mau);
        a[i].tu /= k , a[i].mau /= k;
        if (a[i].mau < 0) a[i].tu *= -1 , a[i].mau *= -1;
    }
    sort (a+1,a+1+n,cpr);
    for (int i = 1 ; i <= n ; i++) 
    {
        if (a[i].mau == 1) cout << a[i].tu << endl;
        else cout << a[i].tu << " " << a[i].mau << endl;
    } 
}