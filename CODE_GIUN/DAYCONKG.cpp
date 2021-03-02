#include <bits/stdc++.h>

using namespace std;
const int maxn = 1000 + 5;
long int a[maxn], L[maxn], T[maxn], n;

void enter(){
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void optimize(){
    long int i, j, jmax;
    a[0] = -2147483648, a[n + 1] = 2147483647;
    L[n + 1] = 1;
    for (i = n; i >= 0; i--){
        jmax = n + 1;
        for (j = i + 1; j <= n + 1; j++)
            if ((a[j] >= a[i]) && (L[j] > L[jmax])) jmax = j;
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
    freopen("DAYCONKG.INP", "r", stdin);
    freopen("DAYCONKG.OUT", "w", stdout);
    enter();
    optimize();
    return 0;
}

