#include<bits/stdc++.h>
#define maxn 3003
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

int m, n, k;
long long a[maxn], b[maxn];
long long kq[2*maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("SEQUENCE.INP", "r", stdin);
    freopen("SEQUENCE.OUT", "w", stdout);

    cin >> m >> n >> k;

    for(int i = 1; i <= m; i++)
        cin >> a[i];
    for(int j = 1; j <= n; j++)
        cin >> b[j];
        int ta = 0, tma = 0, tb = 0;
        for(int i = 1; i <= k; i++)
            kq[i] = 1e18;
    for(int i = 1; i <= k; i++)
    {
        long long sa2 = 1e18, sb2 = 1e18, mb = 1e18;
        for(int j = ta+1; j <= min(ta+(m-ta+n-tb - (k-i)),m); j++)
        if(kq[i] > a[j]){
            sa2 = kq[i];
            kq[i] = a[j];
            tma = j;
        }
        for(int j = tb+1; j <= min(tb+(m-ta+n-tb - (k-i)),n); j++)
        {
            if(mb >= b[j])
               {
                   sb2 = mb;
                    mb = b[j];
               }
            if(kq[i] == b[j]&&sb2 > sa2)
            {
                tma = ta;
            tb = j;
            }
        else if(kq[i] > b[j]){
            sb2 = kq[i];
            kq[i] = b[j];
            tma = ta;
            tb = j;
        }
        }
        ta = tma;
    }
    for(int i = 1; i <= k; i++)
        cout << kq[i] << " ";
}
