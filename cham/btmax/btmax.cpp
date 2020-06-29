#include<bits/stdc++.h>
using namespace std;
long long n , a[(int) 1e6+3] , k , s1 = 0 , s2 = 0 , t1 = 0 , t2 = 0 , b[(int) 1e6+3] ={0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("giun.inp","r",stdin); freopen("giun.out","w",stdout);
    freopen("BTMAX.INP", "r", stdin);freopen("BTMAX.OUT", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n ; i++) cin >> a[i];
    sort ( a + 2 , a + 1 + n);
    for (int i = 1 ; i <= n ; i++ ) b[i] = b[i-1] + a[i];   
    
    /*for (int i = 1; i <= n ; i++) cerr << a[i] << " ";
    cerr << endl;
    for (int i = 1; i <= n ; i++) cerr << b[i] << " ";
    cerr << endl;

    s1 = b[k] - b[1] ;
    s2 = b[n] - b[k] + a[1];
    t1 = b[k] - b[1] + a[1];
    t2 = b[n] - b[k];
    //cerr << s1 << " " << s2 << endl << t1 << " " << t2 ;
    cout << max (abs(s1 - s2) , abs(t1 - t2) );*/
    cout <<max (abs(b[n] - 2*(b[k+1] - b[1])) , abs(b[n] - 2*(b[n] - b[n - k])) );
    //cerr << b[n] << " " << b[k];
    return 0;
}
