// liet ke cac tap con k phan tu 
#include<bits/stdc++.h>

using namespace std;
int main(){
    int n , a[30] , i , j , k ;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    cin >> n >> k;
    for (int i = 1 ; i <= k ; i++) a[i] = i;

    while ( i != 0){
        cout << "{";
        for ( j = 1 ; j <= k  ; j++ ) cout << a[j] << " , " << a[k] << "}";
        cout << endl;
        i = k ;
        while ( (i > 0) && (a[i] == n - k + i ) ) i--;
        if (i > 0 ){
            i++;
            for (j = i+1 ; j <= k ; j++) a[j] = a[j-1]+ 1;
        }
    }
     return 0;
}