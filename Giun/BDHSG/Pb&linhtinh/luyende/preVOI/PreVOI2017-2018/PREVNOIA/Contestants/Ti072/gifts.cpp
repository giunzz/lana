#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <queue>
#include <string>
#include <set>
#include <deque>

using namespace std;
#define int long long
#define uint unsigned long long
#define F1(i,i1,i2) for(int i=i1;i<=i2;i++)
#define F2(i,i1,i2) for(int i=i1;i>=i2;i--)
#define pb push
#define pp pair<int,int>
#define mp make_pair
#define xx first
#define yy second
#define NMAX 2000006
const int DMAX=(int)LONG_MAX*NMAX;

int n,k,a[NMAX],b[NMAX],fx[NMAX],fn[NMAX];

int readint()
{
    char c;
    do c=getchar();
    while (c<'0'||c>'9');
    int re=0;
    while (c>='0'&&c<='9')
    {
        re=re*10+c-'0';
        c=getchar();
    }
    return re;
}

void enter()
{
    n=readint();
    k=readint();
    F1(i,1,n) a[i]=readint();
}

int get_(int l,int r)
{
    return b[r]-b[l-1];
}

void solve()
{
    F1(i,1,n) b[i]=b[i-1]+a[i];
    //
    F1(i,k,n) fx[i]=max(fx[i-1],get_(i-k+1,i));
    //
    F2(i,n-k+1,1) fn[i]=max(fn[i+1],get_(i,i+k-1));
    //
    int kq=DMAX;
    F1(i,1,n-k+1)
    {
        int x=max(fx[i-1],fn[i+k]);
        kq=min(kq,x);
    }
    cout<<kq;
}


main()
{
    ios::sync_with_stdio(0);
    freopen("gifts.inp","r",stdin);
    freopen("gifts.out","w",stdout);
    enter();
    solve();
}
