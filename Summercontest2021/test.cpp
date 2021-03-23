#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define giuncute  ios_base::sync_with_stdio(0),cin.tie(0); cout.tie(0);
cll maxn = 100007;
using namespace std;
ll n , k , c, type[maxn] , cost[maxn] , t , l[maxn][55] , test = 0 ;
struct giun
{
    ll tp , cs;
} a[maxn];
bool cmp (giun &x , giun &y)
{
    return (x.tp < y.tp);
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> t;
    while (t--)
    {
        ll quang = 0;
        queue<int> q;
        map <int,int> d;
        cin >> n >> k >> c;
        for (int i = 1 ; i <= n ; i++) cin >> type[i] , test = max(test,type[i]) ;
        for (int i = 1 ; i <= n ; i++)
        {
            cin >> cost[i] ;
            if ()
        for (int i = 1 ; i <= n ; i++) a[i].tp = type[i] , a[i].cs = cost[i];
        if (test < k) cout << "FRIENDSHIP" << endl;
        else 
        {
            for (int i = 1 ; i <= n ; i++)
            {}

        }
    }
}