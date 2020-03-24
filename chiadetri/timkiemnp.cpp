#include <bits/stdc++.h>

using namespace std;
const int maxn  = 1e7;
int n, k, a[maxn];

void find(){
    int chot, i = 1, j = n + 1;
    while (true){
        chot = (i + j) / 2;
        //cerr << i << " " << j << endl;
        if (a[chot] == k){
            cout << chot;
            break;   
        }
        if (j - i == 1){
            if (k > a[n]) cout << a[i] << " " << -1;
            else if (k < a[1]) cout << -1 << " " << a[j];
            else cout << a[i] << " " << a[j];
            break;
        }
        if (k > a[chot]) i = chot;
        else j = chot;
    }
}

int main(){
    freopen("timkiemnp.INP", "r", stdin);
    freopen("timkiemnp.OUT", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    find();
    cout << endl << clock() << " ms";
}