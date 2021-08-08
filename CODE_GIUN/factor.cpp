#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
using namespace std;
ll t , n;
vector <ll> a;
int main()
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    giuncute;
    cin >> t;
    while (t--)
    {
        cin >> n;
        a.clear();
        for(int i = 2 ; i*i<=n ; i++)
            while (n % i == 0) a.push_back(i) , n /= i ;
        if (n != 1) a.push_back(n) ;
        for (int i = 0 ; i < a.size() ; i++)
        {
            cout << a[i];
            if (a.size()-1 != i ) cout << "*"  ;
        }
        cout << endl;
    }
}