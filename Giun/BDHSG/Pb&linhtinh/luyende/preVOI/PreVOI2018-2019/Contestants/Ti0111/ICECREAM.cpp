#include<bits/stdc++.h>
#define For(i, a, b)  for(int i = a; i <= b; ++i)
#define Ford(i, a, b) for(int i = a; i >= b; --i)
#define FileName      "icecream"
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
const int N = 300;
const int mod = (int)1e9 + 9;

int n, mmax, x, y, z;

struct Sub
{
      int f[305][305][305], _f[305][305][305];
      void DP()
      {
          fill_n(&f[0][0][0], 305 * 305 * 305, 0);
          _f[x][y][z] = 1;
          for(int i = 1; i <= n; ++i)
          {
              // j - m50 - k - m1 - l - m2
              for(int j = 0; j <= mmax; ++j)
              {
                  for(int k = 0; k <= mmax; ++k)
                  {
                      for(int l = 0; l <= mmax; ++l)
                      {
                          //50
                          if(j >= 1) f[j][k][l] += _f[j - 1][k][l];
                          if(f[j][k][l] >= mod) f[j][k][l] -= mod;
                          //100
                          if(k >= 1) f[j][k][l] += _f[j + 1][k - 1][l];
                          if(f[j][k][l] >= mod) f[j][k][l] -= mod;
                          //200
                          if(l >= 1)
                          {
                              f[j][k][l] += _f[j + 1][k + 1][l - 1];
                              if(f[j][k][l] >= mod) f[j][k][l] -= mod;
                              if(k == 0) f[j][k][l] += _f[j + 3][k][l - 1];
                              if(f[j][k][l] >= mod) f[j][k][l] -= mod;
                          }
                      }
                  }
              }
             for(int j = 0; j <= mmax; ++j)
              {
                  for(int k = 0; k <= mmax; ++k)
                  {
                      for(int l = 0; l <= mmax; ++l)
                      _f[j][k][l] = f[j][k][l], f[j][k][l] = 0;
                  }
              }
          }
          int res = 0;
          for(int j = 0; j <= mmax; ++j)
          {
              for(int k = 0; k <= mmax; ++k)
              {
                  for(int l = 0; l <= mmax; ++l)
                  {
                      res += _f[j][k][l];
                      if(res >= mod) res -= mod;
                  }
              }
          }
          cout << res;
      }
} t;

struct SubTwo
{
      struct TVal
      {
          int x, y, z;
          bool operator <(const TVal& o) const&
          {
              if(x != o.x) return x < o.x;
              if(y != o.y) return y < o.y;
              return z < o.z;
          }
      };
      map<TVal, int> f, _f;
      int DP()
      {
          f.clear();
          _f[{x, y, z}] = 1;
          int cnt = 0;
          for(int i = 1; i <= n; ++i)
          {
              // j - m50 - k - m1 - l - m2
              if(cnt >= 50000000) break;
              for(int j = 0; j <= mmax; ++j)
              {
                  if(cnt >= 5000000) break;
                  for(int k = 0; k <= mmax; ++k)
                  {
                      if(cnt >= 5000000) break;
                      for(int l = 0; l <= mmax; ++l)
                      {
                          ++cnt;
                          if(cnt >= 5000000) break;
                          //50
                          int& res = f[{j, k, l}];
                          if(j >= 1) res += _f[{j - 1, k, l}];
                          if(res >= mod) res -= mod;
                          //100
                          if(k >= 1) res += _f[{j + 1, k - 1, l}];
                          if(res >= mod) res -= mod;
                          //200
                          if(l >= 1)
                          {
                              res += _f[{j + 1, k + 1, l - 1}];
                              if(res >= mod) res -= mod;
                              if(k == 0) res += _f[{j + 3, k, l - 1}];
                              if(res >= mod) res -= mod;
                          }
                      }
                  }
              }
              for(int j = 0; j <= mmax; ++j)
              {
                  if(cnt >= 5000000) break;
                  for(int k = 0; k <= mmax; ++k)
                  {
                      if(cnt >= 5000000) break;
                      for(int l = 0; l <= mmax; ++l)
                      {
                          ++cnt;
                          if(cnt >= 5000000) break;
                          _f[{j, k, l}] = f[{j, k, l}], f[{j, k, l}] = 0;
                      }
                  }
              }
          }
          int res = 0;
          cnt = 0;
          for(int j = 0; j <= mmax; ++j)
          {
              if(cnt >= 5000000) return res;
              for(int k = 0; k <= mmax; ++k)
              {
                  if(cnt >= 5000000) return res;
                  for(int l = 0; l <= mmax; ++l)
                  {
                      if(cnt >= 5000000) return res;
                      res += _f[{j, k, l}];
                      if(res >= mod) res -= mod;
                      ++cnt;
                  }
              }
          }
          return res;
      }
} o;

void Enter()
{
     Cin(n), Cin(mmax);
     Cin(x), Cin(y), Cin(z);
     if(mmax <= 300) t.DP();
     else cout << o.DP();
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
