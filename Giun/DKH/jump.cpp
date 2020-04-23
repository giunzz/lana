#include <bits/stdc++.h>

using namespace std;
const int maxsang = 1e6 + 7;
int a, b, sang[maxsang] = {1}, d[maxsang] = {0}, chan, le, can;

void xsang(){
    int dem = 0, lt = 1;
    d[0] = 1, d[1] = 1;
    for (int i = 2; i <= 1e6; i++){
        if (!d[i]){
            while (pow(d[i], lt) <= 1e6){
                sang[pow(d[i], lt)]++;
            }
        }
    }
}

void check(int num){
    chan = 0, le = 0, can = sqrt(num);
    for (int i = 1; i <= can; i++){
        if (num % i == 0){
            if (i % 2 == 0) ++chan;
            else ++le;
            if (i * i != num){
                if ((num / i) % 2 == 0) ++chan;
                else ++le;
            }
        }
    }
}

void sol(){
    int ans = 0;
    for (int i = a; i <= b; i++){
        check(i);
        //if (i == 9) cerr << chan << " " << le << "\n";
        if (abs(chan - le) <= 2) ++ans;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("jump.inp", "r", stdin);
    freopen("jump.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++){
        cin >> a >> b;
        sol();
    }
}