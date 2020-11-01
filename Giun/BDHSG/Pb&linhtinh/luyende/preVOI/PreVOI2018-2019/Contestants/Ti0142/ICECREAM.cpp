#include <bits/stdc++.h>
#define Task "ICECREAM"
#define pii pair<int,int>
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
#define F first
#define S second
#define ll long long
#define MOD 1000000009

using namespace std;
const int maxn = 307;
int n, m, a,b,c, x[maxn], res;

void Calc()
{
    int a1 = a, b1 = b, c1 = c;
    for (int i = 1; i <= n; ++i)
    {
        if (x[i] == 1) a1++;
        else if (x[i] == 2)
        {
            if (a1 > 0) a1--, b1++;
            else return;
        }
        else
        {
            if (b1 > 0 && a1 > 0) c1++, b1--, a1--;
            else if (a1 >= 3) a1 -=3;
            else return;
        }
        if (a1 > m || b1 > m ||c1 > m) return;
    }
    res++;
}

void Try(int i)
{
    for (int j = 1; j <= 3; ++j)
    {
        x[i] = j;
        if (i == n) Calc(); else Try(i+1);
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(Task".inp","r",stdin);
	freopen(Task".out","w",stdout);
	cin >> n >> m >> a >> b >> c;
    Try(1); cout << res;
	return 0;
}
