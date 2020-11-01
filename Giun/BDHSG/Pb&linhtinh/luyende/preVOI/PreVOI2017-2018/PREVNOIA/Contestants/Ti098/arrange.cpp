#include <bits/stdc++.h>
#define FILE "arrange"
const int N = 1e5+7,oo = 1e9+7;
using namespace std;
int n,a[N],x,y,tb,MAX,MIN,ans;
long long s;
int main()
{
    ios_base::sync_with_stdio(0);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;++i)
    {
        cin >> a[i];
        s+=a[i];
    }
    tb = s/n;
    x = -s+tb*n+n;
    y = (n-x);
    MAX = 0;MIN = n+1;
    a[0] = -oo;
    a[n+1] = oo;
    for (int i=1;i<=n;++i) if (a[MAX]<a[i]) MAX = i;
        for (int i=1;i<=n;++i)
        {
            if (a[MIN]>a[i]) MIN = i;
            if (a[MIN]==a[i]) if (abs(MAX-MIN)>abs(MAX-i)) MIN = i;
        }
        for (int i=1;i<=n;++i) if (a[MAX]==a[i]) if (abs(MAX-MIN)>abs(MIN-i)) MAX = i;
    while (a[MAX]-a[MIN]>1)
    {
        a[MAX]--;
        a[MIN]++;
        ans+=abs(MAX-MIN);
        MAX = 0;
        MIN = n+1;
        for (int i=1;i<=n;++i) if (a[MAX]<a[i]) MAX = i;
        for (int i=1;i<=n;++i)
        {
            if (a[MIN]>a[i]) MIN = i;
            if (a[MIN]==a[i]) if (abs(MAX-MIN)>abs(MAX-i)) MIN = i;
        }
        for (int i=1;i<=n;++i) if (a[MAX]==a[i]) if (abs(MAX-MIN)>abs(MIN-i)) MAX = i;
    }
    cout << ans;
    return 0;
}
