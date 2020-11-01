#include <bits/stdc++.h>
#define maxn 1000006
#define max1 1000000007

using namespace std;
int n, k, a[maxn], f[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("gifts.inp","r",stdin);
    freopen("gifts.out","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n - k + 1; i++)
    {
        int sum = 0;
        int j = i + k - 1;
        for (int dc = i; dc <= j; dc++) sum += a[dc];
        f[i] = sum;
    }
    int dcm = max1;
    for (int i = 1; i <= n - k + 1; i++)
    {
        int dcm1 = -max1;
        for (int j = 1; j <= n - k + 1; j++)
            if (i != j)
            {
                dcm1 = max(dcm1, f[j]);
            }
        dcm = min(dcm, dcm1);
    }
    cout << dcm;
}
