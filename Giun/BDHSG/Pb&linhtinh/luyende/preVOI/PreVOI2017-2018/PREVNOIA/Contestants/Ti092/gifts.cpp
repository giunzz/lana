
#include <iostream>
#include<cstdio>
#include<algorithm>

#define ll long long
#define fti(i, x, y) for(int i = (x), _y = (y); i <= _y; ++i)
#define ftd(i, x, y) for(int i = (x), _y = (y); i >= _y; --i)

using namespace std;

const int maxn = 1e5 + 1;
int n, k, id;
ll a[maxn], sum[maxn], _max, res;

void Input()
{
    cin >> n >> k;
    fti(i, 1, n) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
}
void Process()
{
    ll tmp = 0;
    int x = 0;
    fti(i, k, n){
        if(sum[i] - sum[i - k] > _max){
            _max = sum[i] - sum[i - k];
            id = i;
        }
        else if(sum[i] - sum[i - k] == _max && a[id - k] < a[i + 1]) id = i;
    }
    fti(i, id + k, n)
        res = max(res, sum[i] - sum[i - k]);
    if(id - k >= k)
        fti(i, k, id - k) res = max(res, sum[i] - sum[i - k]);
    cout << res;
}
void io()
{
    freopen("gifts.inp", "r", stdin);
    freopen("gifts.out", "w", stdout);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    io();
    Input();
    Process();
}
