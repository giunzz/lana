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
#define PMAX 100005

const int DMAX=(int)LONG_MAX/2*LONG_MAX;

int A,B,node,re,kq1,kq2;
pp Q[PMAX];
int ss[PMAX],S[PMAX];

void prime_()
{
    int a=A,b=B;
    //
    node=0;
    F1(i,2,trunc(sqrt(a)))
    if (a%i==0)
    {
        int dem=0;
        while ((a%i)==0 && a>1)
        {
            a/=i;
            dem++;
        }
        while ((b%i)==0 && b>1)
        {
            b/=i;
            dem++;
        }
        Q[++node].xx=i;
        Q[node].yy=dem;
        if (a==1) break;
    }
    if (a>1)
    {
        int dem=1;
        while ((b%a)==0 && b>1)
        {
            b/=a;
            dem++;
        }
        Q[++node].xx=a;
        Q[node].yy=dem;
        a=1;
    }
    //
    F1(i,2,trunc(sqrt(b)))
    if (b%i==0)
    {
        int dem=0;
        while ((b%i)==0 && b>1)
        {
            b/=i;
            dem++;
        }
        Q[++node].xx=i;
        Q[node].yy=dem;
        if (b==1) break;
    }
    if (b>1)
    {
        Q[++node].xx=b;
        Q[node].yy=1;
    }
}

void tinh()
{
    int x1=1,x2=1;
    F1(i,1,node)
    {
        if (ss[i]) x1*=S[i];
        else x2*=S[i];
    }
    if (x1+x2<re)
    {
        re=x1+x2;
        kq1=x1;
        kq2=x2;
    }
}

void duyet(int i)
{
    if (i>node)
    {
        tinh();
        return;
    }
    F1(j,0,1)
    {
        ss[i]=j;
        duyet(i+1);
    }
}

void optimize_()
{
    int node2=0;
    F1(i,1,node)
    {
        if (Q[i].yy%2==1)
            S[++node2]=Q[i].xx;
    }
    node=node2;
    sort(S+1,S+1+node);
    re=DMAX;
    duyet(1);
    cout<<kq1<<' '<<kq2<<'\n';
}

main()
{
    ios::sync_with_stdio(0);
    freopen("minsum.inp","r",stdin);
    freopen("minsum.out","w",stdout);
    int t;
    cin>>t;
    while (t--)
    {
        cin>>A>>B;
        prime_();
        optimize_();

    }
}
