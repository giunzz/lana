#include <bits/stdc++.h>
#define Pii pair<int,int>
#define fi first
#define se second
#define MAXN 1000005

using namespace std;

int n,k,a[MAXN];
long long b[MAXN],s=0,mi=1e15;
Pii c[MAXN];


int main()
{
    ifstream cin("GIFTS.inp");
    ofstream cout("GIFTS.out");
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=k; i++) s+=a[i];
    for(int i=1; i<=n-k+1; i++){
        b[i]=s;
        s-=a[i];
        s+=a[i+k];
        c[i]=Pii(i,i+k-1);
    }
    for(int i=1; i<=n-k+1; i++){
        int l=c[i].fi, r=c[i].se;
        long long ma=0;
        for(int j=1; j<=n-k+1; j++){
            int u=c[j].fi, v=c[j].se;
            if(l<=u && u<=r) continue;
            if(l<=v && v<=r) continue;
            ma=max(ma,b[j]);
        }
        mi=min(mi,ma);
    }
    cout << mi;
    return 0;
}
