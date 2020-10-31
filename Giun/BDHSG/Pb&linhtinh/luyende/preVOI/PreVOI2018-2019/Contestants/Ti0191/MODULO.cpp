#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
typedef long long lli;
const lli maxCNT = 1048576 + 100;
const int maxN = 70;
int a[3], x[maxN];
lli n, k;
int idn1[maxCNT], idn2[maxCNT];
lli Nhann1, Nhann2;
int n1, n2;
int cntn1 = 0, cntn2 = 0;
lli X[maxCNT], Y[maxCNT];
string ansX[maxCNT], ansY[maxCNT];
lli Modul;
bool flag = false;

lli Power(lli x, lli y)
{
    if(y == 0) return 1;
    lli t = Power(x, y/2);
    if(y%2 == 0) return t*t;
    else return t*t*x;
}

lli PoweMod(lli x, lli y)
{
    if(y == 0) return 1%Modul;
    lli t = PoweMod(x, y/2);
    if(y%2 == 0) return t % Modul * t % Modul;
    else return t % Modul * t % Modul * x % Modul;
}

void Print()
{
    for(int j = 0; j < n; j++)
        cout << a[x[j]];
}

bool Check()
{
    lli res = 0;
    for(int j = 0; j < n; j++)
    {
        res = (res*10%Modul + a[x[j]]%Modul)%Modul;
        res %= Modul;
    }
    if(res == k)
    {
        Print();
        return true;
    }
    return false;
}

void Attemp(int i)
{
    if(!flag)
    {
        if(i == n)
        {
            if(Check())
                flag = true;
            return;
        }
        for(x[i] = 0; x[i] < 2; x[i]++)
            Attemp(i+1);
    }
}

void Make(int t)
{
    if(t == 1)
    {
        X[cntn1] = 0;
        ansX[cntn1] = "";
        idn1[cntn1] = cntn1;
        for(int j = 0; j < n1; j++)
        {
            X[cntn1] = (X[cntn1]%Modul*10%Modul + a[x[j]]%Modul)%Modul;
            ansX[cntn1] += (char)(a[x[j]]+'0');
        }
        cntn1++;
    }
    else
    {
        Y[cntn2] = 0;
        ansY[cntn2] = "";
        idn2[cntn2] = cntn2;
        for(int j = 0; j < n2; j++)
        {
            Y[cntn2] = (Y[cntn2]%Modul*10%Modul + a[x[j]]%Modul)%Modul;
            ansY[cntn2] += (char)(a[x[j]]+'0');
        }
        cntn2++;
    }
}

void Attemp1(int i)
{
    if(i == n1)
    {
        Make(1);
        return;
    }
    for(x[i] = 0; x[i] < 2; x[i]++)
        Attemp1(i+1);
}

void Attemp2(int i)
{
    if(i == n2)
    {
        Make(2);
        return;
    }
    for(x[i] = 0; x[i] < 2; x[i]++)
        Attemp2(i+1);
}

int Search2(lli t)
{
    int low = 0, high = cntn2-1;
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(Y[idn2[mid]] < t) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

int Search1(lli t)
{
    int low = 0, high = cntn1-1;
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(X[idn1[mid]] < t) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

void Solve()
{
    for(int i = 0; i < cntn1; i++)
    {
        lli q = Nhann1%Modul*X[idn1[i]]%Modul;
        if(q <= k)
            q = k - q;
        else
            q = Modul - q + k;
        lli p = Search2(q);
        lli calc = (X[idn1[i]]%Modul*Nhann1%Modul + Y[idn2[p]]%Modul) % Modul;
        if(calc == k)
        {
            flag = true;
            cout << ansX[idn1[i]] << ansY[idn2[p]];
            break;
        }
    }
    if(!flag)
        for(int i = 0; i < cntn2; i++)
        {
            lli q = Nhann2%Modul*Y[idn2[i]]%Modul;
            if(q <= k)
                q = k - q;
            else
                q = Modul - q + k;
            lli p = Search1(q);
            lli calc = (Y[idn2[i]]%Modul*Nhann2%Modul + X[idn1[p]]%Modul) % Modul;
            if(calc == k)
            {
                flag = true;
                cout << ansY[idn2[i]] << ansX[idn1[p]];
                break;
            }
        }
}

bool lf1(int i, int j)
{
    return X[i] < X[j];
}

bool lf2(int i, int j)
{
    return Y[i] < Y[j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("MODULO.INP", "r", stdin);
    freopen("MODULO.OUT", "w", stdout);
    cin >> a[0] >> a[1];
    cin >> n >> k;
    Modul = Power(2, n);
    if(n <= 20)
        Attemp(0);
    else
    {
        n1 = n/2;
        n2 = n-n1;
        Nhann1 = PoweMod(10, n2);
        Nhann2 = PoweMod(10, n1);
        Attemp1(0);
        sort(idn1, idn1 + cntn1, lf1);
        Attemp2(0);
        sort(idn2, idn2 + cntn2, lf2);
        Solve();
    }
    if(!flag)
        cout << "-1";
}
