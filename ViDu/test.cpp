/*#include<stdio.h>
#include<algorithm>
using namespace std;

int n , a[22] , ans[22] = {0} , k , d[(int(1e6+8))] = {0};

void xuat()
{
    for (int i= 1 ; i <= k ; i++) printf("%d ",ans[i]);
    printf("\n");
}

void quaylui(int vt)
{
    if( vt == k + 1) xuat();
    else 
    {
        for (int i = 1 ; i <= n ; i++)
        {
            if (ans[vt - 1] <= a[i]) 
            {
                ans[vt] = a[i];
                quaylui(vt+1);
            }
        }
    }
}

int main()
{
    freopen("input.inp","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d %d",&n,&k);
    for (int i = 1 ; i <= n ; i++) 
    {
        scanf("%d",&a[i]);
        d[a[i]]++;
    }
    sort(a+1,a+1+n);
    ans[0] = -1;
    quaylui(1);
    return 0;
}*/
  
/*

 */
#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e4 + 10;
const int inf = 1e9 + 7;

#define FileOpen freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);
#define fi first
#define se second
#define dd pair < double, double >

int n;
dd a[N];
double ans = 1.0 * inf;

dd GetMidPoint(dd x, dd y) {
    dd res = dd(((x.fi + y.fi) / 2), ((x.se + y.se) / 2));
    return (res);
}

double sqr(double x) {return (x * x);}

double DistanceOf2Points(dd x, dd y) {
    return (sqrt(sqr(x.fi - y.fi) + sqr(x.se - y.se)));
}

bool Check(double R, dd O) {
    for (int i = 1; i <= n; i++) {
        double r = DistanceOf2Points(a[i], O);
        if (r > R) return (false);
    }
    return (true);
}

int main() {
    FileOpen;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }

    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {            
            dd midPoint = GetMidPoint(a[i], a[j]);
            double d = DistanceOf2Points(a[i], midPoint);
            bool res = Check(d, midPoint);
            if (res) ans = min(ans, d);
        }
    }
    cout << fixed << setprecision(3) << ans << endl;
}