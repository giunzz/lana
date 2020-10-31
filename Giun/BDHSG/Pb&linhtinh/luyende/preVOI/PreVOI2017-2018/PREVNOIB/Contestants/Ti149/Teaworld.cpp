#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define llint long long

using namespace std;

struct circle
{
    int x, y, z;
    double r;
    circle(){};
    circle(int x, int y, int z,double r):x(x), y(y), z(z), r(r){};
};

typedef pair< double, double > dd;
typedef pair< dd, int >     di;
int m, n, k, x, y, z;
circle C[2000 + 10], s[20];
vector< di > line[555 * 2];
vector< int > stay;

void cut(int x, circle a,int id)
{
    if (a.x + a.r < x || a.x - a.r > x) return;
    double diff = sqrt(a.r * a.r - (a.x - x) * (a.x - x));
    line[x + 500].push_back(di(dd(a.y - diff, a.y + diff), id));
}
bool in(int x, int y, circle c)
{
    double dist = (c.x - x) * (c.x - x) + (c.y - y) * (c.y - y);
    return (dist <= c.r * c.r);
}
void prepare()
{
    for(int i = 1; i <= m; i++)
        for(int x = -500; x <= 500; x++) cut(x, C[i], i);
    for(int x = -500; x <= 500; x++) sort(line[x + 500].begin(), line[x+ 500].end());
}

queue< int > q; bool visited[2000 + 10];
void add(int id){
    //cerr<<">> " << id <<'\n';
    if (!visited[id]){
        visited[id] = 1;
        q.push(id);
    }
}
void go(int x,int y, circle a)
{
    if (x > a.x){swap(a.x, x);swap(a.y, y);}
    double dif, yy = y;
    if (a.x != x)
        dif = (double)(a.y - y)/(a.x - x); else dif = 0;
    for(int i = x; i <= a.x; i++){

        for(int j = 0; j < line[i + 500].size(); j++){
            //cerr<< line[i+ 500][j].first.first <<' '<< line[i + 500][j].first.second <<'\n';
            if (line[i + 500][j].first.first <= yy && yy <= line[i+ 500][j].first.second){
                add(line[i+ 500][j].second);
            }
            if (line[i + 500][j].first.first > yy) break;
        }
        yy+= dif;
    }
    if (a.x == x)
        for(int j = 0; j < line[x + 500].size(); j++) add(line[x + 500][j].second);
   /// for(int i = 0; i < stay.size();i++) if (visited[i] == 0)
}

int num(int state)
{
    int ans = 0;
    for(int i = 0; i < n; i++)
        if (state & (1 << i))go(x, y, s[i + 1]);
    ans = q.size();
    for(int i = 0; i < stay.size(); i++){
        bool Ok = visited[stay[i]];
        for(int j = 0; j < n; j++)
            if (state & (1 << j)) if (!in(s[j + 1].x, s[j + 1].y, C[stay[i]])) Ok = 0;
        if (Ok) ans--;//, cerr<< ">> " << stay[i] <<'\n';
    }
    while(!q.empty())  visited[q.front()] = 0, q.pop();
    return ans;
}
void Solve_2D()
{
    int ans = 0;
    for(int i = 0; i < (1<<n); i++){
        int sum = 0;
        for(int j = 0; j < n; j++)
            if (i & (1<<j)) sum+= s[j + 1].r;
        if (sum <= ans) continue;
        int x =  num(i);
        //cout<< i <<' '<< x <<' '<< sum <<'\n';
        if (x <= k) ans = max(ans, sum);
    }
    cout<< ans <<'\n';
}
void Read()
{
    cin>> m >> n >> k;
    int x, y, z, r;
    for(int i = 1; i <= m; i++){
        cin>> x >> y >> z >> r;
        C[i] = circle(x, y, z, r);
    }
    for(int i = 1; i <= n; i++){
        cin>> x >> y >> z >> r;
        s[i] = circle(x, y, z, r);
    }
    cin>> x >> y >> z;
    for(int i = 1; i <= m; i++)
        if (in(x, y, C[i])) stay.push_back(i);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("Teaworld.inp","r",stdin);
    freopen("Teaworld.out","w",stdout);
    Read();
    prepare();
    Solve_2D();
    //cout<< num(23) <<'\n';
    return 0;
}
