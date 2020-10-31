#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn=1e5+10;
int n, a[maxn];
ull sum = 0;
int read_int()
{
    int kq = 0, sign = 1;
    char c = getchar();
    while (c <'0' || c >'9')
    {
        if (c == '-')
            sign = -1;
        c = getchar();
    }
    while (c>='0' && c <='9')
        kq = kq*10+c-'0', c= getchar();
    return kq*sign;
}

void sub1()
{
    int avg = sum/n;
    if (sum % n !=0)
        avg++;
    int c = 0, r = 0;
        for (int i = 1; i<=n; i++)
        {
            /*if (a[i] < sum/n)
                c+=abs(r);
            else if(a[i] > sum/n)*/
            c+=abs(r);
            if (sum % n !=0)
            {
                int val = (avg-a[i])/2*2;
                //if (avg < a[i])
                //    val = (avg-a[i]+1)/2*2;
                r+=val;
                //cout << i << " " << val << endl;
            }
            else
                r += avg-a[i];
            //cout << r << endl;
        }

        cout << c << endl;
}

void sub2()
{
    int avg = sum/n;

}

int main()
{
    freopen("ARRANGE.INP",  "r", stdin);
    freopen("ARRANGE.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    n = read_int();
    for (int i = 1; i<=n; i++)
        a[i] = read_int(), sum+= a[i];
    if (sum % n == 0)
    {
        sub1();
    }
    else
    {
        sub1();
    }
    return 0;
}
