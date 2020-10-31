// He always smiles :)
#include <bits/stdc++.h>
#define maxn 305
#define mod 1000000009
#define pii pair<int, int>
#define f first
#define s second
#define pb push_back
#define task "ICECREAM"
#define ll long long
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
int n, ma, m5, m1, m2, a[maxn];
ll res(0);
bool check()
{
    int mm5 = m5, mm1 = m1, mm2 = m2;
    for (int i = 1 ; i <= n ; i ++ )
    {
        if(a[i]==50) ++mm5;
        if(a[i]==1)
        {
            if(mm5) ++mm1, --mm5;
            else return 0;
        }
        if(a[i]==2)
        {
            if(mm1&&mm5) ++mm2, --mm1, --mm5;
            else if(mm1==0 && mm5 > 2) ++mm2, mm5 -= 3;
            else return 0;
        }
        if(mm2 > ma || mm1 > ma || mm5 > ma) return 0;
    }
    return 1;
}
void dq(int i)
{
    if(i==n+1)
    {
        if(check()) ++res;
        if(res > mod) res -= mod;
        return;
    }
    a[i] = 50;
    dq(i+1);
    a[i] = 1;
    dq(i+1);
    a[i] = 2;
    dq(i+1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n >> ma;
    cin >> m5 >> m1 >> m2;
    dq(1);
    cout << res;
    return 0;
}
