#include<bits/stdc++.h>
#define For(i, a, b)  for(int i = a; i <= b; ++i)
#define Ford(i, a, b) for(int i = a; i >= b; --i)
#define FileName      "modulo"
#define ll            long long
#define ld            long double
#define ull           unsigned long long
#define pb            push_back
#define X             first
#define Y             second
#define Karma

using namespace std;

template <typename T> inline void Cin(T &x)
{
    char c;
    T sign = 1;
    x = 0;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') sign = -1;
    for (; c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    x *= sign;
}

typedef pair<int, int> pii;
typedef pair<ll, int> plli;
const int N = 70;

ll n, A, B, k, p[N], m, sp[N];
struct SubOne
{
    int x[N], found;
    string res;
    void Attemp(int pos)
    {
         if(found) return;
         if(pos > n)
         {
             ll t = 0;
             for(int i = 1; i <= n; ++i)
             {
                 ll c = x[i] == 0? A: B;
                 t = (t * 10 + c) % m;
             }
             if(t == k)
             {
                 found = 1;
                 res = "";
                 for(int i = 1; i <= n; ++i)
                 {
                     char c = x[i] == 0? char(A + '0'): char(B + '0');
                     res += c;
                 }
             }
             return;
         }
         x[pos] = 0;
         Attemp(pos + 1);
         x[pos] = 1;
         Attemp(pos + 1);
    }
    void Solve()
    {
        found = 0;
        Attemp(1);
        if(found) cout << res;
        else cout << -1;
    }
} one;

struct SubTwo
{
     string lef;
     map<int, string> rig;
     int x[N], lim, mod;
     map<int, bool> vis;
     bool found;
     void Attemp(int pos)
     {
          if(found) return;
          if(pos > lim)
          {
              if(lim == n / 2)
              {
                  ll t = 0;
                 for(int i = 1; i <= lim; ++i)
                 {
                     ll c = x[i] == 0? A: B;
                     t = (t * 10 + c) % m;
                 }
                 mod = k - (t * p[n - n / 2]) % m;
                 if(mod < 0) mod += m;
                 if(!vis[mod]) return;
                 lef = "";
                 found = 1;
                 for(int i = 1; i <= lim; ++i)
                 {
                     char c = x[i] == 0? char(A + '0'): char(B + '0');
                     lef += c;
                 }
              }
              else
              {
                 ll t = 0;
                 for(int i = n / 2 + 1; i <= lim; ++i)
                 {
                     ll c = x[i] == 0? A: B;
                     t = (t * 10 + c) % m;
                 }
                 if(vis[t]) return;
                 rig[t] = "";
                 vis[t] = 1;
                 for(int i = n / 2 + 1; i <= lim; ++i)
                 {
                     char c = x[i] == 0? char(A + '0'): char(B + '0');
                     rig[t] += c;
                 }
              }
              return;
          }
          x[pos] = 0;
          Attemp(pos + 1);
          x[pos] = 1;
          Attemp(pos + 1);
     }
     void Solve()
     {
          found = 0;
          lim = n;
          Attemp(n / 2 + 1);
          lim = n / 2;
          Attemp(1);
          if(found) cout << lef << rig[mod];
          else cout << -1;
     }
} two;

struct SubThree
{
    int x[N], found, cnt;
    string res;
    void Attemp(int pos)
    {
         if(found || cnt >= 2000000) return;
         ++cnt;
         ll t = 0;
         for(int i = 1; i <= pos; ++i)
         {
             ll c = x[i] == 0? A: B;
             t = (t * 10 + c) % m;
         }
         if((t * p[n - pos] % m + (sp[n - pos] * A) % m) % m == k)
         {
             found = 1;
             res = "";
             for(int i = 1; i <= pos; ++i)
             {
                 char c = x[i] == 0? char(A + '0'): char(B + '0');
                 res += c;
             }
             for(int i = pos + 1; i <= n; ++i)
                res += char(A + '0');
         }
         if((t * p[n - pos] % m + (sp[n - pos] * B) % m) % m == k)
         {
             found = 1;
             res = "";
             for(int i = 1; i <= pos; ++i)
             {
                 char c = x[i] == 0? char(A + '0'): char(B + '0');
                 res += c;
             }
             for(int i = pos + 1; i <= n; ++i)
                res += char(B + '0');
         }
         x[pos] = 0;
         Attemp(pos + 1);
         x[pos] = 1;
         Attemp(pos + 1);
    }
    void Down(int pos)
    {
         if(found || cnt >= 2000000) return;
         ++cnt;
         ll t = 0;
         for(int i = pos + 1; i <= n; ++i)
         {
             ll c = x[i] == 0? A: B;
             t = (t * 10 + c) % m;
         }
         if((t + (sp[pos] * A) % m * p[n - pos] % m) % m == k)
         {
             found = 1;
             res = "";
             for(int i = 1; i <= pos; ++i)
                res += char(A + '0');
             for(int i = pos + 1; i <= n; ++i)
             {
                 char c = x[i] == 0? char(A + '0'): char(B + '0');
                 res += c;
             }
         }
         if((t + (sp[pos] * B) % m * p[n - pos] % m) % m == k)
         {
             found = 1;
             res = "";
             for(int i = 1; i <= pos; ++i)
                res += char(B + '0');
             for(int i = pos + 1; i <= n; ++i)
             {
                 char c = x[i] == 0? char(A + '0'): char(B + '0');
                 res += c;
             }
         }
         x[pos] = 0;
         Attemp(pos + 1);
         x[pos] = 1;
         Attemp(pos + 1);
    }
    void Solve()
    {
        found = 0;
        Attemp(1);
        cnt = 0;
        Down(n);
        if(found) cout << res;
        else cout << -1;
    }
} three;

void Enter()
{
     Cin(A), Cin(B), Cin(n), Cin(k);
     m = (1ll << n);
     p[0] = sp[0] = 1 % m;
     For(i, 1, n) p[i] = (p[i - 1] * 10) % m, sp[i] = (sp[i - 1] + p[i]) % m;
     if(n <= 20) one.Solve();
     else if(n <= 40) two.Solve();
     else three.Solve();
}

void Solve()
{

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifdef Karma
    freopen(FileName".inp", "r", stdin);
    freopen(FileName".out", "w", stdout);
#endif // Karma

    Enter();
    Solve();

    return 0;
}
