#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e5 + 7;
int n, a[MAXN], f[MAXN], han[MAXN], res = 0;
main()
{
    freopen("arrange.inp","r",stdin);
    freopen("arrange.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    int val1 = 0, val2 = 0;
    int cur = f[n] / n;
    val2 = f[n] % n;
    val1 = n - val2;
    for(int i = 1 ; i <= n ; i++)
    {
        if (val1 == 0)
        {
            han[i] = cur + 1;
            val2--;
        }
        else if (val2 == 0)
        {
            han[i] = cur;
            val1--;
        }
        else if (val1  && val2 && abs(cur - a[i]) < abs(cur + 1 - a[i]))
        {
            han[i] = cur;
            val1--;
        }
        else
        {
            han[i] = cur + 1;
            val2--;
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if (a[i] == han[i]) continue;
        if (a[i] > han[i])
        {
            a[i + 1] += a[i] - han[i];
            res += a[i] - han[i];
            a[i] = han[i];
        }
        else
        {
            int cur = han[i] - a[i];
            for(int j = i + 1 ; j <= n ; j++)
                if (f[j] - f[i] >= cur)
                {
                    int temp = (f[j] - f[i]) - cur;
                    res += a[j] - temp;
                    a[j] = temp;
                    for(int k = j - 2 ; k >= i ; k--)
                    {

                        a[k] += a[k + 1];
                        a[k + 1] = 0;
                    }
                    break;
                }
        }
    }
    cout << res;
    return 0;
}
