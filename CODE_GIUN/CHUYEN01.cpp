#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define giuncute  ios_base::sync_with_stdio(0),cin.tie(0); cout.tie(0);
cll maxn = 2007;
using namespace std;
ll n , t , dd[maxn][maxn] ={0};
struct giun
{
    int u , v , w;
} g[maxn];

bool cmp (giun &x , giun &y)
{
    return (x.w < y.w);
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            cin >> t;
            if (t != 0  && dd[i][j] == 0) 
            { 
                dd[i][j] =  1 , dd[j][i] = 1;
                cerr << i <<" " <<  j << " " << t << endl;
                g[i].u = i , g[i].v = j , g[i].w = t;
                //g[j].push_back(make_pair(t,i));
            }
        }
    }
    sort(g+1,g+1+n,cmp);
    for (int i = 1; i <= n ;i++) 
    {
        cout << g[i].u << " " << g[i].v << " " << g[i].w << endl;
    }
}
