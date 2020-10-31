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

#define nmax 1000005

deque<int> truoc;
deque<int> sau;
ll a[nmax];
ll cd[nmax];
ll tg[nmax];
ll kq=100000000000007;
int n, k;

int main ()
{
    freopen("gifts.inp","r",stdin);
    freopen("gifts.out","w",stdout);
    read(n); read(k);
    int i;
    FOR(i, 1, n)
    {
        read(a[i]); cd[i]=cd[i-1]+a[i];
    }
    FOR(i, 1, n-k+1) tg[i]=cd[i+k-1]-cd[i-1];
    FOR(i, k+1, n-k+1)
    {
        while ((!sau.empty()) && (tg[sau.back()]<tg[i])) sau.pop_back();
        sau.push_back(i);
    }
    int j; ll tmp;
    FOR(i, 1, n-k+1)
    {
        tmp=0;
        while ((!sau.empty()) && (sau.front()<=(i+k-1))) sau.pop_front();
        if (!truoc.empty()) tmp=max(tmp, tg[truoc.front()]);
        if (!sau.empty()) tmp=max(tmp, tg[sau.front()]);
        kq=min(kq, tmp);
        if (i>=k)
        {
            j=i-k+1;
            while ((!truoc.empty()) && (tg[truoc.back()]<tg[j])) truoc.pop_back();
            truoc.push_back(j);
        }
    }
    writeln(kq);
    return 0;
}
