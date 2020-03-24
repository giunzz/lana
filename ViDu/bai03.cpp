#include<bits/stdc++.h>

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
    meo = meo / (float ) 2 , ans = meo;
    for (int i = 1 ; i < n ; i++)
    {
        double r = dodai(a[i].fi , a[i].se) / (float ) 2;
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
}

