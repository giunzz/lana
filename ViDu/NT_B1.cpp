#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n , a[(int) 1e5+7]={0} , k , d[(int ) 1e7 + 7] ={0} ,ma = INT_MIN;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("giun.inp","r",stdin);
   // freopen("giun.out","w",stdout);
    cin >> n >> k;
    for (int i =1 ; i <= n ; i++) 
    {
        cin >> a[i] ; d[a[i]]++ ;
        ma = max (ma , d[a[i]]);
    }
    cout << k +ma;
}

