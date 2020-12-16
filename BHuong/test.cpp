#include <bits/stdc++.h>
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;

int t , n , ans ;
string s;
int main()
{
    //freopen("giun.inp","r",stdin);
    //freopen("giun.out","w",stdout);
    cin >> t;
    while (t--)
    {
      cin >> n >> s; 
      ans = 0;
      int du = 0;
      for (int i = 0 ; i < n ; i++)
      {
        if (s[i] == '(') du++;
        else
        {
            du--;
            if (du < 0) du = 0 , ans++;
        }
      }
      cout << ans << endl;
    }
}