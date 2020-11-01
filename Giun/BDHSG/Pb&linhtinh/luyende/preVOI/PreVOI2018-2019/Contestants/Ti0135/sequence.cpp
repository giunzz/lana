#include<bits/stdc++.h>

#define maxn 3003

using namespace std;

int n, k, m, a[maxn], b[maxn],  kq[2 * maxn];
int main()
{
    freopen("sequence.inp", "r", stdin);
    freopen("sequence.out", "w", stdout);
    scanf("%d %d %d", &m, &n, &k);

    for(int i = 1; i <= m; ++i) scanf("%d", &a[i]);
    for(int j = 1; j <= n; ++j) scanf("%d", &b[j]);
    if(m + n == k){
        int u = 1, v = 1, sl = 0;
        while(u <= m && v <= n)
        {
            if(a[u] <= b[v] && u <= m) kq[++sl] = a[u], u++;
            else if(v <= n)kq[++sl] = b[v], v++;
            else if(u > m) kq[++sl] = b[v];
            else kq[++sl] = a[u];

        }
    }

    for(int i = 1; i <= k; i++) printf("%d ", kq[i]);

}

