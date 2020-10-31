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
#define mn 100005
#define FLN "MODULO"
#define int long long
typedef pair<int, int> ii;
//constance

//common data structures and templates
template<typename T>
struct SegmentTree{
};
//gb
int a,b, n, k;
int S;
int f[22][2000005];
int mod[23];
string ans;
//functions here
void input(){
}
void solve(){
}
bool sub1(){
  return n <= 25;
}
int dp(int i, int j){
  if(i >= n) return (j==k);
  if(f[i][j] > -1) return f[i][j];
  f[i][j] = min(dp(i+1, (j+a*mod[i])%S), 2LL); 
  f[i][j] = min(2LL, f[i][j] + min(dp(i+1, (j+b*mod[i])%S), 2LL));
  return f[i][j];
}
void printAns(int i, int j){
  if(i >= n) return ;
  if(dp(i+1, (j+a*mod[i])%S) > 0){
    ans.push_back(a+'0');
    printAns(i+1, (j+a*mod[i])%S);
  }
  else if(dp(i+1, (j+b*mod[i])%S) > 0){
    ans.push_back(b + '0');
    printAns(i+1, (j+b*mod[i])%S);
  }
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
  cin >> a >> b >> n >> k;
  mod[0] = 1;
  S = (1LL<< n);
  if(sub1()){
    for(int i=1; i<= n; ++i) mod[i] = (mod[i-1]*10)%S;
    memset(f, -1, sizeof f);
    printAns(0, 0);
    reverse(ans.begin(), ans.end());
    cout << ans;
  }
	return 0;
}

