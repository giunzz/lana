#include <bits/stdc++.h>

using namespace std;

long n , d , t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("alibaba.inp","r",stdin);
    //freopen("alibaba.out","w",stdout);   
    freopen("input.txt","w",stdin);
    freopen("output.txt","r",stdout);
    cin >> n >> d ;
    if (n % 3 != 0 ) cout <<-1;
    else {
        t = n / 3;
        cout << t-d << " " << t << " " << t+d;
    }
    return 0;
} 
 