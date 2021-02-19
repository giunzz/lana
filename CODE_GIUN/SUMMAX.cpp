// số âm thì in số âm lớn nhất :3
#include<bits/stdc++.h>

using namespace std;

int s = 0, n ,a [(int) 1e3+8] , ans = -10007  ;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SUMMAX.inp","r",stdin);
    freopen("SUMMAX.out","w",stdout);
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    int i = 1;

    while (i <= n ){
        s = a[i];
       for (int j = i + 1   ; j <= n ; j++){
            s += a[j];
            if (s > 0) ans = max (ans , s);
            else  break;
       }    
    i++;
    }
   cout << ans ;
   return 0;
}
 
   

