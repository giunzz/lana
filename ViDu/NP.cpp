#include<bits/stdc++.h>

using namespace std;


int n , a[11]={0} , i , j ;
// phương pháp quay lui
void print_answer(){
   for (int i = 1; i <= n; i++) 
      cout << a[i];
   cout << endl;
}

void np(int vt){
 if (vt == n + 1) print_answer();
 else {
    for (int i = 0; i <= 1; i++){
       a[vt] = i;
       np(vt + 1);
    }
 }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    cin >> n ;
    np(1);
    // phương pháp sinh 
    /*while ( i != 0){
        for ( j = 1 ; j <= n ; j++ ) cout << a[j];
        cout << endl;
        i = n ;
        while ( (i > 0) && (a[i] == 1) ) i--;
        if (i > 0 ){
            a[i] = 1;
            for (j = i+1 ; j <= n ; j++) a[j] = 0;
        }
    }*/
     return 0;
}