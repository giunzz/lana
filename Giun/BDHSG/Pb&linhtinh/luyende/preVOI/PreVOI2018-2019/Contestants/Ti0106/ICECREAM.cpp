#include <bits/stdc++.h>
#define x first
#define y second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
int n,m,m0,m1,m2;
int f[20][12][12][12],kq;
const int base=1e9+9;
typedef pair<int,int> ii;
typedef pair<ii,ii> ll;
queue<ll> q;
map<ll,int> dd;
void sub1()
{
    f[0][m0][m1][m2]=1;
    FOR(i,1,n)
    FOR(j,0,m)
    FOR(k,0,m)
    FOR(h,0,m)
    {
        if(j) f[i][j][k][h]=(f[i][j][k][h]+f[i-1][j-1][k][h])%base;
        if(j<m&&k) f[i][j][k][h]=(f[i][j][k][h]+f[i-1][j+1][k-1][h])%base;
        if(j<m&&k<m&&h) f[i][j][k][h]=(f[i][j][k][h]+f[i-1][j+1][k+1][h-1])%base;
        if(j+3<=m&&k==0&&h) f[i][j][k][h]=(f[i][j][k][h]+f[i-1][j+3][k][h-1])%base;
    }
    FOR(i,0,m)
    FOR(j,0,m)
    FOR(k,0,m) kq=(kq+f[n][i][j][k])%base;
    cout<<kq;
}
void sub2()
{
    q.push(ll(ii(0,m0),ii(m1,m2)));
    dd[ll(ii(0,m0),ii(m1,m2))]=1;
    while(!q.empty())
    {
        int a=q.front().x.x;
        int b=q.front().x.y;
        int c=q.front().y.x;
        int d=q.front().y.y;
        q.pop();
        if(!dd[ll(ii(a,b),ii(c,d))]) continue;
        if(a==n)
        {
            kq=(kq+dd[ll(ii(a,b),ii(c,d))])%base;
            continue;
        }
        if(b<m)
        {
            if(!dd[ll(ii(a+1,b+1),ii(c,d))]) q.push(ll(ii(a+1,b+1),ii(c,d)));
            dd[ll(ii(a+1,b+1),ii(c,d))]=(dd[ll(ii(a+1,b+1),ii(c,d))]+dd[ll(ii(a,b),ii(c,d))])%base;
        }
        if(b&&c<m)
        {
            if(!dd[ll(ii(a+1,b-1),ii(c+1,d))]) q.push(ll(ii(a+1,b-1),ii(c+1,d)));
            dd[ll(ii(a+1,b-1),ii(c+1,d))]=(dd[ll(ii(a+1,b-1),ii(c+1,d))]+dd[ll(ii(a,b),ii(c,d))])%base;
        }
        if(b&&c&&d<m)
        {
            if(!dd[ll(ii(a+1,b-1),ii(c-1,d+1))]) q.push(ll(ii(a+1,b-1),ii(c-1,d+1)));
            dd[ll(ii(a+1,b-1),ii(c-1,d+1))]=(dd[ll(ii(a+1,b-1),ii(c-1,d+1))]+dd[ll(ii(a,b),ii(c,d))])%base;
        }
        if(b>=3&&c==0&&d<m)
        {
            if(!dd[ll(ii(a+1,b-3),ii(c,d+1))]) q.push(ll(ii(a+1,b-3),ii(c,d+1)));
            dd[ll(ii(a+1,b-3),ii(c,d+1))]=(dd[ll(ii(a+1,b-3),ii(c,d+1))]+dd[ll(ii(a,b),ii(c,d))])%base;
        }

    }
    cout<<kq;
}
void nhap()
{
    cin>>n>>m>>m0>>m1>>m2;
    if(n<=15&&m<=10) sub1();
    else sub2();
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("ICECREAM.inp","r",stdin);
    freopen("ICECREAM.out","w",stdout);
    nhap();
    return 0;
}
