#include<bits/stdc++.h>

using namespace std;

const int BASE = 1010;
const int MAXN = BASE*4+20;
int mark[MAXN] , le[MAXN] , ri[MAXN] , m , k , n , x0 , y0 , z0;
long long tea[MAXN];
const double e = 1e-9;

inline bool inSeq(int x , int l, int r)
{
    if(l<=x && x<= r) return true;
    return false;
}

struct data
{
    int x ,y , r;
    data(){}
    data(int _x , int _y , int _r) : x(_x) , y(_y) , r(_r) {}
    bool operator<(const data &b) const
    {
        return x < b.x;
    }
} c[MAXN] , a[MAXN];

inline void sub1()
{
    sort(a+1 ,a+n+1);
    sort(c+1 , c+m+1);
    for(int i = 1 ; i<=n ; i++)
        tea[i] = tea[i-1] + a[i].r;
    tea[n+1] = tea[n];
    int p =-1;
    for(int i = 1 ; i<=n ; i++)
        if(a[i].x >= x0)
    {
        p = i;
        break;
    }

    long long ans = 0;

    if(p == -1) p = n+1;
    //cerr<<p<<endl;
    for(int l = p ; l>=1 ; l--)
        for(int r = p-1 ; r<=n ; r++)
    {
        int le = a[l].x , ri = a[r].x;
        le = min(le , x0);
        ri = max(ri , y0);
        int cnt = 0;
        for(int i = 1 ; i<=m ; i++)
        {
            if(inSeq(c[i].x +c[i].r , le +1, ri-1) || inSeq(c[i].x-c[i].r , le+1 , ri-1)) cnt++;
            if(c[i].x + c[i].r == le || c[i].x - c[i].r == ri) cnt++;
        }
        if(cnt <=k)
        {
            ans = max(ans , tea[r] - tea[l-1]);
        }
    }
    printf("%d",ans);
}

inline pair<double ,double> get_line(int x1 , int y1 , int x2 , int y2)
{
    pair<double ,double> ans;
    ans.first = double(y1 - y2) / double(x1 - x2);
    ans.second = double(y1) - ans.first*x1;
    return ans;
}

double sqr(double a)
{
    return a*a;
}

inline pair<double , double> get(double A , double B , double C)
{
    C = -C;
    double delta = sqrt(sqr(B) - A*C*4);
    return make_pair((-B + delta)/(2*A) , (-B - delta)/(2*A));
}

inline bool check(int id , int x , int y)
{
    pair<double , double> lines;
    lines = get_line(x0 , y0 , x , y);
    pair<double , double>  corndi = get(sqr(lines.first) +1, -2*(c[id].x - lines.first*lines.second + lines.first*c[id].y) , sqr(c[id].r) - sqr(c[id].x) - sqr(c[id].y) - sqr(lines.second) + 2*lines.second*c[id].y);
    double l = min(double(x0) ,double(x));
    double r = max(double(x0) ,double(x));
    if(corndi.first > corndi.second) swap(corndi.first , corndi.second);
    if(abs(l - corndi.first) < e && abs(r - corndi.second) < e) return false;
    if(l <= corndi.first && corndi.first <= r) return true;
    if(l <= corndi.second && corndi.second <= r) return true;
    return false;
}

inline void sub2()
{
    long long ans = 0;
    for(int tus = 1 ; tus < (1<<n) ; tus++)
    {
        memset(mark , 0 , sizeof(mark));
        vector<pair<int ,int> > v;
        long long sum  =0;
        for(int i  = 1 ; i<=n  ;i++)
            if(((tus>>(i-1))&1))
            {
                v.push_back(make_pair(a[i].x , a[i].y));
                sum += a[i].r;
            }
        int cnt = 0;
        for(int i =  1 ; i<=m  ;i++)
        {
            for(int j = 0 ; j<v.size() ; j++)
                if(check(i , v[j].first , v[j].second))
            {
                cnt++;
                break;
            }
        }
        if(cnt <=k){ ans = max(ans ,sum);}
    }
    printf("%lld",ans);
}

int main()
{
    freopen("TEAWORLD.inp" , "r" , stdin);
    freopen("TEAWORLD.out" , "w", stdout);
    scanf("%d%d%d",&m,&n,&k);
    int ok =1;
    for(int i = 1 ; i<=m ; i++)
    {
        int z;
        scanf("%d%d%d%d",&c[i].x , &c[i].y , &z , &c[i].r);
        if(c[i].y !=0 ) ok = 0;
    }

    for(int i = 1 ; i<=n ; i++)
    {
        int z;
        scanf("%d%d%d%d",&a[i].x , &a[i].y , &z , &a[i].r);
        if(a[i].y !=0 ) ok = 0;
    }

    scanf("%d%d%d",&x0,&y0,&z0);
    if(y0 != 0) ok = 0;
    if(ok) sub1();
    else sub2();
    return 0;
}
