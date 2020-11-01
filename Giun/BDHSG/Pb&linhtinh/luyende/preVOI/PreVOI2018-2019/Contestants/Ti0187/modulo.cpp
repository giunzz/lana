#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=65;
int a,b,dx[N];
ll n,k,du,m,kq;
map<ll,int>mm;
vector<ll>d;
void xuli1() {
    du=0;
    for (int i=n/2+1; i<=n; i++)
    {
        if (dx[i]==0) du=(du*10+a);
        else du=(du*10+b);
        if (du>=m) du=du%m;
    }
    mm[du]=1;
}
void Try1(int i) {
    dx[i]=0;
    if (i<n) Try1(i+1);
    else xuli1();

    dx[i]=1;
    if (i<n) Try1(i+1);
    else xuli1();
}
void xuli() {
    du=0;
    for (int i=n/2+1; i<=n; i++)
    {
        if (dx[i]==0) du=(du*10+a);
        else du=(du*10+b);
        if (du>=m) du=du%m;
    }
    if (du==kq)
    {
        for (int i=n/2+1; i<=n; i++)
        {
            if (dx[i]==0) cout << a;
            else cout << b;
        }
        exit(0);
    }
}
void Try(int i) {
    dx[i]=0;
    if (i<n) Try(i+1);
    else xuli();

    dx[i]=1;
    if (i<n) Try(i+1);
    else xuli();
}
void xuli2() {
    du=0;
    for (int i=1; i<=n/2; i++)
    {
        if (dx[i]==0) du=(du*10+a);
        if (dx[i]==1) du=(du*10+b);
        if (du>=m) du=du%m;
    }
    for (int i=n/2+1; i<=n; i++)
        du=(du*10)%m;
    if (mm.find(k-du)!=mm.end())
    {
        for (int i=1; i<=n/2; i++)
        {
            if (dx[i]==0) cout << a;
            else cout << b;
        }
        kq=k-du;
        Try(n/2+1);
    }
    if (mm.find(k+m-du)!=mm.end())
    {
        for (int i=1; i<=n/2; i++)
        {
            if (dx[i]==0) cout << a;
            else cout << b;
        }
        kq=k+m-du;
        Try(n/2+1);
    }
}
void Try2(int i) {
    dx[i]=0;
    if (i<n/2) Try2(i+1);
    else xuli2();

    dx[i]=1;
    if (i<n/2) Try2(i+1);
    else xuli2();
}
void sub1()
{
    m=(1LL<<n);
    Try1(n/2+1);
    Try2(1);
    cout << -1;
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    cin >> a >> b >> n >> k;
    if (n<=40) sub1();
    cout << -1;

}
