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
#define mn 25
#define FLN "ICECREAM"
#define int long long
#define MOD 1000000007
typedef pair<int, int> ii;
//constance

//common data structures and templates
template<typename T>
struct SegmentTree{
};
//gb
int n, mmax;
int a[3];
int f[mn][mn][mn][mn];
//functions here
void input(){
}
void solve(){
}
bool sub1(){
  return n < 25 && mmax < 25;
}
int dp(int i, int x, int y, int z){
  if(f[i][x][y][z] > -1) return f[i][x][y][z];
  if(i> n) return f[i][x][y][z] =1;
  int ans = 0;
  // j= 0;
  if(x < mmax) ans += dp(i+1, x+1, y, z);
  ans %= MOD;
  //j=1;
  if(y < mmax && x> 0) ans += dp(i+1, x-1, y+1, z);
  ans %= MOD;
  //j = 2;
  if(z < mmax){
    if(y > 0 && x >0) ans += dp(i+1, x-1, y-1, z+1);
    else if(x >=3) ans += dp(i+1, x-3, y, z+1);
    ans %= MOD;
  }
  return f[i][x][y][z] = ans;
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
  cin >> n >> mmax;
  cin >> a[0] >> a[1] >> a[2];
  if(sub1()){
    memset(f, -1, sizeof f);
    cout << dp(1, a[0], a[1], a[2]);
  }
	return 0;
}

