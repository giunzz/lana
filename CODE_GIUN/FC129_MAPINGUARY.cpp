#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;

ll n , k , c , d ;
vector<ll> card[maxn][5];
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ; 
    ll ans = 0 ;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> k;
        for (int j = 1 ; j <= k ; j++)
        {
            cin >> c >> d;
            card[i][c].push_back(d);
        }
    }
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ;  j <= 3 ; j++)
        {
            if (card[i][j].size() == 0) continue;
            cerr << j << ": ";
            for (int k : card[i][j]) cerr << k << " ";
            cerr << endl;
        }
        //cerr << endl;
    }
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ;  j <= 3 ; j++)
        {
            ll sz;
            if (j == 1) sz = 3;
            else sz = 1 ;
            sort (card[i][j].rbegin() , card[i][j].rend());
            while(card[i][j].size() > sz) card[i][j].pop_back();
        }
    }
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= 3 ; j++)
        {
            vector<pl> tmp;
            for (int k : card[i][j]) tmp.push_back({j , k});
        }
    }

}