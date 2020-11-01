#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int t, a, b, X, Y, Min, XX, YY;
vector <int> A, B, C, D;

int main()
{
    freopen("MINSUM.INP", "r", stdin);
    freopen("MINSUM.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        A.clear(); B.clear(); C.clear(); D.clear();
        int d = __gcd(a, b);
        a /= d; b /= d;
        X = a; Y = b;
        int i = 2;
        while (1ll*i*i <= a)
        {
            if (a % i == 0)
            {
                A.pb(i);
                B.pb(0);
                while (a % i == 0) B[B.size()-1]++, a /= i;
            }
            i++;
        }
        if (a > 1) A.pb(a), B.pb(1);

        i = 2;
        while (1ll*i*i <= b)
        {
            if (b % i == 0)
            {
                C.pb(i);
                D.pb(0);
                while (b % i == 0) D[D.size()-1]++, b /= i;
            }
            i++;
        }
        if (b > 1) C.pb(b), D.pb(1);

        for (int i=0; i<A.size(); i++)
            for (int j=1; j<=B[i] - B[i] % 2; j++) X /= A[i];
        for (int i=0; i<C.size(); i++)
            for (int j=1; j<=D[i] - D[i] % 2; j++) Y /= C[i];
        Min = 2e9+1;
        for (int i=1; i<=sqrt(X); i++)
            if (X % i == 0)
                for (int j=1; j<=sqrt(Y); j++)
                    if (Y % j == 0)
                    {
                        a = i; b = j;
                        if (1ll * X/a*b + 1ll *  Y*a/b < Min) Min = 1ll * X/a*b + 1ll *  Y*a/b, XX = X/a*b, YY = Y*a/b;
                        a = X/i; b = j;
                        if (1ll * X/a*b + 1ll *  Y*a/b < Min) Min = 1ll * X/a*b + 1ll *  Y*a/b, XX = X/a*b, YY = Y*a/b;
                        a = i; b = Y/j;
                        if (1ll * X/a*b + 1ll *  Y*a/b < Min) Min = 1ll * X/a*b + 1ll *  Y*a/b, XX = X/a*b, YY = Y*a/b;
                        a = X/i; b = Y/j;
                        if (1ll * X/a*b + 1ll *  Y*a/b < Min) Min = 1ll * X/a*b + 1ll *  Y*a/b, XX = X/a*b, YY = Y*a/b;
                    }
        cout << XX << " " << YY << "\n";
    }
    return 0;
}
