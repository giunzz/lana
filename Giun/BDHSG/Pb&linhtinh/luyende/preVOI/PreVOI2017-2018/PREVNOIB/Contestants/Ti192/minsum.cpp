#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,a,b,s,u;
int mu(int x, int n)
{
    if (n==0) return 1;
    int d=mu(x,n/2);
    d=d*d;
    if (n%2==0) return d;
    return d*x;
}
void tinh(int &c)
{
    int x=c;
    for (int i=2; i<=sqrt(x); i++)
    {
        int d=0;
        while (x%i==0)
        {
            d++;
            x=x/i;
        }
        d=d-d%2;
        c=c/(mu(i,d));
    }
}
vector<int>va;
vector<int>vb;
int main()
{
    freopen("minsum.inp","r",stdin);
    freopen("minsum.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--)
    {
        cin >> a >> b;
        if (a==b)
        {
            cout << 1 << " " << 1 << '\n';
            continue;
        }
        u=__gcd(a,b);
        a=a/u;
        b=b/u;
        tinh(a);
        tinh(b);
        ll s=(ll) a*b;
        ll x=a,y=b;
        if (sqrt(s)<=100000)
        {
            for (ll i=1; i<=sqrt(s); i++)
                if (s%i==0)
                    if (i+s/i<x+y)
                    {
                        x=i;
                        y=s/i;
                    }
        }
        cout << x << " " << y << '\n';
    }
}
