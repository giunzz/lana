#include <bits/stdc++.h>

using namespace std;
int n;

int cnt() 
{ 
    int k = 0; 
    for (int i = 5; n / i >= 1; i *= 5) 
        k += n / i; 
    return k; 
} 

int main(){
    freopen("zero.inp", "r", stdin);
    freopen("zero.out", "w", stdout);
    cin >> n;
    cout << cnt();
}