//sinh
#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e4;
int n, dnp[maxn];

void ghichuoi(){
    for (int i  = 1; i <= n; i++){
        cout << dnp[i];
        //cerr << dnp[i];
    }
    cout << "\n";
    //cerr << "\n";
}

void np(){
    int i = n;
    ghichuoi();
    while (dnp[i] == 1) --i;
    if (i > 0){
        dnp[i] = 1;
        memset(dnp + i + 1, 0, (n - i) * sizeof(dnp[1]));
        np();
    }
}

int main(){
    freopen("daynp.INP", "r", stdin);
    freopen("daynp.OUT", "w", stdout);
    cin >> n;
    np();
    return 0;
}
