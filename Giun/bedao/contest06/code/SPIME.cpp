#include <bits/stdc++.h>

using namespace std;

bool p[10000007];
vector <int> V;
int n;

void eratos()
{
    for (int i = 2; i * i <= 10000000; ++i)
        if (!p[i])
            for (int j = i * i; j <= 10000000; j += i)
                p[j] = 1;

    for (int i = 2; i <= 10000000; ++i)
        if (!p[i]) V.push_back(i);
}

int main()
{
    freopen("SPIME.INP", "r", stdin);
    freopen("SPIME.OUT", "w", stdout);
    eratos();
    cin >> n;
    int r = 0, x = 0, y = 0, d = 1, len = 1;
    if (n == 2) cout << "0 0";
    else
    while (1)
    {
        if (d % 2 == 1)
        {
            for (int i = 1; i <= len; ++i)
            {
                ++x;
                ++r;
                if (V[r] == n)
                {
                    cout << x << " " << y;
                    return 0;
                }
            }

            for (int i = 1; i <= len; ++i)
            {
                ++y;
                ++r;
                if (V[r] == n)
                {
                    cout << x << " " << y;
                    return 0;
                }
            }
        }
        else
        {
            for (int i = 1; i <= len; ++i)
            {
                --x;
                ++r;
                if (V[r] == n)
                {
                    cout << x << " " << y;
                    return 0;
                }
            }

            for (int i = 1; i <= len; ++i)
            {
                --y;
                ++r;
                if (V[r] == n)
                {
                    cout << x << " " << y;
                    return 0;
                }
            }
        }
        ++d;
        ++len;
    }
    return 0;
}
