#include<bits/stdc++.h>
using namespace std;
#define NAME "ICECREAM"
const int maxn = 3e2 + 5;
const int mod = 1e9 + 9;
int MMAX,m50,m1,m2;
int c[maxn];
int ans;
int n;

void io()
{
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
}

void Input()
{
    cin >> n >> MMAX >> m50 >> m1 >> m2;
}

void Update()
{
    int M50 = m50;
    int M1 = m1;
    int M2 = m2;
    for(int i = 1; i <= n; ++i)
    {
        if(c[i] == 0)
        {
            M50++;
            if(M50 > MMAX) return;
        }
        else if(c[i] == 1)
        {
            M1++;
            M50--;
            if(M50 < 0 || M1 > MMAX) return;
        }
        else if(c[i] == 2)
        {
            M2++;
            if(M2 > MMAX) return;
            if(M50 >= 1 && M1 >= 1)
            {
                M50--;
                M1--;
            }
            else if(M50 >= 3) M50 -= 3;
            else return;
        }
    }
    ans = (ans + 1) % mod;
}

void BackTrack(int i)
{
    if(i > n) return;
    for(int j = 0; j <= 2; ++j)
    {
        c[i] = j;
        if(i < n) BackTrack(i + 1);
        if(i == n) Update();
    }
}

void Solve()
{
    BackTrack(1);
    cout << ans;
}

int main()
{
    io();
    Input();
    Solve();
}
