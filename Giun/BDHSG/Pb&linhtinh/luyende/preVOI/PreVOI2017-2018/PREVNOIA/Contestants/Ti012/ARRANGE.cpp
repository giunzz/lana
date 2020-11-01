#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 100005
#define Task "ARRANGE"
using namespace std;
int n,a[maxn],temp,b[maxn];
long long sum,ans;
pair <int,pair <int,int> > d[maxn];
void xuli()
{
     FOR(i,1,n - 1)
        {
            ans += 1ll*abs(temp - a[i]);
            a[i+1] -= temp - a[i];
        }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    freopen(Task".inp", "r",stdin);
    freopen(Task".out", "w",stdout);
    cin >> n;
    FOR(i,1,n) cin >> a[i],sum += 1ll*a[i],b[i] = a[i];
    temp = sum / n;
    sum %= n;
    if (!sum)
    {
        xuli();
        return 0;
    }
    FOR(i,1,n - 1)
        {
            ans += 1ll*abs(temp - a[i]);
            a[i+1] -= temp - a[i];
        }
    if (sum == 1)
    {
        FOR(i,1,n)
            if (b[i] > temp)
            {
                ans -= n - i;
                break;
            }
        cout << ans;
        return 0;
    }
    int l = 1;
    while (sum && l <= n)
    {
        if (b[l] > temp)
        {
            --sum;
            ans -= n - l;
        }
        ++l;
    }
    cout << ans;
    return 0;
}
