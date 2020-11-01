#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
long long a,b,n,k,res;
long long mu (int n)
{
    long long res =1;
    for (int i=0 ; i<n ; i++ )
    {
        res *=2;
    }
    return res;
}
bool ck (long long n)
{
    int t = n;
    while (t > 0 )
    {
        if (t % 10 != a && t % 10 != b)
        {
            return false ;
        }
        t =t / 10 ;
    }
    return true;
}
void solve ()
{
    long long two  =mu (n);
    long long limit = 10e14 ;
    int j = 0 ;
    if (k % 2==0 && a % 2 == 1 && b % 2 == 1)
    {
        res =-1;
        return ;
    }
    if (k % 2 ==1 && a % 2 ==0 && b % 2 ==0 )
    {
        res = -1 ;
        return ;
    }
    while (two*j+k < limit )
    {
        if (ck (two*j+k))
        {
            res = two*j + k;
            return ;
        }
        j++;
    }

}

int main()
{
    res =-1;
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    cin >>a>>b;
    cin >>n>>k ;
    solve();
    cout << res ;
    return 0;
}
