#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e3 + 5, maxint = 1e3 + 1, minint = 0;
long int w[maxn], m, n, t[maxn], s[maxn], jmax;

void enter(){
    cin >> n >> m;
    for (int i = 1; i<= n; i++){
        cin >> w[i];
    }
    w[0] = minint, w[n+1] = maxint, s[n+1] = minint, s[0] = maxint;
}

int optimize(){
    for (int i = n; i >= 0; i--){
        if (w[i] > m) w[i] = m + 1;
        else{
            jmax = n + 1;
            for (int j = i + 1; j <= n + 1; j++)
                if ((w[i] + s[j] <= m) && (s[j] > s[jmax])) jmax = j;
            s[i] = s[jmax] + w[i], t[i] = jmax;
        }
    }
    return s[0];
}

void trace(){
    int i = t[0];
    while (i != n + 1){
        cout << w[i] << " ";
        i = t[i];
    }
}

int main(){
    freopen("balo1.INP", "r", stdin);
    freopen("balo1.OUT", "w", stdout);
    enter();
    cout << optimize() << endl;
    trace();
    return 0;
}
