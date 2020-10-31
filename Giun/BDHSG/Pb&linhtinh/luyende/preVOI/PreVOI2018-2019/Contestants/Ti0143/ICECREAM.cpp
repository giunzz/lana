#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
using ll=long long;
using ld=long double;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "ICECREAM"
int n, CMAX;
int O50, O1, O2;
const int base=1000000009;
void add(int &x, int y){
    x+=y;
    if(x>=base) x-=base;
}
int f[51][51][51][51];
vector <int> s;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #else
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    #endif // Uiharu
    read(n);
    read(CMAX);
    read(O50);
    read(O1);
    read(O2);
    f[0][0][0][0]=1;
    FFOR(i, 0, n) FOR(m50, 0, i) FOR(m1, 0, i) FOR(m2a, 0, i) if(f[i][m50][m1][m2a]){
        int m2b=i-m50-m1-m2a;
        if(m2b<0) break;
        int c50=O50+m50-m1-m2a-m2b*3;
        if(c50<0||c50>CMAX) continue;
        int c1=O1+m1-m2a;
        if(c1<0||c1>CMAX) continue;
        int c2=O2+m2a+m2b;
        if(c2<0||c2>CMAX) continue;
        add(f[i+1][m50+1][m1][m2a], f[i][m50][m1][m2a]);
        if(c50) add(f[i+1][m50][m1+1][m2a], f[i][m50][m1][m2a]);
        if(c1&&c50) add(f[i+1][m50][m1][m2a+1], f[i][m50][m1][m2a]);
        else if(c50>2) add(f[i+1][m50][m1][m2a], f[i][m50][m1][m2a]);
    }
    int ans=0;
    FOR(i, n, n) FOR(m50, 0, i) FOR(m1, 0, i) FOR(m2a, 0, i) if(f[i][m50][m1][m2a]){
        int m2b=i-m50-m1-m2a;
        if(m2b<0) break;
        int c50=O50+m50-m1-m2a-m2b*3;
        if(c50<0||c50>CMAX) continue;
        int c1=O1+m1-m2a;
        if(c1<0||c1>CMAX) continue;
        int c2=O2+m2a+m2b;
        if(c2<0||c2>CMAX) continue;
        add(ans, f[i][m50][m1][m2a]);
    }
    writeln(ans);
}