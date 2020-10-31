//POTK29 :)
#include <bits/stdc++.h>
#define maxn 10000000
#define mod 1000000009
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
//#define f first
//#define s second
#define task "ICECREAM"

using namespace std;
int n, mmax, m50, m1, m2, cnt = 0, x[maxn];
vector <int> v;

void check()
{
    int n50 = m50, n1 = m1, n2 = m2;
    for(int i = 1; i <= n; i++)
    {
        if(x[i] == 50) ++n50;
        if(x[i] == 100)
        {
            if(n50 < 1) return;
            else --n50;
            ++n1;
        }

        else if(x[i] == 200)
        {
            if(n1 < 1 && n50 < 3) return;
            if(n1 > 1)
            {
                    --n1;
                    --n50;
            }
            else n50 -= 3;
            ++n2;
        }
    }
    ++cnt;
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
    scanf("%d%d", &n, &mmax);
    scanf("%d%d", &m50, &m1, &m2);
    v.pb(50);
    v.pb(100);
    v.pb(200);
    dq(1);
    cout << cnt;
    return 0;
}
