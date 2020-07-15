/*#include<bits/stdc++.h>
using namespace std;
double a[5] , ans = -1;
long long s1,s2, xa,ya,xb,yb,xc,yc,n;

double chuvi(double u, double l, double k) { return u + l + k;}
double tich(double u, double l, double k) 
{
    double p = chuvi(u, l, k) / 2.0;
    return sqrt(p*(p - u)*(p - l)*(p - k));
}
double dodai(int o1,int p1 , int o2 , int p2){ 
    double val = (sqrt( pow(o1-o2,2) + pow (p1-p2,2))); 
    return roundf(val * 100) / 100;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("giun.inp","r", stdin);freopen("giun.out","w",stdout);
    freopen("SQT.inp","r", stdin);freopen("SQT.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++ )
    {
        cin >> xa >> ya  >> xb >> yb  >> xc >> yc;
        a[1]=dodai(xa,ya,xb,yb);
        a[2]=dodai(xa,ya,xc,yc);
        a[3]=dodai(xb,yb,xc,yc);
        sort (a+1 , a+1+3);
        double x = a[1]*a[1] + a[2]*a[2];
        if ( ceilf(x * 100) / 100 == ceilf(a[3]*a[3] * 10) / 10 ) ans = max (ans , (a[1]*a[2])/2 );
    }
    cout  << setprecision(2) << ans << endl ;
    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll  xa,ya,xb,yb,xc,yc,n,a,b,c;
double ans = -1 , t;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i  = 1 ; i <= n ; i++)
    {
        cin >> xa >> ya >> xb >> yb >> xc >> yc;
        a = (xa - xb) * ( xa - xb) + (ya - yb) * (ya - yb);
        b = (xa - xc) * ( xa - xc) + (ya - yc) * (ya - yc);
        c = (xc - xb) * ( xc - xb) + (yc - yb) * (yc - yb);
        if (a+b == c || a + c == b  || b + c ==  a )
        {
            t = abs ( ( yc + ya ) * (xc - xa) + (ya+yb) * (xa-xb) + (yb+yc) * (xb-xc) );
            ans = max (ans , abs (t/2.0) );
        }  
    }
    cout << ans ;
    return 0;
}







