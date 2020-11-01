#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 1e9+9;
int n, mx, m50, m1, m2;
int a[307], cnt[5], ans;
ll f[307][70][70][70], tg[70][70][70];

void calc1(int i){
    for (int x=1; x<=mx; ++x)
    for (int y=0; y<=mx; ++y)
    for (int z=0; z<=mx; ++z)
        (tg[x][y][z]+=f[i-1][x-1][y][z] ) %= M;
}

void calc2(int i){
    for (int x=mx-1; x>=0; --x)
    for (int y=1; y<=mx; ++y)
    for (int z=0; z<=mx; ++z)
        (tg[x][y][z]+=f[i-1][x+1][y-1][z]) %= M;
}

void calc3(int i){
    for (int x=mx-3; x>=0; --x)
    for (int y=0; y<=mx; ++y)
    for (int z=1; z<=mx; ++z)
        (tg[x][y][z]+=f[i-1][x+3][y][z-1]) %= M;

    for (int x=mx-1; x>=0; --x)
    for (int y=mx-1; y>=0; --y)
    for (int z=1; z<=mx; ++z)
        (tg[x][y][z]+=f[i-1][x+1][y+1][z-1]) %= M;
}

bool check(){
    cnt[1]=m50, cnt[2]=m1, cnt[3]=m2;
    for (int i=1; i<=n; ++i)
    {
        if (cnt[a[i]] == mx) return 0;
        if (a[i] == 1) cnt[a[i]]++;
        if (a[i] == 2)
        {
            if (cnt[1] == 0) return 0;
            cnt[1]--; cnt[2]++;
        }
        if (a[i] == 3)
        {
            if (cnt[1] != 0 && cnt[2] != 0)
            {cnt[1]--; cnt[2]--; cnt[3]++; continue;}
            if (cnt[1] >= 3)
            {cnt[1]-=3; cnt[3]++; continue;}
            return 0;
        }
    }
    return 1;
}

void thu(int t){
    if (t > n) {ans+=check(); return;}
    a[t]=1; thu(t+1);
    a[t]=2; thu(t+1);
    a[t]=3; thu(t+1);
}

int main(){
    freopen("icecream.inp","r",stdin);
    freopen("icecream.out","w",stdout);
    scanf("%d%d", &n, &mx);
    scanf("%d%d%d", &m50, &m1, &m2);

    if (n <= 17) ans=0, thu(1);
    else
    {
        f[0][m50][m1][m2]=1;
        for (int i=1; i<=n; ++i)
        {
            memset(tg, 0, sizeof(tg));
            calc1(i);
            calc2(i);
            calc3(i);
            for (int x=0; x<=mx; ++x)
            for (int y=0; y<=mx; ++y)
            for (int z=0; z<=mx; ++z)
            f[i][x][y][z]=tg[x][y][z];
        }

        for (int x=0; x<=mx; ++x)
        for (int y=0; y<=mx; ++y)
        for (int z=0; z<=mx; ++z) (ans+=f[n][x][y][z]) %= M;
    }

    cout << ans;

    return 0;
}
