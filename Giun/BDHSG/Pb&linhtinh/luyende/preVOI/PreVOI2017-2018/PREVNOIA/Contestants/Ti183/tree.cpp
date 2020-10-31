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

#define nmax 5005

vector<int> e[nmax];
bool cx[nmax];
bool la[nmax];
ll a[nmax];
ll f[nmax];
int np[nmax];
int p[nmax];
int tp[nmax];
ll gt[nmax];
int n, k=0, dm=0;
ll kq=1000000000007;

void dfs (int u)
{
    cx[u]=false; int i, v;
    FORK(i, 0, e[u].size())
    {
        v=e[u][i];
        if (cx[v])
        {
            la[u]=false;
            p[v]=u; dfs(v);
        }
    }
    dm++; tp[dm]=u;
}

void ktra ()
{
    int i, j, c=0;
    int u, v;
    FOR(i, 1, n)
    {
        u=tp[i]; gt[u]=0; f[u]=0;
        if (la[u])
        {
            c++; f[u]=abs(a[u]-np[c]);
            gt[u]=np[c];
        }
        else
        {
            FORK(j, 0, e[u].size())
            {
                v=e[u][j];
                if (v!=p[u])
                {
                    gt[u]+=gt[v];
                    f[u]+=f[v];
                }
            }
            f[u]+=abs(a[u]-gt[u]);
        }
    }
    kq=min(f[1], kq);
}

void nphan (int i)
{
    int j;
    FOR(j, 0, 1)
    {
        np[i]=j;
        if (i==k) ktra();
        else nphan(i+1);
    }
}

int main ()
{
    freopen("tree.inp","r",stdin);
    freopen("tree.out","w",stdout);
    read(n);
    int i;
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, n) cx[i]=true;
    int u, v;
    FOR(i, 1, n-1)
    {
        read(u); read(v);
        e[u].pb(v); e[v].pb(u);
    }
    FOR(i, 1, n) la[i]=true;
    dfs(1);
    FOR(i, 1, n)
        if (la[i]) k++;
    nphan(1);
    writeln(kq);
    return 0;
}
