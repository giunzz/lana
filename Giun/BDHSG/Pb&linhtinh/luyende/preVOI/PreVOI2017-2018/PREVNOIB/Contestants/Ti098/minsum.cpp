#include <bits/stdc++.h>
#define FILE "minsum"
const int N = 1e6+7;
using namespace std;
int a,b,t;

bool check(int x)
{
    if (x<=3) return 1;
    for (int i=2;i<=sqrt(x);++i) if (x%i==0) return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        int tmp = __gcd(a,b);
        a/=tmp;
        b/=tmp;
        if (!check(a)) for (int i=sqrt(a);i>=2;--i) if (a%(i*i)==0) a/=i*i;
        if (!check(b)) for (int i=sqrt(b);i>=2;--i) if (b%(i*i)==0) b/=i*i;
        cout << a << " " << b << "\n";
    }
    return 0;
}
