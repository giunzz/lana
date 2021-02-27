#include<bits/stdc++.h>

using namespace std;

int n , a[109] ;
long  s = 0 , T = 0 , k , ans = -1;
vector<long> b;
vector<long> c;

bool chia (long t , long k)
{
    long tg = 0 , d = 0;
    for (int i = 1 ; i <= n ; i++ )
    {
        tg += a[i];
        if ( tg == t) tg = 0 , d++;
    }
    return (tg == 0 && d == k);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.inp","r",stdin);
    //freopen("output.txt","w",stdout);
    freopen("bai07.inp","r",stdin);
    freopen("bai07.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] , s += a[i];

    for (k = 1; k <= n ; k++)
    {
        if ( s % k == 0 )  T = s / k ;
        if (chia(T , k)) b.push_back(k) ,c.push_back(T) ; 
    }
    for (int i = 0 ; i < (int) b.size() ; i++)  if ( b[i] > ans ) ans = b[i] , T = c[i]; 

    cout << ans << endl;

    long tong = 0;
    int dem = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        tong += a[i];
        if (tong == T) 
        {
            dem++;
            if (dem == ans ) break;
            cout << i << " " ;
            tong = 0;
        }
    }
    cout << n ;    
    return 0;
}