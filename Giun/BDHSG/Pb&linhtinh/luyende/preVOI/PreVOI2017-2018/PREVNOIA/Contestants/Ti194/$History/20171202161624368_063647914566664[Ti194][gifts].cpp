#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 7;

int b[maxn], n, m, a[maxn], dem = 0;

bool d2[maxn], lap[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &b[i]);
        d2[b[i]] = true;
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
        scanf("%d", &a[i]);
        int t = a[i];
        int n = 0;
        while(t){
            n += a[i];
            if(lap[n])
                continue;
            if(n > (int)1e6)
                break;
            lap[n] = true;
            t--;
            if(d2[n])
                dem++;
        }
    }
    cout << dem;
}
