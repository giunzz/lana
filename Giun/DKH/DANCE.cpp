#include <bits/stdc++.h>
using namespace std;
int n, kt[1000007], dem, a[1000007] = {0}, b[1000007] = {0}, t[1000007];

void enter(){
    int da = 0, db = 0;
    char ch;
    for (int i = 1; i <= n; i++){
        cin >> ch;
        if (ch == 'a') kt[i] = 0, a[i] = ++da;
        else kt[i] = 1, b[i] = ++db;
        a[i + 1] = a[i], b[i + 1] = b[i];
    }
}

void sol(){
    for (int q = 1; q < n; q++){
        int i = q, j = q + 1;
        while (j <= n && i >= 1){
            if (a[j] - a[i - 1] == b[j] - b[i - 1]) ++dem;
            //t[j] = 1;

            --i, ++j;
        }
        //while (j <= n && i >= 1){

        //}
    }    
    /*int l, dem = 0;
    for (int i = 2; i <= n; i += 2){
        for (int k = 1; k <= n - i + 1; k++){
            l = k + i - 1;
            if (a[l] - a[k - 1] == b[l] - b[k - 1]) ++dem; 
            //cerr << dem << endl;
        }
    }*/
    cout << dem;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("dance.inp", "r", stdin);
    freopen("dance.out", "w", stdout);
    cin >> n;
    enter();
    //for (int i = 1; i <= n; i++) cout << a[i] << " " << b[i] << endl;
    sol();
    return 0;
}