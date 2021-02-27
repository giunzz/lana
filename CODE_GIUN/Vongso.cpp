#include<bits/stdc++.h>
using namespace std;
const long maxn = 1e6+9;
long n,a[maxn],k,ma,t,j;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   freopen("VONGSO.INP","r",stdin);
   freopen("VONGSO.OUT","w",stdout);
   cin >> n >> k;
   t = n * 2;
   a[0] = 0;
   j = n + 1;
  while (j <= t ){
        for (int i = 1 ; i <= n ; i++){
            cin >> a[i];
            a[j] = a[i];
            j++;
        }
  }

  ma = a[k];
  for (int i = 1  ; i <= t  ; i++) a[i] = a[i] + a[i-1];
  for (int i = k+1; i <= t  ; i++)  ma  = max( ma , a[i] - a[i-k] );
  cout << ma;
  return 0;
}
