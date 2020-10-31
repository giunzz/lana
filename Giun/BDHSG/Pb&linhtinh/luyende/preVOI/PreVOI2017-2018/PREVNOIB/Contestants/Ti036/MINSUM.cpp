#include <bits/stdc++.h>

using namespace std;

void upfile()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("MINSUM.INP","r",stdin);
    freopen("MINSUM.OUT","w",stdout);
}

long long n,x,y,r,uoc[2000];

long long GCD(long long a,long long b)
{
    if (a>b) swap(a,b);
    long long m=a;
    long long n=b;
    long long t;
    while (n>0)
    {
        t=m%n;
        m=n;
        n=t;
    }
    return m;
}

bool nt(long long n)
{
    if (n<=1) return false;
    if (n==2) return true;
    if (n>2 && n%2==0) return false;
    if (n>2 && n%2==1)
    {
        long long i,s=1;
        for (i=3; i<=sqrt(n); i+=2)
            if (n%i==0)
            {
                s=0;
                break;
            }
        if (s==1) return true;
        else return false;
    }
}

void sol()
{
    cin >> x >> y;
    if (x == 0)
    {
        cout << "0 1\n";
        return;
    }

    if (y == 0)
    {
        cout << "1 0\n";
        return;
    }

    if (nt(x) == true && nt(y) == true)
    {
        cout << x << " " << y << "\n";
        return;
    }

    long long x2 = x;
    long long y2 = y;
    long long u = 2;
    int dem = 0;
    while (x2 > 1 || y2 > 1)
    {
        if (x2 % u == 0 || y2 % u == 0)
        {
            uoc[dem] = u;
            ++dem;
        }
        while (x2 % u == 0)
            x2 /= u;
        while (y2 % u == 0)
            y2 /= u;
        ++u;
        if (u>32000) break;
    }

    if (x2 > 1)
    {
        uoc[dem] = x2;
        ++dem;
    }

    if (y2 > 1)
    {
        uoc[dem] = y2;
        ++dem;
    }

    long long r = GCD(x,y);
    x /= r;
    y /= r;
    r = x*y;

    for (int i=0; i<dem; ++i)
    {
        while(r % (uoc[i]*uoc[i]) == 0)
        {
            r /= (uoc[i]*uoc[i]);
        }
    }

    for (int i=sqrt(r); i>0; --i)
    {
        if (r % i == 0)
        {
            long long kq1 = i;
            long long kq2 = r/i;
            long long uu = GCD(kq1,kq2);
            cout << kq1/uu << " " << kq2/uu << "\n";
            return;
        }
    }
}

int main()
{
    upfile();
    cin >> n;
    for (int t=0; t<n; ++t)
        sol();
}















































































































//BAI TAP NAY CUA NGUYEN THAI DUONG
//CAM CHEP CODE DUOI MOI HINH THUC
//NGHIC NGU CHET TU CHIU
//XD
