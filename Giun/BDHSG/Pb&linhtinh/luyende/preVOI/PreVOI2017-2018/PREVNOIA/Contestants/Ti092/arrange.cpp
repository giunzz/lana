
#include <iostream>
#include<cstdio>
#include<algorithm>

#define ll long long
#define fti(i, x, y) for(int i = (x), _y = (y); i <= _y; ++i)
#define ftd(i, x, y) for(int i = (x), _y = (y); i >= _y; --i)
using namespace std;

const int maxn = 1e5 + 1;
int n;
ll a[maxn], sum;

void Input()
{
    cin >> n;
    fti(i, 1, n) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1);
}
void Process1()
{
    sum /= n;
    ll res = 0;
    fti(i, 1, n){
        if(a[i] >= sum) break;
        res += sum - a[i];
    }
    cout << res;
}
void Process2()
{
    ll res = 0, s = 0;
    ll t = sum/n;
    int d = sum % n;
    fti(i, 1, n - d){
        if(a[i] < t) res += t - a[i];
        s += t - a[i];
    }
    ++ t;
    int i = n;
    if(s < 0) a[n] -= s;
    cerr << s;
    while(s > 0){
        if(a[i] - s >= t) {
                a[n] -= s;
                s = 0;
        }
        else {
            a[i] = t;
            res -= a[i] - t;
        }
    }
    fti(i, n - d + 1, n)
        if(a[i] < t) res += t - a[i];
    cout << res;
}
void io()
{
    freopen("arrange.inp", "r", stdin);
    freopen("arrange.out", "w", stdout);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    io();
    Input();
    if(sum % n == 0) Process1();
    else Process2();
}
