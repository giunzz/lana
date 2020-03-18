#include<bits/stdc++.h>
using namespace std;
long n,ans;
int jj( long k ){
    int Sum=0,x;
    while (k != 0){
            x = k % 10;
            Sum = Sum + x;
            k = k / 10;
        }
    if ( Sum < 10 )return Sum;
    else return jj(Sum);
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   freopen("Soco.INP"," r",stdin);
   freopen("soco.OUT","w",stdout);
   cin >> n;
   cout << jj(n);
   return 0;
}
