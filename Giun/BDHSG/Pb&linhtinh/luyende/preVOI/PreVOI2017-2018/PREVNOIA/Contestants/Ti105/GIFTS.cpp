#include <bits/stdc++.h>
#define f0(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define nmax 1000002

using namespace std;
typedef long long ll;

int n, k; ll a[nmax], f[nmax], t[nmax], resx[nmax], resn[nmax];

void init(){
    t[0] = 0;
    f1(i, n) t[i] = t[i-1] + a[i];

    f1(i, n){
        if(i>=k){
            f[i] = t[i] - t[i-k];
        }
    }
    f1(i, n + 1){
        resx[i] = resn[i] = -1e17;
    }
    for(int i=k; i<=n; i++){
        resx[i] = max(resx[i-1], f[i]);
    }
    for(int i=n; i>=k; i--){
        resn[i] = max(resn[i+1], f[i]);
    }
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("GIFTS.inp", "r", stdin);
    freopen("GIFTS.out", "w", stdout);

    cin >> n >> k;
    f1(i, n) cin >> a[i];

    init();

    ll res = 1e17;
    f1(i, n - k + 1){
        int u = i, v = i + k - 1;
        int k1 = u - k;
        ll val = -1e17;
        if(k1>=k){
            val = resx[k1];
        }
        int k2 = v + k;
        if(k2<=n){
            val = max(val, resn[k2]);
        }
        if(val>0)
            res = min(res, val);
    }
    cout << res;
}
