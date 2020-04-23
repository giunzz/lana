#include <bits/stdc++.h>

using namespace std;

ifstream f ("TREELINE.INP");
ofstream g ("TREELINE.OUT");

float a[100000000], dau, Maxx = -1, n;
float k;
void nhap()
{
    a[0]=0;
    f >> n >> k;
    for (long i=1; i<=n;i++)
    {
        long x;
        f >> x;
        a[i] = a[i-1] + x;
    }
}
bool xuly()
{
    long i=1,j=n;
    if (((a[j] - a[i-1])/(j-i+1)) < k) return false;
    while (i<=j)
    {
        if (((a[j] - a[i-1])/(j-i+1)) == k && ((j-i+1) > Maxx))
        {
            dau = i;
            Maxx = j-i+1;
            return true;
            break;
        }
        else if (((a[j] - a[i-1])/(j-i+1)) > k) j--;
        else if (((a[j] - a[i-1])/(j-i+1)) < k) i++;
    }
    return false;
}
int main()
{
    nhap();
    if (xuly()==true) g << Maxx << " " << dau;
    else g << 0;
    f.close();
    g.close();
    return 0;
}
