#include <bits/stdc++.h>

using namespace std;

void upfile()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("ARRANGE.INP","r",stdin);
    freopen("ARRANGE.OUT","w",stdout);
}

int n,a[100000],b[100000],kq;

long long k,ta,tb,du;

int main()
{
    upfile();
    cin >> n;
    for (int i=0; i<n; ++i)
    {
        cin >> a[i];
        ta += a[i];
    }
    k = ta / n;
    kq = 0;
    du = ta - k*n;
    for (int i=0; i<n; ++i)
    {
        if (a[i] > k && du > 0)
        {
            b[i] = k+1;
            --du;
        }
        else b[i] = k;
        tb += b[i];
    }
    //while (ta != tb)
    du = 0;
    for (int i=0; i<n; ++i)
    {
        a[i] += du;
        if (a[i] != b[i])
        {
            du = a[i]-b[i];
            kq += abs(du);
        }
    }
    cout << kq;
}



































































































//BAI TAP NAY CUA NGUYEN THAI DUONG
//CAM CHEP CODE DUOI MOI HINH THUC
//NGHIC NGU CHET TU CHIU
//XD
