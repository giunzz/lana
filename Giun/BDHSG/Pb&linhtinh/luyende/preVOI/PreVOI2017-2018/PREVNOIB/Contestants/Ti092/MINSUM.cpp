
#include <iostream>
#include<cstdio>
#include<algorithm>
#include<map>

#define ll long long
#define fti(i, x, y) for(int i = (x), _y = (y); i <= _y; ++i)
#define ftd(i, x, y) for(int i = (x), _y = (y); i >= _y; --i)

using namespace std;
int T, cnt;
int a, b, p[2];
const int maxn = 1e5 + 1;
bool check[maxn];
int prime[maxn];

void io()
{
    freopen("MINISUM.inp", "r", stdin);
    freopen("MINISUM.out", "w", stdout);
}
void Process()
{
    p[0] = p[1] = 1;
    cin >> a >> b;
    a /= __gcd(a, b);
    b /= __gcd(a, b);
    int t = 0;
    for(int i = 2; i * i <= a; ++ i){
        t = 0;
        while(a % i == 0){
            ++ t;
            a /= i;
        }
        if(t % 2 == 0) continue;
        else p[0] *= i;
    }
    if(a > 1) p[0] *= a;
    for(int i = 2; i * i <= b; ++ i){
        t = 0;
        while(b % i == 0){
            ++ t;
            b /= i;
        }
        if(t % 2 == 0) continue;
        else p[1] *= i;
    }
    if(b > 1) p[1] *= b;
    cout << p[0] << " " << p[1] << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    io();
    cin >> T;
    while(T --) Process();
}
