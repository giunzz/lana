#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
double a,b,c,d,e,f;
long long s1,s2, xa,ya,xb,yb,xc,yc,xm,ym;

double chuvi(double u, double l, double k) { return u + l + k;}
double tich(double u, double l, double k) 
{
    double p = chuvi(u, l, k) / 2.0;
    return sqrt(p*(p - u)*(p - l)*(p - k));
}
double dodai(int o1,int p1 , int o2 , int p2){ return (sqrt( pow(o1-o2,2) + pow (p1-p2,2)));}
int main ()
{
    ios_base::sync_with_stdio(0) , cin.tie(0);
    freopen("TAMGIACB.inp","r",stdin);
    freopen("TAMGIACB.out","w",stdout);
    cin >> xa >> ya  >> xb >> yb  >> xc >> yc >>  xm >> ym ;
    a=dodai(xa,ya,xb,yb);
    b=dodai(xa,ya,xc,yc);
    c=dodai(xb,yb,xc,yc);
    d=dodai(xa,ya,xm,ym);
    e=dodai(xb,yb,xm,ym);
    f=dodai(xc,yc,xm,ym);
    s1 = tich(a,b,c);
    s2 = tich(d,e,a) + tich(d,f,b) + tich(e,f,c);
    if (s1 == s2 ) cout << "YES";
    else cout << "NO";
    return 0;
}


