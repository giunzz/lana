#include <bits/stdc++.h>
using namespace std;
int n , a[(int) 1e6 + 7] , x;
long long s = 0;

bool cnp(int n, int x)
{
  int r = n ;
  int l = 1;
  while (r >= l)
  {
    int mid = l + (r - l) / 2;
    if (a[mid] == x) return true;
    if (a[mid] > x) r = mid - 1;
    if (a[mid] < x) l = mid + 1;
  }
  return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SCB.inp","r",stdin);freopen("SCB.out","w",stdout);
    //freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] , s+= a[i];
    sort(a+1,a+1+n);
    int x = s / 2;
    cerr << x ;
    if (cnp(n,x) == true ) cout << x;
    else cout << -1;
    return 0;
}

