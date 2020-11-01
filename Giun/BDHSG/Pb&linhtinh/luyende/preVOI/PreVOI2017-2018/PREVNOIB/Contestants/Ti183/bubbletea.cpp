#include <bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(i=j;i<=k;i++)
#define FORK(i,j,k) for(i=j;i<k;i++)
#define FORN(i,j,k) for(i=j;i>=k;i--)
#define pb push_back
#define mp make_pair
#define ll long long

typedef pair<int,int> ii;

template <typename T> inline void read(T &x)
{
	char c; bool nega=false;
	while ((!isdigit(c=getchar())) && (c!='-'));
	if (c=='-')
	{
		nega=true; c=getchar();
	}
	x=c-48;
	while (isdigit(c=getchar())) x=x*10+c-48;
	if (nega) x=-x;
}

template <typename T> inline void writep(T x)
{
	if (x>9) writep(x/10);
	putchar(x%10+48);
}

template <typename T> inline void write(T x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	writep(x);
}

template <typename T> inline void writeln(T x)
{
	write(x);
	putchar('\n');
}

//___________________________________________________

#define nmax 50005
#define dmax 100000000000000007

priority_queue<ii, vector<ii>, greater<ii> > pq;
vector<ii> e[nmax];
ll d[nmax];
int hv[15];
ll kc[15][15];
int a[nmax];
int p[nmax];
int t[nmax];
int tp[nmax];
bool cx[nmax];
int n, k, dm;
ll kq=dmax;

bool relax (int u, int v, int w)
{
    if ((d[u]+w)<d[v])
    {
        d[v]=d[u]+w;
        return true;
    }
    else return false;
}

void dijkstra (int x)
{
    while (!pq.empty()) pq.pop();
    int i;
    FOR(i, 1, n) d[i]=dmax;
    d[x]=0; pq.push(mp(0, x));
    ll dd; int u, v, w;
    while (!pq.empty())
    {
        dd=pq.top().first; u=pq.top().second;
        pq.pop();
        if (dd!=d[u]) continue;
        FORK(i, 0, e[u].size())
        {
            v=e[u][i].first; w=e[u][i].second;
            if (relax(u, v, w)) pq.push(mp(d[v], v));
        }
    }
}

void ktra ()
{
    int i; ll tmp=0;
    FOR(i, 1, k)
        if (i%2) tmp=max(tmp, kc[hv[i]][hv[i+1]]);
    kq=min(kq, tmp);
}

void hvi (int i)
{
    int j;
    FOR(j, 1, k)
    {
        if (cx[j])
        {
            hv[i]=j; cx[j]=false;
            if (i==k) ktra();
            else hvi(i+1);
            cx[j]=true;
        }
    }
}

void sub1 ()
{
    int i, j;
    FOR(i, 1, k)
    {
        dijkstra(a[i]);
        FOR(j, i+1, n)
        {
            kc[i][j]=d[a[j]];
            kc[j][i]=kc[i][j];
        }
    }
    FOR(i, 1, k) cx[i]=true;
    hvi(1);
    if (kq==dmax) writeln(-1);
    else writeln(kq);
}

void dfs (int u)
{
    cx[u]=false; int i, v;
    FORK(i, 0, e[u].size())
    {
        v=e[u][i].first;
        if (cx[v])
        {
            p[v]=u; dfs(v);
        }
    }
    dm++; tp[dm]=u;
}

void sub2 ()
{
    int i, j, c, u, v;
    FOR(i, 1, n) cx[i]=true;
    dm=0; dfs(1); kq=0;
    FOR(i, 1, n) cx[i]=true;
    FOR(i, 1, n)
    {
        c=0; u=tp[i];
        FORK(j, 0, e[u].size())
        {
            v=e[u][j].first;
            if ((v!=p[u]) && (cx[v]))
            {
                cx[v]=false;
                c++; t[c]=e[u][j].second;
            }
        }
        sort(t+1,t+c+1);
        if (c%2)
        {
            kq=max(kq, (ll)t[c]); c--;
            cx[u]=false;
        }
        FOR(j, 1, c/2) kq=max(kq, (ll)t[j]+t[c-j+1]);
    }
    writeln(kq);
}

int main ()
{
    freopen("bubbletea.inp","r",stdin);
    freopen("bubbletea.out","w",stdout);
    read(n); read(k);
    int i, u, v, w;
    FOR(i, 1, k) read(a[i]);
    FOR(i, 1, n-1)
    {
        read(u); read(v); read(w);
        e[u].pb(mp(v, w)); e[v].pb(mp(u, w));
    }
    if (i<=10) sub1();
    else sub2();
    return 0;
}
