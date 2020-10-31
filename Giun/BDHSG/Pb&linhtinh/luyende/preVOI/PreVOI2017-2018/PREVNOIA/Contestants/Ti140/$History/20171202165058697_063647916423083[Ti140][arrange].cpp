#include <bits/stdc++.h>
using namespace std;
#define ft(i,x,y) for (int i = x; i <= y; i++)
const int maxn = 1e5+2;
int n,sl,a[maxn];
long long x,kq = 0;
void Enter()
{
    scanf("%d",&n);
    x = 0;
    ft(i,1,n)
    {
        scanf("%d",&a[i]);
        x += (long long)a[i];
    }
}
void Solve()
{
    sl = x % n;
    sl = n - sl;
    x = x / n;
    for (int i = 1; i < n; i++)
    {
        if (a[i] <= x)
        {
            if (sl > 0)
            {
               sl--;
               kq += x - a[i];
               a[i+1] -= x - a[i];
               a[i] = x;
            }
            else
            {
                sl--;
                kq += x + 1 - a[i];
                a[i+1] -= x + 1 - a[i];
                a[i] = x + 1;
            }
        }
        else
        {
            if (sl < n - i + 1)
            {
                kq += a[i] - x - 1;
                a[i+1] += a[i] - x - 1;
                a[i] = x + 1;
            }
            else
            {
                sl--;
                kq += a[i] - x;
                a[i+1] += a[i] - x;
                a[i] = x;
            }
        }
    }
    cout<<kq<<endl;
}
int main()
{
    freopen("arrange.inp","r",stdin);
    freopen("arrange.out","w",stdout);
    Enter();
    Solve();
}
