#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define F first
#define S second
#define mp make_pair
#define LL long long
#define fort(i,a,b) for(LL i=(a); i<=(b); i++)
#define ford(i,a,b) for(LL i=(a); i>=(b); i--)

using namespace std;
LL n,k,a[1000005];
LL f[1000006];
LL maxx[1000006];
LL res = 0, tmp1, tmp2;
LL j = 0;
LL trc[1000006];

void Karl_Heinrich_Marx()
{
    freopen("gifts.inp","r",stdin);
    freopen("gifts.out","w",stdout);

}

void Vladimir_Ilyich_Lenin()
{
    res = 1e18;
    scanf("%lld %lld",&n,&k);
    fort(i,1,n) {
        scanf("%lld",&a[i]);
    }

    fort(i,1,n) {
        f[i] = f[i-1] + a[i];
    }

    for(LL i = 1; i + k - 1 <= n; i++) {
        maxx[i] = f[i+k - 1] - f[i-1];

    }

    ford( i, n - k + 1, 1 ) {
        trc[i] = max( trc[i+1], maxx[i] );
    }
    j = 0;

    fort(i,1,n) {
        if( i >= k ) tmp1 = max( tmp1, maxx[i-k] );
        while( i + k - 1 >= j ) {
            j++;
        }
        tmp2 = trc[j];
        res = min( res, max( tmp1, tmp2 ) );
    }

    printf("%lld",res);

}
int main()
{
    Karl_Heinrich_Marx();
    Vladimir_Ilyich_Lenin();
    return 0;
}
