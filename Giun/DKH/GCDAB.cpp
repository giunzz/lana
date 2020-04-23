#include <bits/stdc++.h>
using namespace std;
long long n, dem, n1, n2;

void sol(){
    long long c = sqrt(n), up, m;
    dem = n, n1 = n;
    if (n == 3) cout << 5;
    else if (n == 2) cout << 3;
    else if (n == 1) cout << 1;
    else {
        for (int i = 2; i <= c; i++){
            m = n / i;
            if (m != n1){
                up = i;
                n2 = n / i;
                dem  += n / i + (n1 - n2) * (n / n1);
            //if (n1 == n2) dem += i;
                //cerr << n1 << " " << n2 << " " << dem << " " << i << endl;
                n1 = n2;
            }
        }
        n2 = n1, n1 = up;
        //cerr << n1 << " " << n2;
        if (c * c != n) dem += (n2 - n1) * (n / n2);
        cout << dem;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("gcdab.inp", "r", stdin);
    freopen("gcdab.out", "w", stdout);
    cin >> n;
    sol();
    //cerr << clock() << " ms";
    return 0;
}