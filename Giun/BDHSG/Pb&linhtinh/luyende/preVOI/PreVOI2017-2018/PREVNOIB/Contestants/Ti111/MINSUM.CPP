#define Link ""

#include <iostream>
#include <cstdio>
#include <vector>

#define TASK "MINSUM"

using namespace std;

void OpenFile()
{
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
}

int a,b;
vector <pair<int,int> > mem[3];
vector <int> s;
long long resx,resy;

void Enter()
{
    cin >> a >> b;
}

void Div(int n, int t)
{
    mem[t].clear();
    for (int i=2;i*i<=n;++i)
        if (n % i == 0) {
            mem[t].push_back({i,0});
            while (n % i == 0) {
                ++mem[t].back().second;
                n /= i;
            }
        }
    if (n > 1)
        mem[t].push_back({n,1});
}

void Init()
{
    Div(a,1);
    Div(b,2);
    s.clear();
}

void UpdateRes(long long x, long long y)
{
    if (x + y < resx + resy) {
        resx = x;
        resy = y;
    }
}

void BT(int i, long long x, long long y)
{
    if (i == s.size())
        UpdateRes(x,y);
    else {
        BT(i+1,x*s[i],y);
        BT(i+1,x,y*s[i]);
    }
}

void Solve()
{
    int i,j;
    i = j = 0;
    while (i < mem[1].size() || j < mem[2].size())
        if (i < mem[1].size() && j < mem[2].size())
            if (mem[1][i].first == mem[2][j].first) {
                if ((mem[1][i].second - mem[2][j].second) % 2)
                    s.push_back(mem[1][i].first);
                ++i;
                ++j;
            }
            else
                if (mem[1][i].first < mem[2][j].first) {
                    if (mem[1][i].second % 2)
                        s.push_back(mem[1][i].first);
                    ++i;
                }
                else {
                    if (mem[2][j].second % 2)
                        s.push_back(mem[2][j].first);
                    ++j;
                }
        else
            if (i < mem[1].size()) {
                if (mem[1][i].second % 2)
                    s.push_back(mem[1][i].first);
                ++i;
            }
            else {
                if (mem[2][j].second % 2)
                    s.push_back(mem[2][j].first);
                ++j;
            }
    resx = resy = 1e18;
    BT(0,1,1);
    cout << resx << ' ' << resy << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    OpenFile();

    int T;
    for (cin>>T;T>0;--T) {
        Enter();
        Init();
        Solve();
    }
}
