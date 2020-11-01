//POTK29 :)
#include <bits/stdc++.h>
#define maxn 100
#define mod 1000000007
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
//#define f first
//#define s second
#define task "ICECREAM"

using namespace std;
int a, b, n, x[maxn];
long long k, p;
vector <int> v;

void check()
{
    long long s = 0, d = 1;
    for(int i = n; i >= 1; i--)
    {
        s += (x[i]*d);
        d *= 10;
    }
    if(s % p == k)
    {
        cout << s;
        exit(0);
    }
}

void dq(int i)
{
    for(int u : v)
    {
        x[i] = u;
        if(i == n) check();
        else dq(i+1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &a, &b);
    scanf("%d%d", &n, &k);
    v.pb(a); v.pb(b);
    p = (1 << n);
    dq(1);
    return 0;
}
