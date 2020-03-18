#include<bits/stdc++.h>

using namespace std;

int d , m ,y , dnn = 0, y4 = 0, y100 = 0, y400 = 0, all4 = 0, ans, all100 = 0, all400 = 0, all = 0, t = 0;
int a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int co(int i){
    return y/i * i;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("bai27.inp", "r", stdin);
    freopen("bai27.out", "w", stdout);
    cin >> d >> m >> y;
    --y, --m;
    for (int i = 1; i <= m; i++) t += a[i];
    y4 = co(4), y100 = co(100), y400 = co(400);
    all4 = y4/4, all100 = y100/100, all400 = y400/400;
    all = all4 - (all100 - all400);
    ans = 365 * y + all + t + d;
    if ((((y + 1) % 4 == 0 && (y + 1) % 100 != 0) || (y + 1) % 400 == 0) && (m + 1 > 2)) {
            ++ans;
    }
    cout << ans;
}
