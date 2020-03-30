/*#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define dd pair<int , int >
#define giun ios_base::sync_with_stdio(0) , cin.tie(0);

int n , m1 , m2 , g1 , g2;
dd a[1007];
double dt , meo = -2.00 , ans = -2.00 , ac , cb;
vector <int> s;

double len(dd x, dd y) 
{
    return ( sqrt( pow(x.fi - y.fi , 2) + pow (x.se - y.se , 2) ) );
}

double dodai(int o1,int p1 )
{
    return (sqrt( pow(o1-0,2) + pow (p1-0,2)));
}

double dodai2(int o1,int p1 , int o2 , int p2){
    return (sqrt( pow(o1-o2,2) + pow (p1-p2,2)));
}


int main()
{
    giun;
    freopen("input.inp", "r", stdin) , freopen("output.txt", "w", stdout);
    //freopen("bai03.inp", "r", stdin);
    //nnfreopen("bai03.out", "w", stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++ ) cin >> a[i].fi >> a[i].se;
    for (int i = 1 ; i < n ; i++)
    {
        for (int j = i+1 ; j <= n ; j++)
            if ( meo < len (a[i] , a[j]) ) 
            {
                m1 = a[i].fi , m2 = a[j].fi ;
                g1 = a[i].se , g2 = a[j].se ;
                meo = len (a[i] , a[j]);
            }
    }
    meo = meo / (double ) 2 , ans = meo;
    for (int i = 1 ; i < n ; i++)
    {
        double r = dodai(a[i].fi , a[i].se) / (double ) 2;
        if ( r > meo ) s.push_back(i);
        //cerr << r << " ";
    }
    
    for (int i = 0 ; i < (int)s.size() ; i++ )
    {
        dt = abs ( ( (m2-m1) * (g1+g2) + (m2 - a[s[i]].fi ) * ( g2 + a[s[i]].se ) + (a[s[i]].fi - m1 ) * ( g1 + a[s[i]].se ) ) / 2 );
        ac = dodai2 (m1 , g1 , a[s[i]].fi, a[s[i]].se);
        cb = dodai2 (m2 , g2 , a[s[i]].fi, a[s[i]].se);
        ans = max ( ans ,  (meo*ac*cb) / (4 *dt ) );
    }
    cout << fixed << setprecision(3) << ans ;
    //cerr << clock() << " ms";
    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
const string file = "giun";
#define fi first
#define se second
#define dd pair<int , int >
#define giun(a) freopen((a + ".inp").c_str(), "r", stdin) ,freopen((a + ".out").c_str(), "w", stdout);
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
int n;
dd at[107];
double bk , a , b, c , ans = DBL_MIN;

double kc(dd x, dd y) 
{
    double d = ( sqrt( pow(x.fi - y.fi , 2) + pow (x.se - y.se , 2) ) );
    return d;
}

double dt ( dd ya , dd yb , dd yc )
{
    double d;
    d = abs ( ( ( yc.fi + ya.fi ) * (yc.se - ya.se) +  ( ya.fi + yb.fi ) * (ya.se - yb.se) + ( yb.fi + yc.fi ) * (yb.se - yc.se) ) / 2  );
    d = round( d * 1000.0 ) / 1000.0;
    return d;
}


int main()
{
    double s;
    giun(file);
    giuncute;
    cin >> n;
    for (int i = 1 ; i <= n ; i++ ) cin >> at[i].fi >> at[i].se;

    for (int i = 1 ; i <= n - 2 ; i++)
    {
        for (int j = i+1 ; j <= n -1 ; j++)
        {
            for (int z = j+1 ; z <= n ; z++)
            {
                a = kc( at[i] , at[j] ); 
                b = kc( at[j] , at[z] ); 
                c = kc( at[z] , at[i] );
                s = dt (at[i] , at[j] , at[z]);
                bk = (a*b*c) / ( 4 * s );
                cerr << at[i].fi << " " << at[i].se << " | " <<  at[j].fi << " " << at[j].se << " | " << at[z].fi << " " << at[z].se << endl;
                cerr << a << " " << b << " " << c << " " << s << " " << bk << endl;
                ans = max( ans , bk);
            }
        }
   
    }
    cout << fixed << setprecision(3) << ans ;
    cerr << endl;
    cerr << clock() << " ms";
    return 0;    
}