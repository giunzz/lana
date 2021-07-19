#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 3e3 +  7;
using namespace std;
ll t  , n , k , sing , dance , s[maxn] , d[maxn];
pair <ll,ll> p[maxn];

// void quaylui (ll vt )
// {
//     if (vt == n + 1)         
//     {

//     }
//     else
//     {
//         for (int i = 0 ; i <= 1 ; i++)
//         {
//             c[vt] = i ;
//             quaylui(vt+1);
//         }
//     }
// }
int main()
{
    giuncute;
    freopen("giun.inp" ,"r",stdin);
    freopen("giun.out", "w" ,stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cin >> sing ;
        for (int i = 1 ; i <= sing ; i++) 
        {
            cin >> s[i];
            p[s[i]].first = 1;
        }
        cin >> dance;
        for (int i = 1 ; i <= dance; i++) 
        {
            cin >> d[i] ;
            p[s[i]].second = 1;
        }
        for (int i = 1 ; i <= n ; i++) 
            cerr << i << " " << p[s[i]].first << " " << p[s[i]].second << endl;
    //    quaylui(1);
    }

}
