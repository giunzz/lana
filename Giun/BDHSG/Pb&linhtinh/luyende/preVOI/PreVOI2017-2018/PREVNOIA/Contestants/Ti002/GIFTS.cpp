#include <bits/stdc++.h>
#define forr(i, a, b) for(long i= a; i<= b; i++)
#define pb push_back
#define mn 1000001
using namespace std;
long n, k, cnt= 1, N, maxx= 0, minn= mn;
long long a[mn], s[mn], last;
vector< long> vcl[mn];
struct bl
{
    long long c;
    long be, en;
};
bl p[mn];
bool sx(const bl& xx, const bl& yy)
{
    if(xx.c== yy.c) return xx.be< yy.be;
    return xx.c< yy.c;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("GIFLS.inp", "r", stdin);
    freopen("GIFLS.out", "w", stdout);
    cin>> n>> k;
    s[0]= 0;
    forr(i, 1, n) cin>> a[i], s[i]= s[i- 1]+ a[i];
    forr(i, k, n){
        p[i- k+ 1].c= s[i]- s[i- k];
        p[i- k+ 1].be= i- k+ 1;
        p[i- k+ 1].en= i;
    }
    N= n- k+ 1;
    sort(p+ 1, p+ N+ 1, sx);
    vcl[cnt].pb(1);
    long vtri= 1, vari= 1;
    while(vtri<= N){
        while(vari<= N&& p[vtri].c== p[vari].c){
            vcl[cnt].pb(vari);
            vari++;
        }
        vtri= vari;
        ++cnt;
    }
    cnt--;
    for(long i= cnt; i> 0; i--)
    {
        long kt= vcl[i].size();
        maxx= max(maxx, p[vcl[i][kt- 1]].be);
        minn= min(minn, p[vcl[i][0]].en);
        if(maxx- minn>= k){
            cout<< p[vcl[i][0]].c;
            return 0;
        }
    }
    cout<< p[vcl[1][0]].c;
    return 0;
}
