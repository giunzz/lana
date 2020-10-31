#include <bits/stdc++.h>
#define LL long long
using namespace std;

void load() {
    #ifndef ONLINE_JUDGE
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    #endif // ONLINE_JUDGE
}

LL Pow[100];
map < LL , string > Map;
LL Base;
LL nhan(LL a, LL b) {
    if (a == 0 || b == 0) return 0;
    if (b == 1) return a;
    if (a == 1) return b;
    LL res = nhan(a,b/2);
    res += res;
    res %= Base;
    if (b % 2) res += a;
    res %= Base;
    return res;
}

void trungtt() {
    int a,b;
    cin >> a >> b;
    int n,k;
    cin >> n >> k;
     Base = (1LL << n);
    Pow[0] = 1;
    string y = "";
    LL tmp = 0;

    for (int i = 1 ; i <= n ; ++ i)
        Pow[i] = (Pow[i-1] * 10) % Base;
    if (n > 40) {
        srand(time(NULL));
        for (int i = 1 ; i < n - 37 ; ++ i) {
            int ran = rand()  % 2;
            tmp = tmp * 10;
            tmp %= Base;
            if (ran == 0)
                tmp += a,
                y += char('0'+a);
            else
                tmp += b,
                y += char('0'+b);
            tmp %= Base;
        }
        n = 37;
        tmp = nhan(tmp,Pow[37]);
    }

    int m = (n / 2);
    if (n == 1) {
        if (a == k) printf("%d",a);
        else
            if (b == k) printf("%d",b);
        else
            printf("-1");
        return ;
    }
    for (int i = 0 ; i < (1 << m) ; ++ i) {
        string x = "";
        LL Sum = 0;
        for (int j = 0 ; j < m ; ++ j) {
            if (i & (1 << j))
                x += char('0' + a),
                Sum = (Sum * 10 + a) % Base;
            else
                x += char('0' + b),
                Sum = (Sum * 10 + b) % Base;
        }
        Sum = nhan(Sum, Pow[n-m]);
        Sum += tmp;
        Sum %= Base;
        Map[Sum] = x;
    }

    int l = n - m;
    for (int i = 0 ; i < (1 << l) ; ++ i) {
        string x = "";
        LL Sum = 0;
        for (int j = 0 ; j < l ; ++ j) {
            if (i & (1 << j))
                x += char('0' + a),
                Sum = (Sum * 10 + a) % Base;
            else
                x += char('0' + b),
                Sum = (Sum * 10 + b) % Base;
        }
        if (Sum <= k) Sum = k - Sum;
        else Sum = Base - Sum + k;
        if (Map.find(Sum) == Map.end()) continue;
        cout << y << Map[Sum] << x;
        return ;
    }
    printf("-1");


}

int main() {
    load();
    trungtt();
    return 0;
}
