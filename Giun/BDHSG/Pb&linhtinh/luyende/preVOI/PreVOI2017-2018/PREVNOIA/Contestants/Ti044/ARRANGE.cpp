#include<bits/stdc++.h>
#define maxn 100005
using namespace std;

struct data
{
    int u, vt;
};
int n, a[maxn], b[maxn], du;
long long sum(0), k, tong(0);

int main()
{
    freopen("ARRANGE.inp","r",stdin);
    freopen("ARRANGE.out","w",stdout);
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
        sum += a[i];
    }
    k = sum / n;
    du = ((sum % n)+n)%n;
    int v1(1), v2(1);  /// v1 for < k, v2 for > k
    while(v1<=n && v2<=n)
    {
        while(v1<=n && b[v1]>=k) ++v1;
        while(v2<=n && b[v2]<=k) ++v2;
        if( v1 > n || v2 > n ) break;
        int ff = min(k-b[v1], b[v2]-k);
        b[v1] += ff;
        b[v2] -= ff;
        tong += ff*(fabs(v1 - v2));
    }

    cout << tong;
}
