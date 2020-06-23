/*#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

int  a , b , n , dem[12] ;

void fastscan(int &number) 
{ 
    bool negative = false; 
    register int c; 
    number = 0; 
    c = getchar(); 
    if (c == ' ') fastscan(number);
    if (c=='-') 
    { 
        negative = true; 
        c = getchar(); 
    } 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
    if (negative) 
        number *= -1; 
}

int main()
{
    balabalo;
    for (int giun = 1 ; giun <= 500 ; giun++)
    {
        fastscan(a) ; 
        fastscan(b);
        //cin >> a >> b ;
        cerr << a << " " << b << endl;
        if ( a == 0 && b == 0 ) return 0;
        else 
            {
                for (int i = 0 ; i <= 10 ; i++) dem[i] = 0;
                int i = min(a,b);
                while ( i <= max(a,b) )
                {  
                    int j = i;
                    while (j != 0 )
                    {
                        dem[j % 10 ]+= 1;
                        j = j / 10;
                    }
                    i++;  
                }
                for (int i = 0 ; i < 10 ; i++) cout << dem[i] << " ";
                cout << endl;
            }
    }
}*/

//#include<bits/stdc++.h>
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
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> xa >> ya  >> xb >> yb  >> xc >> yc >>  xm >> ym ;
    a=dodai(xa,ya,xb,yb);
    b=dodai(xa,ya,xc,yc);
    c=dodai(xb,yb,xc,yc);
    d=dodai(xa,ya,xm,ym);
    e=dodai(xb,yb,xm,ym);
    f=dodai(xc,yc,xm,ym);
    s1 = tich(a,b,c);
    s2 = tich(d,e,a) + tich(d,f,b) + tich(e,f,c);
    if (s1 == s2 ) cout << " YES";
    else cout << " NO";
    return 0;
}


