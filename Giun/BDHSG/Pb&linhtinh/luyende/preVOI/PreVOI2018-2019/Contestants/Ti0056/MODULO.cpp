#include<bits/stdc++.h>
#define maxn 1048600
using namespace std;

typedef long long ll;

ll MOD, HS;

struct data
{
    int u, id;
} P[maxn], Q[maxn];

int A, B, n, k, dem1(0), dem2(0), x1(0), x2(0);

string S = "";

int cmp(data a, data b)
{
    return a.u < b.u;
}

void solve1(int l, int r)
{
    int x = r - l + 1;

    x1 = x;

    for(int i=0;i<(1<<x);i++)
    {
        ll cs = 1;
        int ans = 0;
        for(int j=0;j<x;j++)
        {
            if((i >> j) & 1)
            {
                ans = (ans + (A * cs) % MOD) % MOD;
            }
            else
            {
                ans = (ans + (B * cs) % MOD) % MOD;
            }
            cs = (cs * 10) % MOD;
        }
        P[i+1].id = i;
        P[i+1].u = ans;
    }

    sort(P+1, P+(1<<x)+1, cmp);
    dem1 = (1<<x);
}

void solve2(int l, int r)
{
    int x = r - l + 1;

    x2 = x;

    HS = 1ll;
    for(int i=1;i<=x;i++) HS = (HS * 10) % MOD;

    for(int i=0;i<(1<<x);i++)
    {
        ll cs = 1;
        int ans = 0;
        for(int j=0;j<x;j++)
        {
            if((i >> j) & 1)
            {
                ans = (ans + (A * cs) % MOD) % MOD;
            }
            else
            {
                ans = (ans + (B * cs) % MOD) % MOD;
            }
            cs = (cs * 10) % MOD;
        }
        Q[i+1].id = i;
        Q[i+1].u = ans;
    }

    sort(Q+1, Q+(1<<x)+1, cmp);

    dem2 = (1<<x);
}

void xuat(int x, int u)
{
    for(int i=x-1;i>=0;i--)
        if((u >> i) & 1) S = S + (char)(A + '0');
        else S = S + (char)(B + '0');
}

int main()
{
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.out","w",stdout);

    cin >> A >> B >> n >> k;

    MOD = (1<<n);

    if(n <= 40)
    {
        solve1(1, n/2);
        solve2(n/2+1, n);

        for(int i=1;i<=dem1;i++)
        {
            int l = 1, r = dem2, ans = -1, val;

            P[i].u = (P[i].u * HS) % MOD;

            val = (k - P[i].u + MOD) % MOD;

            while(l <= r)
            {
                int mid = (l+r)/2;
                if(Q[mid].u > val) r = mid - 1;
                else if(Q[mid].u < val) l = mid + 1;
                else
                {
                    ans = mid;
                    break;
                }
            }

            if(ans != -1)
            {
                xuat(x1, P[i].id);
                xuat(x2, Q[ans].id);
                while(S.length() > 1 && S[S.length()-1] == '0') S.erase(S.length()-1);
                cout << S;
                return 0;
            }
        }
    }
    cout << -1;
}
