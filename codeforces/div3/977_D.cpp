#include <bits/stdc++.h>
  #define ll long long
  using namespace std;
  ll a[110], nex[110], pre[110];
  int main() {
      int n;
      cin >> n;
      for(int i = 1; i <= n; i ++) nex[i] = pre[i] = i;
      for(int i = 1; i <= n; i ++) cin >> a[i];
     for(int i = 1; i <= n; i ++) {
         for(int j = 1; j <= n; j ++) {
             if(a[i] > a[j]) {
                 if(a[i]%3==0 && a[i]/3 == a[j]) {
                     nex[i] = j;
                     pre[j] = i;
                 } else if(a[i]%2==0&&a[i]/2==a[j]) {
                     nex[j] = i;
                     pre[i] = j;
                 }
            } else if(a[j] > a[i]){
                 if(a[j]%3==0 && a[j]/3 == a[i]) {
                     nex[j] = i;
                     pre[i] = j;
                 } else if(a[j]%2==0&&a[j]/2==a[i]) {
                     nex[i] = j;
                     pre[j] = i;
                 }
             }
         }
     }
     int id = 0;
     for(int i = 1; i <= n; i ++) {
         if(pre[i] == i) {
            id = i;
             break;
         }
     }
     while(nex[id] != id) {
         cout << a[id];
         id = nex[id];
     }
     cout << a[id];
     return 0;
}