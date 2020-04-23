#include <bits/stdc++.h>
using namespace std;
long long n;

void sol(){
    long long vl, vl1, ans = 0, d;
    bool c = 0;
    cin >> vl1 >> vl;
    d = vl1;
    if (vl > vl1) ans = vl - vl1, c = 1, d = vl;
    vl1 = vl;
    //cerr << vl1 << endl << vl << endl << ans << endl << c << endl << d << endl;
    for (int i = 1; i < n - 1; i++){
        cin >> vl;
        if(vl > vl1){
            if(!c){
                c = 1;
            }
            if (vl > d) ans += vl - vl1;
        }
        else if (vl < vl1) {
            if(c){
                c = 0;
                d = vl1;   
                //cerr << d << endl;            
            }
        }
        vl1 = vl;
        //cerr << ans << " " << d << endl;
    }
    cerr << clock << " ms";
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("duaxe.inp", "r", stdin);
    freopen("duaxe.out", "w", stdout);
    cin >> n;
    sol();
    return 0;
}