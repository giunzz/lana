#include <bits/stdc++.h>
#define maxn
#define oo 1e9+5
#define foru(a,b,c) for (int a=b;a<=c;a++)
#define ford(a,b,c) for (int a=b;a>=c;a--)
#define mp make_pair
#define pb push_back
#define ii pair<int,int>
#define ll long long
#define forv(a,b) for(auto&a:b)
#define base 1000000009
using namespace std;
ll kq;
int m50,m1,m2,n,x[305],mmax,e=300;
//int xd[101][151][101][101];
//int f[101][151][101][101];
map<int,map<int,int> > f[305][1000],xd[305][1000];
void update()
{
    int dem1=m50,dem2=m1,dem3=m2;
    foru(i,1,n)
    {
        if (x[i]==50) ++dem1;
        if (dem1>mmax) return;
        if (x[i]==100)
        {
            if (dem1==0) return;
            --dem1;
            ++dem2;
            if (dem2>mmax) return;
        }
        if (x[i]==200)
        {
            if (dem1>0 && dem2>0)
            {
                --dem1;
                --dem2;
                ++dem3;
                if (dem3>mmax) return;
            }
            else if (dem2==0 && dem1>=3)
            {
                dem1-=3;
                ++dem3;
                if (dem3>mmax) return;
            }
            else return;
        }
    }
    ++kq;
}
void tohop(int i)
{
    foru(j,0,2)
    {
        if (j==0) x[i]=50;
        else if (j==1) x[i]=100;
        else x[i]=200;
        if (i==n) update();
        else tohop(i+1);
    }
}
void xuli1()
{
    tohop(1);
    cout << kq << endl;
}
ll tinh(int vt, int dem1,int dem2,int dem3)
{
    if (vt==n+1) return 1;
    if (xd[vt][dem1][dem2][dem3]) return f[vt][dem1][dem2][dem3];
    xd[vt][dem1][dem2][dem3]=1;
    ll res=0;
    if (dem1+1-e+m50<=mmax) res=(res+tinh(vt+1,dem1+1,dem2,dem3))%base;
    if (dem1-e+m50>0 && dem2-e+1+m1<=mmax) res=(res+tinh(vt+1,dem1-1,dem2+1,dem3))%base;
    if (dem1-e+m50>0 && dem2-e+m1>0 && dem3-e+1+m2<=mmax) res=(res+tinh(vt+1,dem1-1,dem2-1,dem3+1))%base;
    else if (dem1-e+m50>=3 && dem3-e+1+m2<=mmax) res=(res+tinh(vt+1,dem1-3,dem2,dem3+1))%base;
    return f[vt][dem1][dem2][dem3]=res;
}
void xuli2()
{
    cout << tinh(1,e,e,e) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("icecream.inp", "r", stdin);
    freopen("icecream.out", "w", stdout);
    cin >> n >> mmax;
    cin >> m50 >> m1 >> m2;
    if (n<15) xuli1(); else
    xuli2();
}
