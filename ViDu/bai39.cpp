#include<bits/stdc++.h>

using namespace std;

long long n ;

long long tich(long long a)
{
    long long t = 1;
    while (a > 0)
    {
        t = t * (a % 10);
        a = a / 10;
    }
    return t;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("bai39.inp","r",stdin);
    freopen("bai39.out","w",stdout);
    //freopen("input.inp","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n ;
    while ( n > 10)
    {
        n = tich(n);
    }
    cout << n;
    return 0;
}