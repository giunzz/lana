#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
const int maxn = 1e7;
long long n,k;
long long check,a[maxn],x[maxn],res,ress[maxn];
long long ans,dem;

using namespace std;

void Attempt(int i)
{
        if (i == n)
    {
        res = x[0];
        int cnt=1;
        int t = 0;
        for (int j = 1; j < n; j++)
            {
                res = res * 10 + x[j];
                cnt++;
                if (cnt == n)
                {
                    ress[t] = res;
                    t++;
                    dem++;
                    cnt = 0;
                }
            }
         for (int m = 0; m < dem; m++)
            {
                long long mod = pow(2,n);

                ans = ress[m] % mod;

                if (ans == k)
                {
                    cout << ress[m];
                    //cout << endl;
                    check = true;
                }
            }
        return;
    }
    else
        for (int k = 1; k <= 2; k++)
    {
        x[i] = a[k];
        Attempt(i + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("MODULO.INP","r",stdin);
    freopen("MODULO.OUT","w",stdout);
    cin >> a[1] >> a[2];
    cin >> n >> k;
    Attempt(0);
    if (check == false) cout << -1;


}

