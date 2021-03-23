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
    freopen("SC4.inp","r",stdin);
    freopen("SC4.out","w",stdout);
    cin >> t;
    while (t--)
    {
        ll quang = 0;
        stack<ll> q;
        map <int,int> d;
        cin >> n >> k >> c;
        for (int i = 1 ; i <= n ; i++) cin >> type[i] , test = max(test,type[i]) ;
        for (int i = 1 ; i <= n ; i++) cin >> cost[i] ;
        for (int i = 1 ; i <= n ; i++) a[i].tp = type[i] , a[i].cs = cost[i];
        if (test < k) cout << "FRIENDSHIP" << endl;
        else 
        {
            sort (a+1,a+1+n, cmp);
            q.push(a[1].cs) ;
            ll need = a[1].tp ;
            for (int i = 2 ; i <= n ; i++)
            {
                if (a[i].tp > k) break;

                if (need == a[i].tp)
                {
                    ll u = min (q.top(), a[i].cs ) ;
                    q.pop() , q.push(u);
                    
                }
                if (need != a[i].tp) q.push(a[i].cs) , need = a[i].tp ;
                d[i] = 1;
            }
            while (!q.empty())
            {
                quang += q.top() , q.pop() ;
            }
            if (quang == c) cout << "NOT FRIENDSHIP BUT NOT LOVE" << endl;
            if (quang > c) cout << "FRIENDSHIP" << endl;
            else if (quang < c) 
            {
                int bla = 0 ;
                for (int i = 1 ; i <= n ; i++)
                {
                    if (d[i] == 0 && quang + a[i].cs < c )
                    {
                        cout << "LOVE" << endl ;
                        bla = 1;
                        break;
                    }
                }
                if (bla == 0) cout << "NOT FRIENDSHIP BUT NOT LOVE" << endl;
            }
        }
    }
}