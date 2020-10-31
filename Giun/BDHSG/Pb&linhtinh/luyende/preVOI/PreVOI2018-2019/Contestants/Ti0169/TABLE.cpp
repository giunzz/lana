#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <cstring>
#include <iomanip>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;
#define inf 280201280201280201
#define mn 305
#define FLN "TABLE"
#define int long long
typedef pair<int, int> ii;
//constance

//common data structures and templates
template<typename T>
struct SegmentTree{
};
//gb
int m, n, k;
int a[mn][mn];
int sX, sY, eX, eY;
int f[mn][mn], g[mn][mn];
int mxr[mn][mn], mxc[mn][mn];
//functions here
void input(){
}
void solve(){
  memset(f, 0, sizeof f);
  memset(g, 0, sizeof g);
  for(int i =sX; i<= eX; ++i)
    for(int j=sY; j<= eY; ++j){
      if(i==sX) f[i][j] = f[i][j-1] + a[i][j];
      else if(j==sY) f[i][j] = f[i-1][j] + a[i][j];
      else{
        f[i][j] = max(f[i][j-1] + a[i][j],\
          f[i-1][j] + a[i][j]
        );
      }
    } 
  for(int i =eX; i >= sX; --i)
    for(int j = eY; j >= sY; --j){
      if(i==eX) g[i][j] = g[i][j+1] + a[i][j];
      else if(j==eY) g[i][j] = g[i+1][j] + a[i][j];
      else{
        g[i][j] = max(g[i][j+1] + a[i][j],\
          g[i+1][j] + a[i][j]
        );
      }
    }
  int ans = f[eX][eY];
  for(int i=sX; i<=eX ; ++i){
    mxr[i][sY] = f[i][sY] + g[i][sY] - a[i][sY];
    for(int j=sY+1; j<= eY; ++j)
      mxr[i][j] = max(mxr[i][j-1], f[i][j] + g[i][j] - a[i][j]);
  }
  for(int i=sY; i<= eY; ++i){
    mxc[sX][i] = f[sX][i] + g[sX][i] - a[sX][i];
    for(int j=sX+1; j<= eX; ++j)
      mxc[j][i] = max(mxc[j-1][i], f[j][i] + g[j][i] - a[j][i]);
  }
  for(int i=sX+1; i<eX; ++i)
    for(int j=sY+1; j< eY; ++j){
      ans = min(ans, max(mxr[i+1][j-1], mxc[i-1][j+1]));
    }
  for(int j=sY+1; j< eY; ++j){
    ans= min(ans, mxr[sX+1][j-1]);
    ans = min(ans, mxc[eX-1][j+1]);
  } 
  for(int i=sX+1; i < eX; ++i){
    ans = min(ans, mxc[i-1][sY+1]);
    ans = min(ans, mxr[i+1][eY-1]);
  }
  cout << ans << "\n";
}

#define LOCAL 1

signed main(signed argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifdef LOCAL
	   freopen(FLN".inp", "r", stdin);
	   freopen(FLN".out", "w", stdout);
#endif  
  cin >> m >> n >> k;
  for(int i=1; i<= m; ++i)
    for(int j=1; j<= n; ++j) cin >> a[i][j];
  while(k--){
    cin >> sX >> sY >> eX >> eY;
    solve();
  }
	return 0;
}

