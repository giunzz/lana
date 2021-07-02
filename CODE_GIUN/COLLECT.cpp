#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
#define pl pair <ll,ll>
const ll maxn = 1e6 + 7 ;
using namespace std;
ll k , X , Y , Z , L , M , N;
ll x , y , z , d , b , c , dd[10][10][10] = {0};
struct giun 
{
    int i , j, t , u , v , h;
};

vector<giun> a , ans;
queue <giun> dq;

void bfs ( )
{
    dq.push({X,Y,Z,0});
    dd[X][Y][Z] = 1;
    while (dq.size())
    {
        x = dq.front().i , y = dq.front().j , z = dq.front().t ;
        ll Time = dq.front().u;
        // cerr << x << " " << y << " " << z << endl;
        dq.pop();
        if (x >= L && y >= M && z >= N )
        {
            ans.push_back({x,y,z,Time}) ;
            continue;
        }
        if (Time == k) continue;
        for (giun o : a)
        {
            ll x1 = x - o.i + o.u , y2 = y - o.j + o.v , z1 = z - o.t + o.h;
            if (x >= o.i && x1 <= 4 && y >= o.j && y2 <= 4 && z >= o.t && z1 <= 4 && !dd[x1][y2][z1] )
            {
                dd[x1][y2][z1] = 1;
                dq.push({x1,y2,z1, Time + 1});
            }
        }
    }
}
bool cmp (giun &a1 , giun &a2)
{
    return (a1.i < a2.i) || (a1.i == a2.i && a1.j < a2.j) || (a1.i == a2.i && a1.j == a2.j && a1.t < a2.t );
}
int main()
{
    giuncute;
    freopen("COLLECT.inp","r",stdin);
    freopen("COLLECT.out","w",stdout);
    cin >> k;
    cin >> X >> Y >> Z >> L >> M >> N;
    while (cin >> x >> y >> z >> d >> b >> c ) a.push_back({x,y,z,d,b,c});
 //   for (giun i : a ) cerr << i.i << " " << i.j << " " << i.t << " " << i.u << " " << i.v << " " << i.h << endl;
    bfs();
    sort(ans.begin() , ans.end() , cmp);
    if (ans.size() == 0 ) cout << -1;
    else 
    {
        cout << ans.size() << endl;
        for (giun i : ans) cout << i.i << " " << i.j << " " << i.t << " " << i.u << endl;
    }
}