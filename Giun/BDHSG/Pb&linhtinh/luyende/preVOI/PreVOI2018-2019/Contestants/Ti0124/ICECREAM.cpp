#include <bits/stdc++.h>
using namespace std;

const int maxn = 310;
const int mod = 1000000009;

long long n, mmax, m50, m1, m2, res, a[maxn];

bool solve()
{
    int xu50 = m50, xu1 = m1, xu2 = m2;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == 50)
        {
            xu50++;
            if(xu50 > mmax) return false;
        }
        if(a[i] == 1)
        {
            if(xu50 > 0)
            {
                xu50--;
                xu1++;
                if(xu1 > mmax) return false;
            }
            else return false;
        }
        if(a[i] == 2)
        {
            bool ok1 = false, ok2 = false;
            if(xu1 > 0 && xu50 > 0)
            {
                m2++;
                if(m2 > mmax) return false;
                ok1 = true;
                xu1--; xu50--;
            }
            if(!ok1)
            {
                if(xu50 >= 3)
                {
                    m2++;
                    if(m2 > mmax) return false;
                    ok2 = true;
                    xu50 -= 3;
                }
                if(!ok2) return false;
            }
        }
    }
    return true;
}

void Try(int x)
{
    if(x > n)
    {
        //solve();
        if(solve())
        {
            //for(int i = 1; i <= n; i++) cout << a[i] << ' ';
            res = (res + 1) % mod;
            //cout << '\n';
        }
        return;
    }
    for(int i = 0; i <= 2; i++)
    {
        if(i == 0) a[x] = 50;
        else a[x] = i;
        Try(x + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("ICECREAM.inp","r",stdin); freopen("ICECREAM.out","w",stdout);
    cin >> n >> mmax >> m50 >> m1 >> m2;
    Try(1);
    cout << res;
}
