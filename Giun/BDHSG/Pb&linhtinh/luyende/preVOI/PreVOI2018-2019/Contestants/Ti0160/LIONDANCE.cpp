#include<bits/stdc++.h>

using namespace std;
#define brokenheart "LIONDANCE"
#define pb	push_back
typedef long double ld;
typedef long long ll;
const int maxn = 4e3 + 5;

int n , delta;

int a[maxn] , b[maxn];
unordered_map<int,vector<int>> mmap;

void input()
{
    cin >> n >> delta;
    for(int i = 1 ; i <= n ; ++i)cin >> a[n - i + 1];
    for(int i = n ; i >= 1 ; --i){
        cin >> b[i];
        mmap[b[i]].pb(i);
    }
    for(auto & c : mmap){
        reverse(c.second.begin(),c.second.end());
    }
}

struct TNode
{
    int val , i , j;
}f[maxn][maxn];

void solve()
{
    int resi = 0 , resj = 0;
    for(int i = 1 ; i <= n ; ++i)
    {
        for(int j = 1 ; j <= n ; ++j)
        {
            if(a[i] == b[j])
            {
                f[i][j].val = 1;
                for(int t = 1 ; t < i ; ++t)
                {
                    if(abs(a[i] - a[t]) <= delta)
                    {
                        auto & c = mmap[a[t]];
                        auto it = upper_bound(c.begin(),c.end(),j,greater<int>());
                        if(it == c.end())continue;
                        int g = *it;
                        if(f[i][j].val < f[t][g].val + 1)
                        {
                            f[i][j].val = f[t][g].val + 1;
                            f[i][j].i = t;
                            f[i][j].j = g;
                        }
                        else if(f[i][j].val == f[t][g].val + 1 && a[f[i][j].i] < a[t])
                            f[i][j].i = t , f[i][j].j = g;
                    }
                }
                if(f[resi][resj].val < f[i][j].val)
                    resi = i , resj = i;
                else if(f[resi][resj].val == f[i][j].val && a[resi] < a[i])
                    resi = i , resj = j;
            }
        }
    }
    cout << f[resi][resj].val << '\n';
    while(resi != 0 && resj != 0)
    {
        cout << a[resi] << " ";
        auto k = f[resi][resj];
        resi = k.i;resj = k.j;
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if(fopen(brokenheart".INP","r"))
        freopen(brokenheart".INP", "r",stdin) ,
        freopen(brokenheart".OUT", "w",stdout);
    input();
    solve();
}
