#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
int t,n,x[maxn],y[maxn],r[maxn],p,d=0;
int main(){
  ios_base::sync_with_stdio(false);
   cin.tie(0);
   freopen("Bai20.INP"," r",stdin);
   freopen("Bai20.OUT","w",stdout);
  cin >> n;
  for (int i =1 ; i <= n ; i++) cin >> x[i] >> y[i] >> r[i];
  for (int i = 1; i<=n-1 ; i++) {
    for ( int j = i+1 ; j <= n ; j++){
       t= sqrt( pow(x[j]-x[i],2) + pow (y[j]-y[i],2));
       p= r[j]+r[i];
       if (t < p) d++;
       }
  }
   cout <<  d << endl;
  return 0 ;
}

