#include <bits/stdc++.h>
#define maxn 3005
#define oo 1e9+5
#define foru(a,b,c) for (int a=b;a<=c;a++)
#define ford(a,b,c) for (int a=b;a>=c;a--)
#define mp make_pair
#define pb push_back
#define ii pair<int,int>
#define ll long long
#define forv(a,b) for(auto&a:b)
using namespace std;
void read(int &n) {
    n = 0;
    int ch = getchar(), sign=1;
    while( ch < '0' || ch > '9' ){
        if (ch == '-') sign = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    n *= sign;
}
void put(int x)
{
    if (x > 9) put(x / 10);
    putchar(x % 10 + 48);
}
struct data
{
    int x,vt;
};
bool cmp(data p1,data p2)
{
    if (p1.x!=p2.x) return p1.x<p2.x;
    return p1.vt>p2.vt;
}
bool cmp2(data p1,data p2)
{
    return p1.vt<p2.vt;
}
int n,m,k;
data a[maxn],b[maxn],p[maxn],q[maxn];
void xuli1()
{
    vector<int> kq;
    foru(i,1,k) kq.pb(oo);
    foru(x,0,min(m,k))
    {
        int y=k-x;
        if (y>n) continue;
        int sl1=0,sl2=0;
        foru(i,1,x) p[++sl1]=a[i];
        foru(i,1,y) q[++sl2]=b[i];
        sort(p+1,p+sl1+1,cmp2);
        sort(q+1,q+sl2+1,cmp2);
        int i=1,j=1;
        p[x+1].x=oo;q[y+1].x=oo;
        int vt=0,vt2=0;
        bool ok=false;
        vector<int> res;
        while (i<=x || j<=y)
        {
            if (p[i].x<q[j].x) res.pb(p[i++].x);
            else if (p[i].x>q[j].x) res.pb(q[j++].x);
            else
            {
                int u=i,v=j;
                while (u<=x || v<=y)
                {
                    if (p[u].x==q[v].x) {++u;++v;}
                    else
                    {
                        if (p[u].x<q[v].x) {res.pb(p[i++].x);break;}
                        else if (p[u].x>q[v].x) {res.pb(q[j++].x);break;}
                    }
                }
                if (u==x+1 || v==y+1) {res.pb(p[i++].x);}
            }
        }
        kq=min(kq,res);
    }
    foru(i,1,k) {put(kq[i-1]);putchar(' ');}
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("sequence.inp", "r", stdin);
    freopen("sequence.out", "w", stdout);
    read(m);read(n);read(k);
    foru(i,1,m)
    {
        read(a[i].x);
        a[i].vt=i;
    }
    foru(i,1,n)
    {
        read(b[i].x);
        b[i].vt=i;
    }
    sort(b+1,b+n+1,cmp);
    sort(a+1,a+m+1,cmp);
    //if (m<=100 && n<=100) xuli1();
    xuli1();
}
