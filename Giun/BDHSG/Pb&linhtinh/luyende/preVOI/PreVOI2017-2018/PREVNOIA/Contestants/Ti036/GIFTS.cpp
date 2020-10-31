#include <bits/stdc++.h>

using namespace std;

void upfile()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("GIFTS.INP","r",stdin);
    freopen("GIFTS.OUT","w",stdout);
}

int n,k,a[1000000],m,vt;

long long tong;

int main()
{
    upfile();
    cin >> n >> k;
    for (int i=0; i<n; ++i)
    {
        cin >> a[i];
    }
    tong = 0;
    for (int i=0; i<k; ++i)
    {
        tong += a[i];
    }
    m = tong;
    vt = 0;
    for (int i=k; i<n; ++i)
    {
        tong = tong +a[i] - a[i-k];
        if (tong > m)
        {
            m = tong;
            vt = i - k + 1;
        }
    }
    for (int i=vt; i<vt+k; ++i)
    {
        a[i] = 0;
    }
    tong = 0;
    for (int i=0; i<k; ++i)
    {
        tong += a[i];
    }
    m = tong;
    for (int i=k; i<n; ++i)
    {
        tong = tong +a[i] - a[i-k];
        if (tong > m)
        {
            m = tong;
        }
    }
    cout << m;
}















































































































//BAI TAP NAY CUA NGUYEN THAI DUONG
//CAM CHEP CODE DUOI MOI HINH THUC
//NGHIC NGU CHET TU CHIU
//XD
