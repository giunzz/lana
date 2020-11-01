#include <bits/stdc++.h>
#define maxc 1ll*1000000000000000007
#define PB push_back
#define mp make_pair
#define F first
#define S second
using namespace std;

int n, a, b, xx[100];
pair<long long, long long> res;
vector<int> all, duyet;
void ptich(int a, int b)
{
    map<int, int> dd;
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i) continue;
        if (dd[i] == 0) all.PB(i);
        while (a % i == 0)
        {
            a /= i;
            dd[i]++;
        }
    }
    if (a > 1)
    {
        if (dd[a] == 0) all.PB(a);
        dd[a]++;
    }
    for (int i = 2; i <= sqrt(b); i++)
    {
        if (b % i) continue;
        if (dd[i] == 0) all.PB(i);
        while (b % i == 0)
        {
            b /= i;
            dd[i]++;
        }
    }
    if (b > 1)
    {
        if (dd[b] == 0) all.PB(b);
        dd[b]++;
    }
    for (auto x : all)
    {
        if (dd[x] % 2 == 0) continue;
        duyet.PB(x);
    }
}

void tinh()
{
    long long x = 1, y = 1;
    for (int i = 0; i < duyet.size(); i++)
    {
        if (xx[i] == 1) x = x*duyet[i];
        else y = y*duyet[i];
    }
    if (x + y < res.F + res.S)
        res = mp(x, y);
}
void Try(int pos)
{
    if (pos >= n)
    {
        tinh();
        return;
    }
    Try(pos+1);
    xx[pos] = 1;
    Try(pos+1);
    xx[pos] = 0;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("MINSUM.INP", "r", stdin);
    freopen("MINSUM.OUT", "w", stdout);
    int Tests; cin >> Tests;
    while (Tests--)
    {
        all.clear(); duyet.clear();
        res = mp(maxc, maxc);
        cin >> a >> b;
        ptich(a, b);
        n = duyet.size();
        Try(0);
        cout <<res.F<<" "<<res.S<<endl;
    }
}
