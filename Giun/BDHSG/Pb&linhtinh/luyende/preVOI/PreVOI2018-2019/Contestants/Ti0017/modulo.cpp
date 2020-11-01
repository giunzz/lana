#include <bits/stdc++.h>
#define crys "modulo"

using namespace std;

char kt[10]={'0','1','2','3','4','5','6','7','8','9'};
int a, b, xd[50];
long long n, k, du;
bool ok;

void ktra()
{
    long long so = 1;
    string kq = "";
    for (int i=1; i<=n; ++i)
    {
        so = (so*10)%du;
        if (xd[i])
        {
            so = (so+b)%du;
            kq+=kt[b];
        } else
        {
            so = (so+a)%du;
            kq+=kt[a];
        }
    }
    if (so==k) {ok=true; cout << kq;}
}

void di(int i)
{
    if (ok) return;
    for (int j=0; j<=1; ++j)
    {
        xd[i]=j;
        if (i==n) ktra(); else di(i+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(crys".inp", "r", stdin);
    freopen(crys".out", "w", stdout);
    cin >> a >> b;
    cin >> n >> k;
    du = 1;
    for (int i=1; i<=n; ++i) du*=2;
    if (n<=20)
    {
        ok = false;
        di(1);
        if (ok==false) cout << -1;
    } else cout << -1;
    return(0);
}
