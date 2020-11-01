// He always smiles :)
#include <bits/stdc++.h>
#define maxn 105
#define mod 1000000007
#define pii pair<int, int>
#define f first
#define s second
#define pb push_back
#define task "MODULO"
#define ll long long
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
int a, b, n, s[maxn];
bool ok=0;
string kq;
ll k, res;
int du(string a, ll b)
{
    ll r = 0;
    for (int i = 0 ; i < a.length() ; i ++ )
    {
        ll chia = (a[i]-48)+r*10;
        r = chia%b;
    }
    return r;
}
bool check(string &ss)
{
    ss.clear();
    for (int i = 0 ; i < n ; i ++ ) ss = ss + char(s[i]+48);
    if(du(ss, res)==k) return 1;
    return 0;
}
void dq(int i)
{
    if(i==n)
    {
        if(check(kq)) {cout << kq; ok = 1;exit(0);}
        return;
    }
    s[i] = a;
    dq(i+1);
    s[i] = b;
    dq(i+1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> a >> b >> n >> k;
    res = 1 << n;
    if(n<=20)dq(0);
    if(!ok) cout << -1;
    return 0;
}
