//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

int xa,ya,xb,yb,xc,yc,xm,ym;
float a,b,c,d,e,f;
long s1,s2;

/*long tich(int k,int l,int u){
    float p,kq;
    p = (k+l+u)/2;
   // kq=sqrt((k+l+u)*(k+l-u)*(l+u-k)*(u+k-l))/4;
    kq = sqrt(p*(p-k)*(p-l)*(p-u));
    return kq;
}*/

/*float tich(int u, int l, int t) {
    long p = u + l + t  / 2;
    return sqrt(p*(p - u)*(p - l)*(p - t));
}*/


float chuvi(float u, float l, float k) {
    return u + l + k;
}
float tich(float u, float l, float k) {
    float p = chuvi(u, l, k) / 2.0;
    return sqrt(p*(p - u)*(p - l)*(p - k));
}


float dodai(int o1,int p1 , int o2 , int p2){
    return (sqrt( pow(o1-o2,2) + pow (p1-p2,2)));
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("BAI81.INP","r",stdin);
    freopen("BAI81.OUT","w",stdout);
    cin >> xa >> ya  >> xb >> yb  >> xc >> yc >>  xm >> ym ;

    a=dodai(xa,ya,xb,yb);
    b=dodai(xa,ya,xc,yc);
    c=dodai(xb,yb,xc,yc);
    d=dodai(xa,ya,xm,ym);
    e=dodai(xb,yb,xm,ym);
    f=dodai(xc,yc,xm,ym);

    //cerr << a <<"  "  << b <<"  "<< c <<"  "<< d <<"  "<< e <<"  "<< f<< endl;

    s1 = tich(a,b,c);
    s2 = tich(d,e,a) + tich(d,f,b) + tich(e,f,c);

    cerr << tich(a,e,d)<< " " << tich(e,a,d) << " " << tich(a,d,e) << " " << tich(d,a,e) << " " << tich(e,d,a) << " " << tich (d,e,a) << endl;
    cerr << tich(b,d,f)<< " " << tich(b,f,d) << " " << tich(d,f,b) << " " << tich(d,b,f) << " " << tich(f,b,d) << " " << tich(f,d,b) << endl;
    cerr << tich(e,f,c)<< " " << tich(f,e,c) << " " << tich(e,c,f) << " " << tich(f,a,e) << " " << tich(c,e,f) << " " << tich(c,f,e) << endl;
    cerr << s1 <<" " << s2;

    /*if (s1 == s2 ) cout << " YES";
    else    if ( s1 > s2 ) cout << " M thuộc cạnh tam giác ";
            else cout << " NO";*/

    if (s1 == s2 ) cout << " YES";
    else cout << " NO";
    return 0;
}


