#include<bits/stdc++.h>

using namespace std;

long a[1003] ;
int  d = 0 , n , t = 1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.inp","r",stdin);
    //freopen("output.txt","w",stdout);
    
    freopen("Bai02.inp","r",stdin);
    freopen("Bai02.out","w",stdout);
    
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    sort(a+1 , a+1+n);
    
    for (int i = 1 ; i <= n ; i++)
    {
        if (a[i] != a[i+1]) d++;
    }

    cout << d << endl;

    for (int i = n ; i >= 1 ; i--)
    {
        if ( a[i] == a[i-1] ) t++;
        else cout << a[i] << " " << t << endl  , t = 1;
    }
    
    return 0;
}