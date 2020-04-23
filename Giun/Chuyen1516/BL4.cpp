#include <bits/stdc++.h>

using namespace std;

double dientich(int x, int y, int z, float p)
{
    double dt;
    dt = p * (p - x) * (p - y) * (p - z);
    dt = sqrt(dt);
    return dt;
}

bool kttgv(int x, int y, int z)
{
    int bpch, bpcg;
    bpch = z*z;
    bpcg = x*x + y*y;
    return (bpch == bpcg)? true : false;
}

int main()
{
    freopen("BL4.INP", "r", stdin);
    freopen("BL4.OUT", "w", stdout);
    int n, canh1, canh2, canh3, check = 0;
    double maxdt = 0;
    cin >> n;
    if (n == 1 || n == 2 || n == 4)
    {
        cout << "KHONG\n";
        cout << "KHONG\n";
        cout << "0";
    }
    else
    {
        canh1 = round(n/3);
        for (int x = 1; x <= canh1; x++)
        {
            canh2 = round((n - x)/2);
            canh3 = n - canh2 - x;
            while ((canh3 - canh2 < x) && (x <= canh2))
            {
                if ((check == 0) && (kttgv(x, canh2, canh3 == 1))) check = 1; //Kiểm tra tam giác vuông
                maxdt = max(maxdt, dientich(x, canh2, canh3, n/(float)2));
                cout << "(" << x << "; " << canh2 << "; " << canh3 << ")" << " ";
                canh2 -= 1;
                canh3 += 1;
            }
        }
        if (check == 1) cout << "\nCO";
        else cout << "\nKHONG";
        cout << endl << setprecision(3) << maxdt;
    }
    return 0;
}
