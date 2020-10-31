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

#define nmax 100005

queue<int> thap;
queue<int> cao;
ll a[nmax];
ll tg=0, kq=0;
int n;
ll k;

void sub1 ()
{
    k=tg/n;
    int i, j, b, dis;
    FOR(i, 1, n)
    {
        if (a[i]>k)
        {
            while ((!thap.empty()) && (a[i]>k))
            {
                b=k-a[thap.front()]; dis=i-thap.front();
                if ((a[i]-b)>=0)
                {
                    a[i]-=b; a[thap.front()]+=b;
                    thap.pop(); kq+=((ll)b*dis);
                }
                else
                {
                    kq+=((ll)a[i]*dis);
                    a[thap.front()]+=a[i]; a[i]=0;
                }
            }
            if (a[i]<k) thap.push(i);
            else if (a[i]>k) cao.push(i);
        }
        else if (a[i]<k)
        {
            if ((!cao.empty()) && (a[i]<k))
            {
                j=cao.front(); b=k-a[i]; dis=i-j;
                if ((a[j]-b)>=k)
                {
                    a[i]+=b; a[j]-=b;
                    kq+=((ll)b*dis);
                    if (a[j]==k) cao.pop();
                }
                else
                {
                    b=a[j]-k; kq+=((ll)b*dis);
                    a[i]+=b; a[j]-=b;
                    cao.pop();
                }
            }
            if (a[i]<k) thap.push(i);
        }
    }
}

void sub2 ()
{
    ll tmp;
    sub1(); tmp=(tg-k*n);
    kq=kq+tmp/2;
}

int main ()
{
    freopen("arrange.inp","r",stdin);
    freopen("arrange.out","w",stdout);
    read(n); int i;
    FOR(i, 1, n)
    {
        read(a[i]); tg+=a[i];
    }
    if ((tg%n)==0) sub1();
    else sub2();
    //sub1();
    writeln(kq);
    return 0;
}
