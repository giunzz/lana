#include <bits/stdc++.h>
using namespace std;
int a[5], k, ans = 0;

int get(int &t){
    int no = t, a;
    while (no >= 3){
        a = t / 3;
        t = t % 3;
        no = a + t;
        ans += a;
    }
    return no;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a[1] >> a[2] >> a[3];
    sort(a + 1, a + 1 + 3);
    while (a[1] != 0 && a[2] != 0 && a[3] != 0){
        a[0] = a[1];
        ans += (a[2] / a[1]) * a[1]; 
        a[1] = a[2] % a[0];
        a[2] = a[0];
        sort(a + 1, a + 1 + 3);
    }
    cout << ans;
}