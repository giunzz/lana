#include <bits/stdc++.h>
#define maxn 1000006
#define max1 1000000007
#define mp make_pair
#define F first
#define S second

using namespace std;
int q, nt[maxn], bp[3000006], dem, thang, dd[4999][4999];
pair<int,int> luu[maxn];
void check(int a, int b)
{
    thang = 0;
    int dc = __gcd(a, b);
    if (a == b) {cout << 1 << " " << 1 << endl; thang++; return;}
    if (bp[a] == 1 && bp[b] == 1) {cout << 1 << " " << 1 << endl; thang++; return;}
    if (nt[a] == 0 && nt[b] == 0) {cout << a << " " << b << endl; thang++; return;}
    if (nt[a] == 0 && bp[b] == 1) {luu[++dem] = mp(a,1); thang++; return;}
    if (nt[b] == 0 && bp[a] == 1) {luu[++dem] = mp(1,b); thang++; return;}
    if (nt[a / dc] == 0 && nt[b / dc] == 0) {luu[++dem] = mp(a/dc,b/dc); thang++; return;}
    dd[a][b] = 1;
    dd[b][a] = 1;
    for (int i = 2; i <= min(a, b); i++)
    {
        if (thang == 1) break;
        if (a % i == 0 && b % i == 0 && dd[a/i][b/i] != 1) check(a / i, b / i);
    }
    if (nt[a] != 0)
    {
        for (int i = 2; i <= a; i++)
        {
            if (thang == 1) break;
            if (a % i == 0 && dd[a/i][b*i] != 1) check(a / i, b * i);
        }
    }
    if (nt[b] != 0)
    {
        for (int i = 2; i <= b; i++)
        {
            if (thang == 1) break;
            if (b % i == 0 && dd[a*i][b/i] != 1) check(a * i, b / i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("minsum.inp","r",stdin);
    freopen("minsum.out","w",stdout);
    for (int i = 2; i <= 100; i++)
    {
        for (int j = i + i; j <= 100001; j += i)
            if (nt[j] == 0) nt[j] = 1;
    }
    for (int i = 1; i <= 1000; i++) bp[i*i] = 1;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        dem = 0;
        check(a, b);
        int dcm = max1;
        pair<int,int> save;
        for (int i = 1; i <= dem; i++)
            if (luu[i].F + luu[i].S < dcm && luu[i].F != 0 && luu[i].S != 0) save = luu[i], dcm = luu[i].F + luu[i].S;
        if (save.F != 0 && save.S != 0) cout << save.F << " " << save.S << endl;
        else {
            dem = 0;
            for (int i = 1; i <= 4999; i++)
                for (int j = 1; j <= 4999; j++) if (dd[i][j] == 1) luu[++dem] = mp(i,j);
            for (int i = 1; i <= dem; i++)
                if (luu[i].F + luu[i].S < dcm && luu[i].F != 0 && luu[i].S != 0) save = luu[i], dcm = luu[i].F + luu[i].S;
            if (save.F != 0 && save.S != 0) cout << save.F << " " << save.S << endl;
        }
    }
}
