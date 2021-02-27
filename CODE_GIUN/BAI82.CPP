#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
const long long  maxn = 3e7+9;
long long n , a[maxn] , k ;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    freopen("BAI82.INP","r",stdin);
    freopen("BAI82.OUT","w",stdout);
    cin >> n >> k;
    for (long long i = 1 ; i <= n ; i++) cin >> a[i];
    sort(a + 1 , a + n + 1 );
    for (long  long i = n ; i >= k ; i-- ) cout << a[i] << " ";
    return 0;
}
