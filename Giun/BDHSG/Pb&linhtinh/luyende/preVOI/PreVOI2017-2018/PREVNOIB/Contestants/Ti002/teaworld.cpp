#include <bits/stdc++.h>
#define forr(i, a, b) for(long i= a; i<= b; i++)
#define mn 2001
using namespace std;
long dem =0,n, m, k, x[mn], e[mn], y, z, X, hb[mn], hs[mn], ms, cu, ft[mn], fp[mn], res= 0, minn= 1e9+ 7, maxx= -1e9-7;
long long S[20];

struct bong
{
    long x, r, vtri1, vtri2;
}ball[mn];
struct cuahang
{
    long x, e;
}shop[20];
bool sxball(const bong& xx, const bong& yy)
{
    return xx.vtri1< yy.vtri1;
}
bool sxball2(const bong& xx, const bong& yy)
{
    return xx.vtri2< yy.vtri2;
}
bool sxshop(const cuahang& xx, const cuahang& yy)
{
    return xx.x< yy.x;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("teaworld.inp", "r", stdin);
    freopen("teaworld.out", "w", stdout);
    cin>> m>> n>> k;
    forr(i, 1, m)
    {
        cin>> ball[i].x>> y>> z>> ball[i].r;
        ball[i].vtri1= ball[i].x- ball[i].r;
        ball[i].vtri2= ball[i].x+ ball[i].r;
    }
    forr(i, 1, n){
        cin>> shop[i].x>> y>> z>> shop[i].e;
    }
    cin>> X>> y>> z;
    sort(ball+ 1, ball+ m+ 1, sxball);
    sort(shop+ 1, shop+ n+ 1, sxshop);
    forr(i, 1, m)
    {
        if(ball[i].vtri1<= X&& ball[i].vtri2>= X){
                ++dem;
        minn= min(minn, ball[i].vtri1);
        maxx= max(maxx, ball[i].vtri2);
        }
    }
    S[0]= 0;
    forr(i, 1, n){
        S[i]= S[i- 1]+ shop[i].e;
        hs[i]= shop[i].x;
    }
    forr(i, 1, m) hb[i]= ball[i].vtri1;
    sort(hb+ 1, hb+ m+ 1);
    sort(hs+ 1, hs+ n+ 1);
    long vb= lower_bound(hb+ 1, hb+ m+ 1, X)- hb;
    long vs= lower_bound(hs+ 1, hs+ n+ 1, X)- hs;
    cu= vb;
    for(long i= vb; i<= vb+ m+ 1, i<= m; i++)
    {
        ms= lower_bound(hs+ 1, hs+ n+ 1, ball[i].vtri1)- hs;
        ft[i- vb+ 1]= ft[i- vb]+ S[ms]- S[cu- 1];
        cu= ms;
    }
    sort(ball+ 1, ball+ m+ 1, sxball2);
    forr(i, 1, m) hb[i]= ball[i].vtri2;
    vb= lower_bound(hb+ 1, hb+ m+ 1, X)- hb;
    cu= vb;
    for(long i= vb; i> vb- m- 1, i> 0; i--)
    {
        ms= lower_bound(hs+ 1, hs+ n+ 1, ball[i].vtri2)- hs;
        fp[i- vb+ 1]= fp[i- vb]+ S[cu]- S[ms- 1];
        cu= ms;
    }
    long id= lower_bound(hs+ 1, hs+ n+ 1, minn)- hs;
    long _id= upper_bound(hs+ 1, hs+ n+ 1, maxx)- hs;
    long vl= S[_id- 1]- S[id- 1];
    m-= dem;
    forr(i, 0, m)
    {
        res= max(res, ft[i]+ fp[m- i]);
    }
    cout<< res+ vl;
    return 0;
}
