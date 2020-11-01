#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, A, B, ans1, ans2;
ll tich;

int solve(int a)
{
    int x = a;
    for(int i=2;i<=sqrt(a);i++)
    {
        while(x%(i*i)==0)
        {
            x = x / (i*i);
        }
    }
    return x;
}

void solve2(int a, int b)
{
    tich = 1ll*a*b;
    int x = (int)(sqrt(tich));
    while( tich % x != 0 )
    {
        --x;
    }
    cout << x << " " << tich/x << endl;
}

int main()
{
    freopen("MINSUM.inp","r",stdin);
    freopen("MINSUM.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>A>>B;
        int x = __gcd(A, B);
        A /= x;
        B /= x;
        A = solve(A);
        B = solve(B);
        solve2(A, B);
    }
}
