#include<bits/stdc++.h>

const int maxN = 5e4 + 5;
const int maxT = 1e9;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define READ(F)   freopen(F".inp", "r", stdin)
#define WRITE(F)  freopen(F".out", "w", stdout)
#define ll        long long
#define F         "minsum"

using namespace std;

ll T, x, y, a, b, s[maxN], temp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    READ(F);
    WRITE(F);
    For(i, 1, sqrt(maxT)) s[i] = i * i;
    cin >> T;
    for(int ii = 1; ii <= T; ii++)
    {
        cin >> x >> y;
        temp = __gcd(x, y);
        x   /= temp;
        y   /= temp;
        a = sqrt(x);
        b = sqrt(y);
        for(int i = a; i >= 1; i--)
        {
            if(x % s[i] == 0)
            {
                x /= s[i];
                break;
            }
        }
        for(int i = b; i >= 1; i--)
        {
            if(y % s[i] == 0)
            {
                y /= s[i];
                break;
            }
        }
        cout << x << ' ' << y << '\n';
    }
}
