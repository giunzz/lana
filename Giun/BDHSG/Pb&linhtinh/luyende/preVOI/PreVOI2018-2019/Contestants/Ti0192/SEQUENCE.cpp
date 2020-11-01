#define task "SEQUENCE"
#include <bits/stdc++.h>
using namespace std;

int m, n , k, t, pos, cnt;
int a[3005], b[3005], c[6005], add[3005], tk = 1;
bool checka[3005];

int Fil(int x, int t)
{
    //x là vị trí đặt, t là vị trí i trg th đó
    if (x == 0)
    {
        if (t <= k - n)
            return add[t];
        else
            return b[t - k + n];
    }
    if (t <= x)
        return b[t];
    else if (t <= k - n + x)
        return add[t - x];
    else return b[t - k + n];
}

bool Check(int x)
{
    //kt xem ở pos x có nhỏ hơn cấc pos trc ko
    for (int i = 1; i <= k; i++)
    {
        int a = Fil(x, i), b = Fil(pos, i);
        if (a < b)
            return 1;
        else if (a > b)
            return 0;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = m; cnt < k - n; i--)
    {
        if (i < 1)
        {
            i = m + 1;
            tk++;
        }
        if (a[i] == tk)
        {
            checka[i] = 1;
            cnt++;
        }
    }
    for (int i = 1; i <= m; i++)
        if (checka[i])
            add[++t] = a[i];
    for (int i = 1; i <= n; i++)
        if (Check(i))
            pos = i;
    for (int i = 1; i <= pos; i++)
        cout << b[i] << ' ';
    for (int i = 1; i <= k - n; i++)
        cout << add[i] << ' ';
    for (int i = pos + 1; i <= n; i++)
        cout << b[i] << ' ';
}


