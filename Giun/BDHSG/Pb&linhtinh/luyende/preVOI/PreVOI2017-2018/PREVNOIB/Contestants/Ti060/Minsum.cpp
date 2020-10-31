#include <bits/stdc++.h>

using namespace std;

const int maxt = 500+5;
const int maxn = 1e5+5;

int t, sp = 0;
int isPri[maxn], Pri[maxn], pt[maxn];
long long a, b, c;

void Prime(int x)
{
    isPri[1] = 1;
    for (int i=2; i<=sqrt(x); i++)
        if (isPri[i] == 0)
        {
            //sp++; Pri[sp] = i;
            int j = i * i;
            isPri[j] = 1;
            while (j <= x)
            {
                isPri[j] = 1;
                j += i;
            }
        }
    for (int i=1; i<=x; i++)
        if (isPri[i] == 0)
        {
            sp++;
            Pri[sp] = i;
        }
}

int main()
{
    freopen ("Minsum.inp", "r", stdin);
    freopen ("Minsum.out", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> t;
    Prime(maxn);
    while (t)
    {
        t--;
        cin >> a >> b;
        int i = 1;

        bool ok = false;
        while (a != 1 and i <= sp)
        {
            if (a % Pri[i] == 0)
            {
                pt[i]++;
                a = a / Pri[i];
                ok = true;
            }
            else i++;
        }
        i = 1;
        while (b != 1 and i <= sp)
        {
            if (b % Pri[i] == 0)
            {
                pt[i]++;
                b = b / Pri[i];
                ok = true;
            }
            else i++;
        }
        if (ok == false) cout << a << ' ' << b << '\n';
        else
        {
            c = 1;
            c = c * a * b;
            for (int i=1; i<=sp; i++)
                if (pt[i] % 2 == 1)
                {
                    c = c * Pri[i];
                    pt[i] = 0;
                }
            //cout << a << ' ' << b << ' ' << c << ' ';
            i = sqrt(c);
            while (c % i != 0)
                i--;
            cout << i << ' ' << c / i << '\n';
            //cout << a * (c / ans) << ' ' << b * ans;
        }
    }
}
