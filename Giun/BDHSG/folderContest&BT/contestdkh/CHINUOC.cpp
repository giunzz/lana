#include <bits/stdc++.h>

using namespace std;
long long t, snt[1000007], n;

void xaysnt(){
    long long p = 1;
    bool d[1000007];
    d[0] = 1, d[1] = 1;
    for (int i = 2; i <= 1000007; i++){
        if(!d[i]){
            snt[p] = i;
            for (int j = 2 * i; j <= 1000007; j += i) d[j] = 1;
            ++p;
        }
    }
}

void sol(){
    cin >> n;
    long long ans = 0;
    //long long m = (int)sqrt(n);
    //cerr << m << endl;
    int i = 1, j = 1;
    //int total;
    while (snt[j]*snt[j] <= n) ++j;
    --j;
    //total = j;
    //cerr << snt[6] << endl;
    //ans = j;
    while(true){
        while(j > i && snt[i]*snt[j]*snt[i]*snt[j] > n) --j;
        if(j <= i) break;
        ans += j - i;
        //cerr << j << endl;
        //cerr << ans << endl;
        ++i;

    }    
    //cerr << ans << endl;
    j = 1;
    long long chot = pow(n, 1.0/8);
    //cerr << chot << endl;
    while(snt[j] <= chot) ++ans, ++j;
    cout << ans << endl;
}

int main(){
    freopen("CHINUOC.INP", "r", stdin);
    freopen("CHINUOC.OUT", "w", stdout);
    xaysnt();
    cin >> t;
    //cerr << snt[10];
    for (int i = 1; i <= t; i++){
        sol();
    }
    cerr << clock() << " ms";
    return 0;
}