#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 1e6 + 100;
int n,k;
LL b,val[N],sum[N], it[5 * N];
const LL oo = 1e18;

void load() {
    freopen("gifts.inp","r",stdin);
    freopen("gifts.out","w",stdout);
}
void init(int k, int l, int r) {

    if (r < l)
        return ;
    if (l == r)  {
        it[k] = sum[l];
        return ;
    }

    int tmp = (l + r) / 2;

    init(k*2,l,tmp);init(k*2+1,tmp+1,r);

    it[k] = max(it[k * 2],it[k*2 + 1]);

    return ;
}

LL get(int k, int x, int y, int l, int r) {

    if (l > y || r < x)
        return 0;

    if (l >= x && r <= y)
        return it[k];

    int tmp = (l + r) / 2;

    return max(get(k*2,x,y,l,tmp),get(k*2+1,x,y,tmp+1,r));

}
void process() {

    scanf("%d%d",&n,&k);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%lld",&b);
        val[i] = val[i-1] + b;
    }

    for (int i = k ; i <= n ; ++ i)
        sum[i] = val[i] - val[i-k];



    init(1,1,n);

    LL  ans = oo;
    for (int i = k; i < n ; ++ i) {
        if (max(get(1,1, i - k,1,n),get(1,i+k,n,1,n)) <= sum[i])
            ans = min(ans,sum[i]);
    }

    printf("%lld",ans);
}

int main() {
    load();
    process();
    return 0;
}
