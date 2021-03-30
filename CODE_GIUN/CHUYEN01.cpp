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
    freopen("chuyen01.inp","r",stdin);
    freopen("chuyen01.out","w",stdout);
    cin >> n ;
    int dem = 1;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            cin >> t;
            if (t != 0  && dd[i][j] == 0) 
            { 
                dd[i][j] =  1 , dd[j][i] = 1;
               // cerr << i <<" " <<  j << " " << t << endl;
                g[dem].u = i , g[dem].v = j , g[dem].w = t;
                //g[j].push_back(make_pair(t,i));
            dem++;
            }
        }
    }
    dem--;
    sort(g+1,g+1+dem,cmp);
    for (int i = 1; i <= dem ;i++) 
    {
        cout << g[i].u << " " << g[i].v << " " << g[i].w << endl;
    }
}