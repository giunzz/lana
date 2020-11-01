#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<=b; i++)
using namespace std;

int n,mmax,m50,m1,m2;
int res;

void DFS(int x, int a, int b, int c)
{
    if (x==n+1)
    {
        res++;
        return;
    }

    if (a<mmax) DFS(x+1,a+1,b,c);
    if (a>0 && b<mmax) DFS(x+1,a-1,b+1,c);
    if (a>0 && b>0 && c<mmax) DFS(x+1,a-1,b-1,c+1);
    if (a>2 && c<mmax) DFS(x+1,a-2,b,c+1);
}

void sub1()
{
    DFS(1,m50,m1,m2);
    cout<<res;
}

int main()
{
    freopen("icecream.inp","r",stdin);
    freopen("icecream.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>mmax;
    cin>>m50>>m1>>m2;

    sub1();

}
