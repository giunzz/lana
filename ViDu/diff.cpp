#include <bits/stdc++.h>
using namespace std;
int a, n[100], madiff;

void sol(int l, int r, int mad, int ma, int mi){
    int mid;
    static int mad1, ma1, mi1, mad2, ma2, mi2;
    if(l == r) {
        madiff = 0;
        ma = a[r];
        mi = a[r];
    }
    else{
        mid = (l + r) / 2;
        sol(1, mid, ma)
    }
}

void enter(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

int main(){
    freopen("diff.inp", "r", stdin);
    freopen("diff.out", "w", stdout);
    enter();
    sol(1, n);
}
