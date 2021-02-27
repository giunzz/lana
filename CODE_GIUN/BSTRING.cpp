#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
int n, a[maxn], ans[3] = {0}, d = 1, dem[3] = {0};

void xuly(int t){
    d = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] != t) 
            ++ans[t];
        if (++d == dem[t]) break;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BSTRING.INP", "r", stdin);
    freopen("BSTRING.OUT", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n; char t;
    cin.ignore();
    for (int i = 1; i <= n; i++){
        cin.get(t);
        a[i] = t - '0';
        if (a[i]) ++dem[1];
        else ++dem[0];
        if (i == 1) continue;
        if (a[1] == a[i] && a[i] == a[i - 1]) ++d;
    }
    if (d == dem[a[1]]) {cout << 0; return 0;}
    xuly(1);
    xuly(0);
    cout << min(ans[1], ans[0]);
}