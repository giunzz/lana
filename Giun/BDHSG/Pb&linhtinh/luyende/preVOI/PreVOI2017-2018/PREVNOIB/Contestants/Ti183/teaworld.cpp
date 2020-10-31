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

#define nmax 17
#define mmax 2005

struct bg
{
    int x, y, z, r;
};

bg t[nmax];
bg c[mmax];
int chon[nmax];
bool kl[mmax];
vector<int> loai[nmax];
int n, m, k, xs, ys, zs;
int kq=0;

double kc (int u, int v, int x, int y)
{
    int a=abs(u-x), b=abs(v-y);
    return sqrt((double)a*a+(double)b*b);
}

double hr (double a, double b, double c)
{
    double p=(a+b+c)/2;
    return (sqrt(p*(p-a)*(p-b)*(p-c)));
}


void ktra ()
{
    int tg=0, dm=0; int i, j;
    FOR(i, 1, m) kl[i]=false;
    FOR(i, 1, n)
        if (chon[i])
        {
            tg+=t[i].r;
            FORK(j, 0, loai[i].size())
                if (kl[loai[i][j]]);
                else
                {
                    kl[loai[i][j]]=true; dm++;
                }
        }
    if (dm<=k) kq=max(kq, tg);
}

void nphan (int i)
{
    int j;
    FOR(j, 0, 1)
    {
        chon[i]=j;
        if (i==n) ktra();
        else nphan(i+1);
    }
}

void sub2 ()
{
    int i, j; double dis, a, b, dt, cos1, cos2;
    FOR(i, 1, n)
    {
        dis=kc(xs, ys, t[i].x, t[i].y);
        FOR(j, 1, m)
        {
            a=kc(xs, ys, c[j].x, c[j].y);
            b=kc(t[i].x, t[i].y, c[j].x, c[j].y);
            if ((a<=c[j].r) || (b<=c[j].r))
            {
                if ((a<=c[j].r) && (b<=c[j].r)) continue;
                else
                {
                    loai[i].pb(j); continue;
                }
            }
            cos1=(dis*dis+a*a-b*b)/(2*a*dis);
            cos2=(dis*dis+b*b-a*a)/(2*b*dis);
            if ((cos1<0) || (cos2<0)) continue;
            dt=hr(a, b, dis);
            if (((2*dt)/dis)<=c[j].r) loai[i].pb(j);
        }
    }
    nphan(1);
}

int main ()
{
    freopen("teaworld.inp","r",stdin);
    freopen("teaworld.out","w",stdout);
    read(m); read(n); read(k);
    int i;
    FOR(i, 1, m)
    {
        read(c[i].x); read(c[i].y); read(c[i].z);
        read(c[i].r);
    }
    FOR(i, 1, n)
    {
        read(t[i].x); read(t[i].y); read(t[i].z);
        read(t[i].r);
    }
    read(xs); read(ys); read(zs);
    sub2();
    writeln(kq);
    return 0;
}
