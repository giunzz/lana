#include<bits/stdc++.h>

#define fi first
#define se second

using namespace std;

int a, b, n;
int64_t k, s;

typedef pair<int64_t, string> II;
queue<II> q;
string a1, b1, ds;
vector<int64_t> g[65];
string doi(int a)
{
    if(a == 1) return "1";
    if(a == 2) return "2";
    if(a == 3) return "3";
    if(a == 4) return "4";
    if(a == 5) return "5";
    if(a == 6) return "6";
    if(a == 7) return "7";
    if(a == 8) return "8";
    return "9";
}
void bfs(int a ,int b)
{
    a1 = doi(a);
    b1 = doi(b);
    int ok = 0;
    if(a % 2 != k % 2 && b % 2 == k % 2) ok = 1;
    if(b % 2 != k % 2 && a % 2 == k % 2 ) ok = 2;
    int64_t u = (int64_t)a % s;
    q.push (II(u, a1));
    if(b1 != a1) {q.push(II(b % s, b1));}
    while(!q.empty())
    {
        II v = q.front();
        q.pop();
        int64_t u2 = v.fi;
        string s1 = v.se;
        string s2 = s1;
        int m = s1.length();
        if(m == n && u2 == k){ ds = s1; return;}
        if(m < n){
        int64_t v1 = 0;
        v1 = (u2 * 10 % s + a % s) % s;
        if ( m + 1 <= n && (ok == 0 || ok == 2))
        {
            s1 = s1 + a1;
            q.push(II(v1, s1));
        }
        v1 = (u2 * 10 % s + b % s)%s;
        if(m + 1 <= n && (ok == 0 || ok == 1))
        {
            s2 = s2 + b1;
            q.push(II(v1, s2));
        }
        }

    }
}
int main()
{
    freopen("modulo.inp", "r", stdin);
    freopen("modulo.out", "w", stdout);
    scanf("%d %d", &a, &b);
    scanf("%d %I64d", &n, &k);
    if(a % 2 == 1 && b % 2 == 1 && k % 2 == 0) {printf("-1");return 0;}
    if(a % 2 == 0 && b % 2 == 0 && k % 2 == 1) {printf("-1"); return 0;}
    s = 1;
    for(int i = 1; i <= n; ++i) s = 2 * s;
    if(a % s == k && n == 1) {printf("%d", a); return 0;}
    if(b % s == k && n == 1) {printf("%d", b); return 0;}
    bfs(a, b);
    int m = ds.length();
    if(m == 0) printf("-1");
    for(int i = 0; i <m; ++i) printf("%c", ds[i]);
}
