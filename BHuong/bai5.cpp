#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
#define ballolo freopen("bai5.inp","r",stdin),freopen("bai5.out","w",stdout);
ll n, a[(ll) 1e7+7] ;
void sorting(ll d, ll c)
{
    ll i,j,m,x;
    m = (d+c)/2,x = a[m],i = d,j = c;
    do 
    {
        while (a[i]<x) i++ ;
        while (a[j]>x) j-- ;
        if (i<=j) swap(a[i],a[j]), i++,j--;
    }
    while (i<=j);
    if (j>d) sorting(d,j);
    if (i<c) sorting(i,c);
}
int main()
{
    giuncute;
    ballolo;
    cin >> n ;
    for (ll i = 1 ; i <= n ; i++) cin >> a[i]; 
    sorting(1,n);
    for (ll i = 1 ; i <= n ; i++) cout<< a[i] << " ";     
} 


