#include <bits/stdc++.h>
#define Ball_x(i) p[i].first.first
#define Ball_y(i) p[i].first.second
#define Ball_z(i) p[i].second.first
#define Ball_r(i) p[i].second.second
#define MilkTea_x(i) q[i].first.first
#define MilkTea_y(i) q[i].first.second
#define MilkTea_z(i) q[i].second.first
#define MilkTea_r(i) q[i].second.second
#define coor_x vitri.first.first
#define coor_y vitri.first.second
#define coor_z vitri.second
using namespace std;
const int maxN = 17, maxM = 2005;
int m, n, k;
typedef pair<double , double> II;
typedef pair<II , double> III;
typedef pair<II , II> IIII;
IIII p[maxM], q[maxN];
III vitri;

double Input(){
    scanf("%d %d %d", &m, &n, &k);
    for(int i = 1 ; i <= m ; ++ i) { // Ball
        double x, y, z, r;
        scanf("%lf %lf %lf %lf", &x, &y, &z, &r);
        p[i] = IIII(II(x,y),II(z, r));
    }
    for(int i = 1 ; i <= n ; ++ i) { // MilkTea
        double x, y, z, r;
        scanf("%lf %lf %lf %lf", &x, &y, &z, &r);
        q[i] = IIII(II(x, y), II(z , r));
    }
    scanf("%lf %lf %lf", &vitri.first.first, &vitri.first.second , &vitri.second);
    return 0;
}

inline II operator - (II A, II B){
    return II(B.first - A.first, B.second - A.second);
}
inline II operator + (II A, II B){
    return II(B.first + A.first, B.second + A.second);
}
inline double operator * (II A, II B){
    return A.first * B.second - A.second * B.first;
}
inline II operator * (int B, II A){
    return II(A.first * B, A.second * B);
}
inline double dist(II A, II B){
    return (A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second);
}
inline double Down(II O, II A, II B){
    II AB = (A - B); AB = II(- AB.second, AB.first);
    double c = - (AB.first * A.first + AB.second * A.second);
    return abs(AB.first * O.first + AB.second * O.second + c) / (sqrt(AB.first * AB.first + AB.second * AB.second));
}

II Cross(II A, II B, II C, II D){
    II AC = A - C, CD = C - D, AB = A - B;
    double p = (AC * CD) / (AB * CD);
    II M = A + p * AB;
    return M;
}

bool Check(II O , II A, II B){
    II AB = (A - B);
    double c = - (AB.first * O.first + AB.second * O.second),
           y = min(A.second, B.second) - 1,
           x = (- c - AB.second * y) / AB.first;
    II K = II(x , y);
    II H = Cross(A, B, O , K), OH = O - H, OA = O - A, OB = O - B;
    return ((OH * OA) * (OH * OB) <= 0);
}
bool Check_Cross(double A, double B, double O, double r){
    double OA = abs(O - A),
           OB = abs(O - B),
           AB = abs(A - B);
    if(OA + OB == AB) return true;
    return min(OA, OB) <= r;
}
int x[maxN], ds, dd[maxM];
int Process(){
    int Count = 0, kq = 0;
    for(int i = 1 ; i <= m ; ++ i) dd[i] = 0;
    for(int i = 1 ; i <= n ; ++ i) if(x[i]){
        for(int j = 1 ; j <= m ; ++ j) {
            if(!dd[j]) Count += Check_Cross(vitri.first.first, q[i].first.first, p[j].first.first, Ball_r(j));
            dd[j] = 1;
        }
        if(Count > k) return 0;
        kq += MilkTea_r(i);
    }
    ds = max(ds, kq);
    return 0;
}
int Try(int i){
    if(i > n){Process(); return 0;}
    for(int j = 0 ; j <= 1 ; ++ j){
        x[i] = j;
        Try(i + 1);
    }
    return 0;
}
int Solve(){
    ds = 0;
    Try(1);
    printf("%d", ds);
    return 0;
}

#define TASK "TEAWORLD"
int main(){
    #ifdef TASK
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    #else
    freopen("main.inp","r",stdin);
    #endif // TASK
    Input();
    Solve();
}

