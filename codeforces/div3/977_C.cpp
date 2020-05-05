#include<bits/stdc++.h>
using namespace std;
const long maxn = 2e5+7;
long n , k , a[maxn], ans;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  //freopen("giun.inp","r",stdin);
  //freopen("giun.out","w",stdout);
  cin >> n >> k ;
  for (int i = 0 ; i < n ; i++) cin >> a[i];
  sort(a , a+n);
  if ( k == 0 )
  {
    if ( a[0] == 1 ) cout << -1;
    else cout << 1;
    return 0; 
  }
  if ( a[k] == a[k-1]) cout << -1;
  else cout << a[k-1];
  return 0;
}
