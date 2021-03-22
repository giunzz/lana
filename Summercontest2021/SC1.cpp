#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define giuncute  ios_base::sync_with_stdio(0),cin.tie(0); cout.tie(0);
using namespace std;
ll t , n , ta , tb ,  c ;
string  tc ;
ll tc1[] = {1000,2000,5000, 10000,
20000, 50000, 100000, 200000, 500000};
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> a , b;
        ll sa = 0 , sb = 0 ;
        for (int i = 0 ; i < 9 ; i++)
        {
            cin >> tc >> ta >> tb;
            if (ta == 1 ) a.push_back(tc1[i]) , sa += tc1[i];
            if (tb == 1 ) b.push_back(tc1[i]) ;
        }
        //for (int i = 0 ; i < a.size() ; i++) cerr << a[i] << " ";
        //cerr << sa << " ";
        if (sa <= n ) cout << "SORRY!!!";
        else 
        {
            ll  ans = a.size() , tmpa = 0;
            for (int i = 0 ; i < (int) a.size() ; i++)
            {
                tmpa += a[i];
                ans--;
                if (tmpa >= n) break;
            }
            cerr << tmpa << " ";
            ll have = tmpa - n;
            cerr << have << " ";
            for (int i = 0 ; i < (int) b.size() ; i++)
            {
                sb += b[i];
                ans++;
                if ( sb == have) break;
            }
            if (sb != have) cout << "SORRY!!!";
            else cout << ans << endl;
        }
    }
}