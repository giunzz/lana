#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
ll n , a[(int) 1e6+7] ,  dd[(int) 1e6+7] ={0} , ma = INT_MIN , b[(int)1e6+7];
int main()
{
    giuncute;
    //freopen("giun.inp","r",stdin);
    //freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] ,dd[a[i]]++ , ma = max(ma,a[i]) ;
    ll tmp = 0 , ans = 0;
    for (int j = 1 ;j <= ma ; j++) b[j] += (dd[j]*(dd[j]-1))/2  , tmp += b[j];
    ans = tmp;
    //cerr << ans << " " << tmp;
    for (int i = 1 ; i <= n ; i++)
    {
        ans -= ((dd[a[i]])*(dd[a[i]]-1))/2 ;
        ans +=((dd[a[i]]-1)*(dd[a[i]]-1-1))/2;
        cout << ans << endl;
        ans = tmp; 
    }
}
