#include <bits/stdc++.h>
#define fto(i,a,b) for (int i=a; i<=b; i++)
#define maxn 10005
#define base 1000000009
using namespace std;
int n, nmax, m50, m1, m2;
void nhap ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("icecream.inp", "r", stdin);
    freopen("icecream.out", "w", stdout);
    cin >> n >> nmax;
    cin >> m50 >> m1 >> m2;
}
long long res=0;
void calc (int i, int s1, int s2, int s3)
{
    if (i==n+1) {++res; return;}
    if (s1<nmax) calc(i+1, s1+1, s2, s3);
    if (s1 && s2<nmax) calc(i+1, s1-1, s2+1, s3);
    if (s1 && s2 && s3<nmax) calc (i+1, s1-1, s2-1, s3+1);
        else if (s1>=3 && s3<nmax) calc(i+1, s1-3, s2, s3+1);
}
void xuli1()
{
    calc(1, m50, m1, m2);
    cout << res << '\n';
}

int main()
{
    nhap();
    xuli1();
    return 0;
}
