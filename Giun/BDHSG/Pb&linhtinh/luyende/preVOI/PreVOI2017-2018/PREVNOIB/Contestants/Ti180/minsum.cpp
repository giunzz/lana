#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define F first
#define S second
#define mp make_pair
#define LL long long
#define fort(i,a,b) for(LL i=(a); i<=(b); i++)
#define ford(i,a,b) for(LL i=(a); i>=(b); i--)

using namespace std;

void Karl_Heinrich_Marx()
{
    #ifndef ONLINE_JUDGE
    freopen("minsum.inp","r",stdin);
    freopen("minsum.out","w",stdout);
    #endif // ONLINE_JUDGE
}

LL GCD( LL x, LL y )
{
    LL tmp = 0;
    while( y > 0 ) {
        tmp = x%y;
        x = y;
        y = tmp;
    }
    return x;
}
void xuly( LL x, LL y )
{
    vector<LL> a;
    LL tmp = GCD(x,y);
    x = x / tmp;
    y = y / tmp;
    LL res = 1e18 , t1,t2;
    for(LL i = 2; i*i <= x; i++) {
        while( x % i == 0 ) {
            a.pb( i );
            x/=i;
        }
    }
    if( x > 1 ) a.pb(x);
    for(LL i = 2; i*i <= y; i++) {
        while( y % i == 0 ) {
            a.pb(i);
            y/=i;
        }
    }

    if( a.size() == 0 ) {
        cout << 1 << " " << 1 <<'\n';
    }
    sort(a.begin(), a.end());
    if( y > 1 ) a.pb(y);
    LL n = a.size();
    if( a.size() <= 15 ) {
        LL m ; m = (1<<n); m--;
        LL ok1, ok2;
        fort(i,0,m) {
            ok1 = ok2 = 1;
            fort(j,0,n-1) {
                if( (i>>j)&1 ) ok1=ok1*a[j];
                else ok2 = ok2 * a[j];
            }
            if( ok1 + ok2 < res) {
                res = ok1 + ok2;
                t1 = ok1; t2 = ok2;
            }
        }
        cout << t1 << " " << t2 <<'\n';
        return;
    }

    if( n <= 40 ) {
        vector<LL> a1, a2;
        LL ans = 1;
        LL an1=1;
        LL ok1, ok2;
        ok1 = ok2 = 1;
        fort(i,0,n-1) {
            ans = ans * a[i];
        }
        an1=ans;
        ans = sqrt( ans );
        LL tam = (n-1)/2;
        LL m;
        m = (1<<tam); m--;
        fort(i,0,m) {
            ok1 = 1;
            fort(j,0,tam) {
                if( (i>>j)&1 ) ok1*=a[j];
            }

            a1.pb(ok1);
        }
        m = ( 1 << (n-tam-1) );  m--;
        fort(i,0,m) {
            ok1=1;
            fort(j,tam+1,n-1) {
                if( (i>>(j-tam-1))&1 ) ok1*=a[j];
            }
            a2.pb(ok1);

        }
        res = 1e18; LL tamp;
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());
        vector<LL>::iterator it;
        for(LL i = 0 ; i < a1.size(); i++) {
            tamp = ans/a1[i];
            it = lower_bound( a2.begin(), a2.end(), tamp );
            if( it == a2.end() ) it--; tam=(*it);

            if( res > tam*a1[i] + an1/(tam*a1[i]) ) {
                t1 = tam*a1[i]; t2 = an1/t1;
                res = t1 + t2;
            }

            it = upper_bound( a2.begin(),a2.end(),tamp );
            if( it == a2.end() ) it--;tam=(*it);

            if( res > tam*a1[i] + an1/(tam*a1[i]) ) {
                t1 = tam*a1[i]; t2 = an1/t1;
                res = t1 + t2;
            }

        }
        cout << t1 <<" " <<t2<<'\n';
        return ;
    }

    t1 = 1; t2 = 1;
    fort(i,1,n-1) {
        if( t1 > t2 ) t2*=a[i];
        else t1*=a[i];
    }
    cout << t1 << " " << t2 <<'\n';

}
LL T;
LL a,b;
void Vladimir_Ilyich_Lenin()
{
    cin >> T;
    fort(TEST,1,T) {
        cin >> a >> b;
        xuly(a,b);
    }
}
int main()
{
    Karl_Heinrich_Marx();
    Vladimir_Ilyich_Lenin();
    return 0;
}
