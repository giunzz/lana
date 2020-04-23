#include <bits/stdc++.h>

using namespace std;
const int maxn = 1000;
long int a[maxn + 5], L[maxn + 5], T[maxn + 5], n;

void enter(){
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void optimize(){

    long int i, j, jmax;
    a[0] = -32768, a[n + 1] = 32767;
    L[n + 1] = 1;

    for (i = n; i >= 0; i--){
        jmax = n + 1;

        for (j = i + 1; j <= n + 1; j++)
            if ((a[j] > a[i]) && (L[j] > L[jmax])) jmax = j;

        L[i] = L[jmax] + 1;
        T[i] = jmax;

    }

    cout << L[0] - 2 << endl;

    i = T[0];

    while (i != n + 1){
        cout << a[i] << " ";
        i = T[i];
    }
}

int main(){
    freopen("dondieudainhat.INP", "r", stdin);
    freopen("dondieudainhat.OUT", "w", stdout);
    enter();
    optimize();
    return 0;
}
