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
        L[i] = L[jmax] + 1; //do dai lon nhat cua day tang tai vi tri i
        T[i] = jmax; //ghi lai phan tu gan nhat cua day tang
    }
    cout << L[0] - 2 << endl; //tru 2 phan tu a[0] va a[n+1]
    i = T[0];
    while (i != n + 1){
        cout << a[i] << " ";
        i = T[i];
    }
}

int main(){
    freopen("daytang.INP", "r", stdin);
    freopen("daytang.OUT", "w", stdout);
    enter();
    optimize();
    return 0;
}

