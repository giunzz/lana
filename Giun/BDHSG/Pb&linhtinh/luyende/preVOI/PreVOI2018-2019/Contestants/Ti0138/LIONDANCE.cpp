#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int n, delta;
const int maxn = 4e3 + 1;
int L[maxn], R[maxn];
int res[maxn], s[maxn];
int cnt, maxl;

void Input()
{
    cin >> n >> delta;
    for (int i = 1; i <= n; i++)
        cin >> L[i];
    for (int i = 1; i <= n; i++)
        cin >> R[i];
}

void Choose(int i, int posiR)
{
    if (i > n)
    {
        if (maxl < cnt)
        {
            for (int k = 1; k <= cnt; k++)
                res[k] = s[k];
            maxl = cnt;
        }
        else if (maxl == cnt)
        {
            bool check = false;
            for (int k = 1; k <= cnt; k++)
            if (res[k] < s[k])
            {
                check = true;
                break;
            }
            if (check)
            {
                for (int k = 1; k <= cnt; k++)
                res[k] = s[k];
            }
        }
        return;
    }

    if (cnt == 0 || abs(L[i] - s[cnt]) <= delta)
    {
        int j = posiR;
        while (j <= n && R[j] != L[i])
            j++;
        if (j <= n)
        {
            cnt++;
            s[cnt] = L[i];
            Choose(i + 1, j + 1);
            cnt--;
        }
        else
        {
            if (maxl < cnt)
            {
                for (int k = 1; k <= cnt; k++)
                    res[k] = s[k];
                maxl = cnt;
            }
            else if (maxl == cnt)
            {
                bool check = false;
                for (int k = 1; k <= cnt; k++)
                if (res[k] < s[k])
                {
                    check = true;
                    break;
                }
                if (check)
                {
                    for (int k = 1; k <= cnt; k++)
                    res[k] = s[k];
                }
            }
        }
    }
    Choose(i + 1, posiR);
}

void Output()
{
    cout << maxl << '\n';
    for (int i = 1; i <= maxl; i++)
        cout << res[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //freopen("test.inp" , "r" , stdin);
    //freopen("test.out" , "w" , stdout);

    freopen("LIONDANCE.INP" , "r" , stdin);
    freopen("LIONDANCE.OUT" , "w" , stdout);

    Input();
    maxl = 0;
    cnt = 0;
    Choose(1, 1);
    Output();
}

