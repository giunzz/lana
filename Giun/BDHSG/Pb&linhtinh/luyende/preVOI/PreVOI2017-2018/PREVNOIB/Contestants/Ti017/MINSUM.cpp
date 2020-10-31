#include <bits/stdc++.h>
#define FILE "MINSUM"

using namespace std;

int T, A, B, mn; bool fg;

void Hand(int X, int Y)
{
    for (int i=1; i<=sqrt(X); i++)
        if ( !(X %i))
        {
            int GCD = __gcd(X/i,Y*i);
            if (X/i/GCD + Y*i/GCD < mn){ mn = X/i/GCD + Y*i/GCD; A = X/i/GCD; B = Y*i/GCD; fg=1; }
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> T;
    while (T--)
    {
        cin >> A >> B; int GCD = __gcd(A,B); A /= GCD; B /= GCD;
        mn = A+B; fg=1;
        while (fg)
        {
            int preA = A, preB = B; fg = 0;
            Hand(preA,preB); Hand(preB,preA);
        }
        cout << A << " " << B << "\n";
    }
    return 0;
}
