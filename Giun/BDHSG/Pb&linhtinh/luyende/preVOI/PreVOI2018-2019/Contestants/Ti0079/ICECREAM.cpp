#include <bits/stdc++.h>
using namespace std;
long long cd,mmax,m50,m1,m2,d[20][31][31][31],ok[20][31][31][31];
long long result[51][70][70][70];
long long mod = 1e9+9;
void inp()
{
    cin >> cd >> mmax;
    cin >> m50 >> m1 >> m2;
}
void sub1()
{
    ok[0][m50][m1][m2] = 1;
    d[0][m50][m1][m2] = 1;
    for (long long i = 0 ; i < cd ; i++)
    {
        for (long long e = 0 ; e <= mmax ; e++)
        for (long long f = 0 ; f <= mmax ; f++)
        for (long long g = 0 ; g <= mmax ; g++)
        {
            if (ok[i][e][f][g] == 1)
            {
                ok[i+1][e+1][f][g] = 1;
                d[i+1][e+1][f][g] += d[i][e][f][g];
                if (e != 0)
                {
                    ok[i+1][e-1][f+1][g] = 1;
                    d[i+1][e-1][f+1][g] += d[i][e][f][g];
                    d[i+1][e-1][f+1][g] %= mod;
                }
                if (f != 0 && e != 0)
                {
                    ok[i+1][e-1][f-1][g+1] = 1;
                    d[i+1][e-1][f-1][g+1] += d[i][e][f][g];
                    d[i+1][e-1][f-1][g+1] %= mod;
                }
                if (f == 0 && e >= 3)
                {
                    ok[i+1][e-3][f][g+1] = 1;
                    d[i+1][e-3][f][g+1] += d[i][e][f][g];
                    d[i+1][e-3][f][g+1] %= mod;
                }
            }
        }
    }
    long long kq = 0;
        for (long long e = 0 ; e <= mmax ; e++)
        for (long long f = 0 ; f <= mmax ; f++)
        for (long long g = 0 ; g <= mmax ; g++)
            kq += d[cd][e][f][g] , kq %= mod;
        cout <<kq;
}
bool check(long long i , long long e , long long f , long long f1 , long long ok)
{
    long long g = i - e - f;
    long long g1 = f - f1;
    if (g < 0 || g1 < 0) return false;
    long long fifty = m50 + e - (f-f1) - 3*(g-g1) - f;
    long long one = m1 + f1;
    long long two = m2 + g;
    if (g > mmax || f < f1 || f1 < 0 || f < 0 || e < 0) return false;
    if (one > mmax || one < 0 || two > mmax || two < 0 ) return false;
    if (fifty < 0 || fifty > mmax) return false;
    if (ok == 1 && fifty < 1) return false;
    if (ok == 2 && (fifty < 3 || f1 != 0)) return false;
    if (ok == 3 && fifty < 1) return false;
    return true;
}
void sub2()
{
    long long kq = 0;
    result[0][0][0][0] = 1;
    for (long long i = 1 ; i <= cd ; i++)
    {
        for (long long e = 0 ; e <= i ; e++)
        for (long long f = 0 ; f <= i - e ; f++)
        for (long long f1 = 0 ; f1 <= f ; f1++)
        {
            // th f = 0 --> thoi 3 cai;
            if (check(i , e , f , f1,0))
            {
               // cout <<"yes "<<i<<" "<<e<<" "<<f<<" "<<f1<<endl;
                if (check(i - 1 , e - 1 , f , f1,0)) result[i][e][f][f1] += result[i-1][e-1][f][f1];
           //     if (check(i-1 , e , f-1,f1)) result[i][e][f][f1] += result[i-1][e][f-1][f1];
                if (check(i-1 , e , f-1 , f1-1,1)) result[i][e][f][f1] += result[i-1][e][f-1][f1-1];
                if (check(i-1,e,f,f1,2)) result[i][e][f][f1] += result[i-1][e][f][f1];
                if (f1 < mmax) if (check(i-1 , e , f , f1+1,3)) result[i][e][f][f1] += result[i-1][e][f][f1+1];
                result[i][e][f][f1] %= mod;
             //   cout <<result[i][e][f][f1]<<endl;
                if (i == cd) kq += result[i][e][f][f1];
                kq %= mod;
            }
        }
    }
    cout << kq;
}
main()
{
    freopen("ICECREAM.INP","r",stdin);
    freopen("ICECREAM.OUT","w",stdout);
    inp();
    if (cd <= 15) sub1();
    else
    sub2();
}
