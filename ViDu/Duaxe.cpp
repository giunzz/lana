#include<bits/stdc++.h>

using namespace std;

long l , m , n  , a[(int) 1e6 + 7] ;
long r = 0 , ans = 0 , t = 0;
void timchao(long k)
{
    m = k ,  r = k ,   l = k;
	while ( ( l-1 >= 1 ) && ( a[l] < a[l-1] ))  l--;
    while ( ( r+1 <= n ) && ( a[r] < a[r+1] ))  r++;
	for (m = l+1 ; m <= r-1 ; m++) 
        if (a[m] < a[m-1]  && a[m] <a[m+1] ) break;
    cerr << l << " " << m << " " << r << endl ;
    //cerr << a[l] << " " <<a[m] << " " << a[r] << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.inp", "r", stdin);
    freopen("output.txt", "w", stdout);
    //freopen("duaxe.inp","r",stdin); 
    //freopen("duaxe.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    while (r < n)
    {
        timchao (r+1);
        t = (a[r] - a[m]) - (a[l] - a[m]);
        if (t<0) t = 0;
	    ans =+ t;
    }
    cout << ans;
    return 0;
}  