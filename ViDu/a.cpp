#include<bits/stdc++.h>

using namespace std;

int n,k,a[10000], ok = 0,d[3]={0}, s = 1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> k;
    for (int i =1 ; i <= n ; i++) cin >> a[i];
    if (k == n )
    {
        cout << "YES" << endl << n << endl ;
        for (int i = 1 ; i <= n ; i++)  cout << i << " " << i << endl << -a[i] << endl;
    }
    else if (k == 1)
    {
        for (int i = 1 ; i <= n ; i++)
        {
            s = 1,ok = 0,d[1]=1,d[2]=1;
            if (a[i] == 0 ) continue;
            if (ok == 1 ) d[2] = i, s*= a[i];
            d[1] = i, ok++, s*= a[i];
        }
        if ( s %  d[1]-d[2]+1 != 0) cout << "NO";
        else  
        {
            cout << "YES" << endl << d[1] << " " << d[2] << endl;
            for (int i =1  ; i <= n ; i++) cout << -a[i] <<" ";
        }
    }

}