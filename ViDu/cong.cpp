#include<bits/stdc++.h>

using namespace std;
const long maxn = 1e6+8;

long tach (long a){
    long t;
    t = a % 10;
    return t;
}
int main(){
    long n , k , d = 0, i = 1 , a[maxn];
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    cin >> n >> k ;
    while (n != 0){
        //x = tach(n);
        //y = tach(k);
        d++;
        a[i] = tach(n) + tach (k);
        n = n / 10 , k = k / 10;
        i++;
    }
    for (int i = 1 ; i <= d ; i++ ) cout << a[i];
return 0;
    
}