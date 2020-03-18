#include<bits/stdc++.h>

using namespace std;

int main(){
    int n , a[11]={0} , i , j ;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    cin >> n ;
    while ( i != 0){
        for ( j = 1 ; j <= n ; j++ ) cout << a[j];
        cout << endl;
        i = n ;
        while ( (i > 0) && (a[i] == 1) ) i--;
        if (i > 0 ){
            a[i] = 1;
            for (j = i+1 ; j <= n ; j++) a[j] = 0;
        }
    }
     return 0;
}