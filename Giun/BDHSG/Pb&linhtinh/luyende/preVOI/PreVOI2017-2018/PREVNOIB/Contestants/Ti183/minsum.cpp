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

int a, b;

void xli ()
{
    ll kq=100000000007, kq1=0, kq2=0;
    read(a); read(b);
    ll t=a*b; ll i, j, k, x;
    FOR(i, 1, t)
        if ((t%i)==0)
        {
            x=(ll)sqrt(t/i);
            if ((((t/i)%x)!=0) || (((t/i)/x)!=x)) continue;
            FOR(j, 1, i)
                if ((i%j)==0)
                {
                    k=i/j;
                    if ((j+k)<kq)
                    {
                        kq=j+k;
                        kq1=j; kq2=k;
                    }
                }
        }
    write(kq1); putchar(' '); writeln(kq2);
}

int main ()
{
    freopen("minsum.inp","r",stdin);
    freopen("minsum.out","w",stdout);
    int i, tv; read(tv);
    FOR(i, 1, tv) xli();
    return 0;
}
