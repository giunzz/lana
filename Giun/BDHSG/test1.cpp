#include<bits/stdc++.h>
using namespace std;

int main(){
    long long a, b = 0;
    // cin >> a;
    for(cin >> a; a > 0; a/= 10){
        b = max(b, a % 10);
    }
    cout << b;
}