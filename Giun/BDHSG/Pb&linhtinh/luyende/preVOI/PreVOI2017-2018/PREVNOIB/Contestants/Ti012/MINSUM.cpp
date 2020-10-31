#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 200
#define Task "MINSUM"
using namespace std;
int t,x,y,cnt,save[maxn];
vector <long long> a,b;
long long temp,h;
pair <long long,int> ans;
void process(int &x,int &y)
{
    FOR(i,2,sqrt(x))
    {
        bool dd = 0;
        while (x % i == 0)
        {
            x /= i;
            dd ^= 1;
        }
        while (y % i == 0)
        {
            y /= i;
            dd ^= 1;
        }
        if (dd) save[++cnt] = i;
    }
    if (x != 1) save[++cnt] = x, x = 1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    freopen(Task".inp", "r",stdin);
    freopen(Task".out", "w",stdout);
    cin >> t;
    while (t--)
    {
        ans.F = 10ll*maxc;
        cin >> x >> y;
        a.clear();
        b.clear();
        cnt = 0;
        temp = __gcd(x,y);
        x /= temp;
        y /= temp;
        if (x == 1 && y == 1)
        {
            cout << "1 1\n";
            continue;
        }
        process(x,y);
        process(y,x);
        if (!cnt)
        {
            cout << "1 1\n";
            continue;
        }
        if (cnt == 1)
        {
            cout << 1 << ' ' << save[1] << '\n';
            continue;
        }
        if (cnt == 2)
        {
            cout << save[1] << ' ' << save[2] << '\n';
            continue;
        }
        temp = 1;
        FOR(i,1,cnt) temp = 1ll*temp*save[i];
        h = sqrt(temp);
        FOR(i,1,cnt/2)
        {
            int qwe = a.size();
            FOR(j,0,qwe-1)
                a.pb(1ll*a[j]*save[i]);
            a.pb(save[i]);
        }
        FOR(i,cnt/2+1,cnt)
        {
            int qwe = b.size();
            FOR(j,0,qwe-1)
                b.pb(1ll*b[j]*save[i]);
            b.pb(save[i]);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for (long long v : a)
        {
            int qwe = lower_bound(b.begin(),b.end(),1ll*h/v) - b.begin();
            if (qwe && b[qwe] > h/v) --qwe;
            int TLE = 1ll*b[qwe]*v;
            if (ans.F > TLE + temp / TLE)
                ans = mp(TLE + temp / TLE,TLE);
        }
        cout << ans.S << ' ' << temp / ans.S << '\n';
    }
    return 0;
}
