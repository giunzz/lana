#include <stdio.h>
#include <algorithm>
#include <cmath>

#define fti(i, x, y) for(int i = (x), _y = (y); i <= _y; ++ i)
#define ftd(i, x, y) for(int i = (x), _y = (y); i >= _y; -- i)
#define ll long long

using namespace std;

const int N = 102;
int t, cnt;
ll a, b, d, res, tsnt[N], gh, kqa, kqb;
bool dd[N];

void fr()
{
    freopen("MINSUM.inp", "r", stdin);
    freopen("MINSUM.out", "w", stdout);
}

void inp()
{
    scanf("%lld %lld", &a, &b);
    d = __gcd(a, b);
    a /= d, b /= d;
}

void btr(ll S)
{
    if(res > (a * b) / S + S) res = (a * b) / S + S, kqa = S, kqb = (a * b) / S;
    fti(i, 1, cnt)
        if(!dd[i]) {
            if(S * tsnt[i] > gh) continue;
            dd[i] = true;
            btr(S * tsnt[i]);
            dd[i] = false;
        }
}

void proc()
{
    res = 1e18; cnt = 0;
    int tga = a, tgb = b, j = 2;
    a = 1;
    while(j * j <= tga) {
        cnt = 0;
        while(tga % j == 0) ++ cnt, tga /= j;
        if(cnt % 2) a *= j;
        ++ j;
    }
    a *= tga;

    b = 1; j = 2;
    while(j * j <= tgb) {
        cnt = 0;
        while(tgb % j == 0) ++ cnt, tgb /= j;
        if(cnt % 2) b *= j;
        ++ j;
    }
    b *= tgb;

    j = 2; tga = a; cnt = 0;
    while(j * j <= tga) {
        while(tga % j == 0) tga /= j, tsnt[++ cnt] = j;
        ++ j;
    }
    j = 2; tgb = b;
    if(tga > 1) tsnt[++ cnt] = tga;
    while(j * j <= tgb) {
        while(tgb % j == 0) tgb /= j, tsnt[++ cnt] = j;
        ++ j;
    }
    if(tgb > 1) tsnt[++ cnt] = tgb;

    gh = sqrt(a * b);
    btr(1);
    printf("%lld %lld\n", kqa, kqb);
}

int main()
{
    fr();
    scanf("%d", &t);
    while(t --) {
        inp();
        proc();
    }
    return 0;
}
