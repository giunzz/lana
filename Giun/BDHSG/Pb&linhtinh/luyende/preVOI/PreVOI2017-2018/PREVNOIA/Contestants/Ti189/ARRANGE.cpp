#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a); i <= (b); i ++)
#define FORd(i, a, b) for(int i = (a); i >= (b); i --)
#define FORv(i, a, b) for(int i = (a); i < (b); i ++)
#define II pair<int, int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn = 1e5 + 69;
ll n, a[maxn], sum;
int main()
{
    freopen("ARRANGE.inp", "r", stdin);
    freopen("ARRANGE.out", "w", stdout);
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%lld", &n);
    FOR(i, 1, n){
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    if(sum % n == 0){
        sum = sum / n;
        ll res = 0, du = 0;
        FOR(i, 1, n){
            res += abs(du);
            a[i] += du;
            du = a[i] - sum;
            a[i] = sum;
        }
        printf("%lld", res);
        return 0;
    }
    return 0;
}
