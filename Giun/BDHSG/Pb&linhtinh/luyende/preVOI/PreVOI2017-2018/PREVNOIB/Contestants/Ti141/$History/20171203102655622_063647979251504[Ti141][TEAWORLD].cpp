#include <bits/stdc++.h>

#define TASK "TEAWORLD"

using namespace std;

template<typename T> inline void read(T &x){
    x = 0; char ch; bool neg = 0;
    while(!isdigit(ch=getchar())&&ch!='-');
    if(ch=='-'){neg=1;ch=getchar();}
    do{x=10*x+ch-'0';}while(isdigit(ch=getchar()));
    if(neg) x = -x;
}

typedef long double ld;

const int N = 22;
const int M = 2222;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

int m, n, k, sx, sy, sz;
int dp[2][M], F[2][M], res;
struct Point{
    int x, y ,z, val;
    bool operator < (const Point &a){
        return x < a.x || (x==a.x&&y<a.y) || (x==a.x&&y==a.y&&z<a.z);
    }
} P[M], D[N], s;

int getBit(int x, int p){
    return (x>>p)&1;
}

Point operator - (Point a, Point b){
    return {a.x-b.x,a.y-b.y};
}

int operator * (Point a, Point b){
    return a.x*b.y-a.y*b.x;
}

int mul(Point a, Point b){
    return a.x*b.x+a.y*b.y;
}

ld dist(Point a){
    return sqrt(a.x*a.x+a.y*a.y);
}

bool inCir(int j, Point t){
    return (ld)P[j].val+EPS>dist(t-P[j]);
}

bool intersect(int i, int j){
    if(inCir(j,s)) return !inCir(j,D[i]);
    if(inCir(j,D[i])) return !inCir(j,s);
    ld rad;
    rad = acos((ld)mul((s-P[j]),(s-D[i]))/(dist(s-P[j])*dist(s-D[i])));
    if(rad>PI/2) return 0;
    rad = acos((ld)mul((D[i]-P[j]),(D[i]-s))/(dist(D[i]-P[j])*dist(D[i]-s)));
    if(rad>PI/2) return 0;
    ld d = fabs((ld)((P[j]-s)*(P[j]-D[i]))/dist(s-D[i]));
    if(d<(ld)P[j].val+EPS) return 1;
    return 0;
}

bool B[M];

void sol2(int num, int type, int add){
    for(int st = 0; st < (1<<num); st++){
        memset(B,0,sizeof(B));
        int cnt = 0;
        int sum = 0;
        for(int i = add+1; i <= add+num; i++){
            if(getBit(st,i-add-1)){
                for(int j = 1; j <= m; j++){
                    if(!B[j]&&intersect(i,j)){
                        B[j] = 1;
                    }
                }
                sum += D[i].val;
            }
        }
        for(int i = 1; i <= m; i++) cnt += B[i];
        dp[type][st] = sum;
        F[type][st] = cnt;
    }
}

void solve2(){
    sol2(n,0,0);
    //sol2(n-n/2,1,n/2);
    int num = n;
    res = 0;
    int cnt = 0;
    int st = 0;
    for(int i = 0; i < (1<<num); i++){
        if(F[0][i]<=k){
            if(res<dp[0][i]){
                res = dp[0][i];
                cnt = F[0][i];
                st = i;
            }
        }
    }
    //cerr<<cnt<<endl<<st<<endl;
    cout<<res<<'\n';
}

void solve3(){
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    read(m); read(n); read(k);
    bool isSub1 = 1;
    bool isSub2 = 1;
    for(int i = 1; i <= m; i++){
        int x, y, z, r;
        read(x); read(y); read(z); read(r);
        if(y!=0) isSub1 = 0;
        if(z!=0) isSub2 = 0;
        P[i] = {x,y,z,r};
    }
    for(int i = 1; i <= n; i++){
        int x, y, z, e;
        read(x); read(y); read(z); read(e);
        if(y!=0) isSub1 = 0;
        if(z!=0) isSub2 = 0;
        D[i] = {x,y,z,e};
    }
    read(s.x); read(s.y); read(s.z);
    if(isSub1){
        solve2();
    }
    else if(isSub2){
        solve2();
    }
    else solve3();
    return 0;
}
