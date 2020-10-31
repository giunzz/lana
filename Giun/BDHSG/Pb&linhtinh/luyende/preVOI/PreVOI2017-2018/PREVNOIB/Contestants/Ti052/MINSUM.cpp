#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 100015;
int tmp, i, j, t, k, sl, bn;
ll a[N], kt[N], prime[N], luu[N];
ll n, m, res;

void Init()
{
    int limit = 1e5;
    for(int i = 2; i <= limit; i ++)
        if(kt[i] == 0)
        {
            prime[++ sl] = i;
            for(int j = i ; j <= limit; j += i) kt[j] = i;
        }
//    cout << "sl  " << sl << "\n";
//    exit(0);
}
void ppsinh()
{
    t = 1 << bn;
    for(int i = 0 ; i < t; i ++)
    {
        ll tn = 1, tm = 1;
        for(int j = 0 ; j < bn; j ++)
            if((i >> j)&1) tn *= luu[j + 1];
            else tm *= luu[j + 1];
//        cout << "op  " << tn << "  " << tm << "  " << res << "\n";
        if(res >= tn + tm)
        {
            res = tn + tm;
            n = tn; m = tm;
//            cout << n << "  " << m << "  " << tn << "  " << tm << "\n";
        }
    }
//    cout << "kq  " << n << "  " << m << "\n";
}
void Sol()
{
//    cout << "nm  " << n*m << "\n";
    if(n < m) swap(n, m); res = n + m;
    t = sqrtl(n);
    int vt = 1; bn = 0;
//    cout << "t  " << prime[2] << "\n";
    while(vt <= sl && prime[vt] <= t)
    {
        tmp = prime[vt];
        if(n % tmp == 0 || m % tmp == 0)
        {
            int smu = 0;
            while(n % tmp == 0) n /= tmp, smu ++;
            while(m % tmp == 0) m /= tmp, smu ++;
            if(smu % 2 == 1) luu[++ bn] = tmp;
        }
//            cout << "uc  " << tmp << "\n";
        vt ++;
    }
    if(n == m) n = 1, m = 1;
    if(n > 1) luu[++ bn] = n;
    if(m > 1) luu[++ bn] = m;
//    cout << "nt  " ;for(int i = 1; i <= bn; i ++) cout << luu[i] << "  "; cout << "\n";
    ppsinh();
//    cout << res << "\n";
    cout << n << " " << m << "\n";
}

int main()
{
//#define file "r"
#define file "MINSUM"
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    Init();
    cin >> T;
//    T = 500;
    while(T --)
    {
        cin >> n >> m;
//        n = 1e9; m = n;
        Sol();
    }
    return 0;
}
