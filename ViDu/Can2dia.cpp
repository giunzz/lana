#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
int n,M[maxn]={0},a[maxn];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   freopen("CAN2DIA.INP"," r",stdin);
   freopen("CAN2DIA.OUT","w",stdout);
   cin >> n;
   for (int i = 1 ; i <= n ; i++) {
            cin >> a[i];
            M[a[i]]=1;
   }
   for (int i = 1 ; i <= n-1 ; i++) {
        for (int j = i+1 ; j <= n ; j++){
            M[a[i]+a[j]]=1;
        }
   }
   for (int i = 1 ; i <= n-2 ; i++) {
        for (int j = i+1 ; j <= n-1 ; j++){
                for (int k = j+1 ; k <= n ; k++){
                   M[a[i]+a[j]+a[k]]=1;
                }
        }
   }
   for (int i = 1 ; i <= 3000 ; i++) {
           if (M[i]!= 0) cout << i << " ";
   }
   return 0;
}
