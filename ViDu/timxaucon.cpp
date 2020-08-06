#include <bits/stdc++.h>
using namespace std;

string s , c[(int) 1e5 + 7] ;
int p[(int) 1e5 + 7],ans = 0,n,l;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> c[i] >> p[i];
    cin >> s;
    for (int i = 1 ; i <= n ; i++)
    {
        l = 0 ;
        while (l < (int) c[i].length() )
        {
            string t = c[i].substr(l,s.length());
            if ( t == s)
            {
                ans += p[i];
                break;
            }
            l++;
        }
    }
    cout << ans;
}
