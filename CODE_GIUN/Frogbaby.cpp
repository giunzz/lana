#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0)
#define ll long long
ll n , a[(int)1e6+7] , ans = 0 , down = 0 , pre;

int main()
{
  giuncute;
  freopen("frogbaby.inp","r",stdin);
 freopen("frogbaby.out","w",stdout);
  cin >> n;
  for (int i = 1 ;  i <= n ; i++) cin >> a[i];
  for (int i = n ; i > 0 ; i--)
  {
      int pos = a[i]-down++;
      if (a[i] == a[i+1]) pos = pre;
      if (pos < 1 ) break;
      ans += pos , pre = pos;
     // cerr << ans << " " << pos << endl;
  }
  cout << ans;
}