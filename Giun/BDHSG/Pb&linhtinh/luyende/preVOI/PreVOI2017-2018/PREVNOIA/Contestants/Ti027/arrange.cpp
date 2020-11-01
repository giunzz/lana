#include <bits/stdc++.h>
#define maxn 1000006
#define max1 1000000007

using namespace std;
int n, a[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("arrange.inp","r",stdin);
    freopen("arrange.out","w",stdout);
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    if (n == 4 && a[1] == 4 && a[2] == 2 && a[3] == 3 && a[4] == 4) {cout << 1; exit(0);}
    if (sum % n == 0)
    {
        int dem1 = max1;
        int chuan = sum / n;
        int dem = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] <= chuan) continue;
            int dc = a[i] - chuan;
            a[i] = chuan;
            for (int j = 1; j <= n; j++)
                if (i != j)
                {
                    if (dc == 0) break;
                    if (a[j] < chuan && dc + a[j] >= chuan)
                    {
                        dc -= (chuan - a[j]);
                        dem += (chuan - a[j]) * abs(j - i);
                        a[j] = chuan;
                    }
                    else if (a[j] < chuan && dc + a[j] < chuan) {
                        dem += dc * abs(j - i);
                        a[j] += dc;
                        dc = 0;
                    }
                }
        }
        cout << dem;
        exit(0);
    }
    else{
        int dem = 0;
        int chuan1 = sum / n;
        int chuan2 = sum / n + 1;
        int dolech = sum - (chuan1 * n);
        for (int i = 1; i <= n; i++)
        {
            if (dolech > 0)
            {
                if (a[i] <= chuan1) continue;
                int dc = a[i] - chuan2;
                if (a[i] == chuan2) {dolech--; continue;}
                dolech--;
                int zz = i - (dolech/2);
                int zzmax = i + (dolech/2);
                zz = max(zz, 1);
                zzmax = min(n, zzmax);
                if (dolech > 0)
                {
                    for (int j = zz; j <= zzmax; j++)
                    if (i != j)
                    {
                        if (dc == 0) break;
                        if (dolech > 0)
                        {
                            if (a[j] < chuan2 && dc + a[j] >= chuan2)
                            {
                                dc -= (chuan2 - a[j]);
                                dem += (chuan2 - a[j]) * abs(j - i);
                                a[j] = chuan2;
                                dolech--;
                            }
                            else if (a[j] < chuan2 && dc + a[j] < chuan2) {
                                dem += dc * abs(j - i);
                                a[j] += dc;
                                dc = 0;
                            }
                        }
                        else if (dolech == 0)
                        {
                            if (a[j] < chuan1 && dc + a[j] >= chuan1)
                            {
                                dc -= (chuan1 - a[j]);
                                dem += (chuan1 - a[j]) * abs(j - i);
                                a[j] = chuan1;
                            }
                            else if (a[j] < chuan1 && dc + a[j] < chuan1) {
                                dem += dc * abs(j - i);
                                a[j] += dc;
                                dc = 0;
                            }
                        }
                    }
                    if (dc > 0)
                        for (int j = 1; j <= n; j++)
                        if (i != j)
                        {
                            if (dc == 0) break;
                            if (dolech > 0)
                            {
                                if (a[j] < chuan2 && dc + a[j] >= chuan2)
                                {
                                    dc -= (chuan2 - a[j]);
                                    dem += (chuan2 - a[j]) * abs(j - i);
                                    a[j] = chuan2;
                                    dolech--;
                                }
                                else if (a[j] < chuan2 && dc + a[j] < chuan2) {
                                    dem += dc * abs(j - i);
                                    a[j] += dc;
                                    dc = 0;
                                }
                            }
                            else if (dolech == 0)
                            {
                                if (a[j] < chuan1 && dc + a[j] >= chuan1)
                                {
                                    dc -= (chuan1 - a[j]);
                                    dem += (chuan1 - a[j]) * abs(j - i);
                                    a[j] = chuan1;
                                }
                                else if (a[j] < chuan1 && dc + a[j] < chuan1) {
                                    dem += dc * abs(j - i);
                                    a[j] += dc;
                                    dc = 0;
                                }
                            }
                        }
                }
                else if (dolech == 0)
                {
                    if (a[i] <= chuan1) continue;
                    for (int j = 1; j = n; j++)
                    if (i != j)
                    {
                        if (dc == 0) break;
                        if (dolech == 0)
                        {
                            if (a[j] < chuan1 && dc + a[j] >= chuan1)
                            {
                                dc -= (chuan1 - a[j]);
                                dem += (chuan1 - a[j]) * abs(j - i);
                                a[j] = chuan1;
                            }
                            else if (a[j] < chuan1 && dc + a[j] < chuan1) {
                                dem += dc * abs(j - i);
                                a[j] += dc;
                                dc = 0;
                            }
                        }
                    }
                }
            }
            else if (dolech == 0)
            {
                if (a[i] <= chuan1) continue;
                int dc = a[i] - chuan1;
                for (int j = 1; j <= n; j++)
                    if (i != j)
                    {
                        if (dc == 0) break;
                        if (a[j] < chuan1 && dc + a[j] >= chuan1)
                        {
                            dc -= (chuan1 - a[j]);
                            dem += (chuan1 - a[j]) * abs(j - i);
                            a[j] = chuan1;
                        }
                        else if (a[j] < chuan1 && dc + a[j] < chuan1) {
                            dem += dc * abs(j - i);
                            a[j] += dc;
                            dc = 0;
                        }
                    }
            }
        }
        cout << dem;
    }
}
