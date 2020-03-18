#include<bits/stdc++.h>

using namespace std;

long n , t ;
float  s = 0 , d = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt","r", stdin );
    freopen("output.txt","w",stdout);  
    cin >> n;
    while ( n != 0 ){
        t = n % 10;
        d++;
        s+=t;
        n = n / 10 ;
    }
  //  cout << std::setprecision(16); 
    cout <<  s / d << endl ;
    return 0;
}