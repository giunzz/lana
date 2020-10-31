#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

#define taskname "bubbletea"
#define pb push_back
#define mp make_pair
#define ins insert
#define era erase
#define fort(i,a,b) for(int i=(a); i<=(b); ++i)
#define forl(i,a,b) for(int i=(a); i>=(b); --i)
#define forc(i,c) for(__typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
#define forcn(i,c) for(__typeof(c.rbegin()) i=c.rbegin(); i!=c.rend(); ++i)
#define fir first
#define sec second

ifstream fi(taskname".inp");
ofstream fo(taskname".out");

const int maxn=5e4+5;
const int maxk=1e3+5;
int n, k;
vector<int> play;
vector<pair<int, long long> > ad[maxn];
long long l[maxn], cl[maxn];
int cnt=0;
long long d[maxk][maxk];
int x[maxn], mark[maxn];
long long res=1e18+5;

void enter()
{
    fi >> n >> k;
    int u, v, d;
    fort(i, 1, k)
    {
        fi >> v;
        play.pb(v);
    }
    fort(i, 1, n-1)
    {
        fi >> u >> v >> d;
        ad[u].pb(mp(v, d));
        ad[v].pb(mp(u, d));
    }
}

void Dijkstra(int id)
{
    int st=play[id];
    set<pair<long long, int> > s;
    ++cnt; cl[st]=1; l[st]=0; s.ins(mp(0, st));

    while (!s.empty())
    {
        int u=s.begin()->second; s.era(s.begin());
        forc(it, ad[u])
        {
            int v=it->fir; long long w=it->sec;
            if (cl[v]!=cnt)
            {
                cl[v]=cnt; l[v]=l[u]+w;
                s.ins(mp(l[v], v));
            } else if (l[v]>l[u]+w)
            {
                s.era(mp(l[v], v));
                l[v]=l[u]+w;
                s.ins(mp(l[v], v));
            }
        }
    }

    fort(i, 0, k-1) d[id][i]=l[play[i]];
}

void check()
{
    long long dis=0;
    fort(i, 1, k/2) dis=max(dis, d[x[i*2-1]][x[i*2]]);
    res=min(res, dis);
}

void back_track(int t)
{
    if (t>k)
    {
        check(); return;
    }
    fort(i, 0, k-1)
    if (mark[i]==0)
    {
        mark[i]=1; x[t]=i;
        back_track(t+1);
        mark[i]=0;
    }
}

void solve()
{
    fort(i, 0, k-1) Dijkstra(i);
    back_track(1);
    fo << res;
}

int main()
{
    enter();
    solve();
}
