//dequyquaylui
#include <bits/stdc++.h>

using namespace std;
const int maxn = 65;
int n, dnp[maxn];

void inch(){
    for (int i = 1; i <= n; i++){
        cout << dnp[i];
    }
    cout <<  endl;
}

void np(int i){
    for (int j = 0; j <= 1; j++){
        dnp[i] = j;
        //cerr << i << " " << j << endl;
        if (i == n) inch();
        else np(i + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("bai42ql.INP", "r", stdin);
    freopen("bai42ql.OUT", "w", stdout);
    cin >> n;
    np(1);
    return 0;
}