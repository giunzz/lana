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
#include <iterator>
using namespace std;
#define inf 280201280201280201
#define mn 3005
#define FLN "SEQUENCE"
#define int long long
typedef pair<int, int> ii;
//constance

//common data structures and templates
template<typename T>
struct SegmentTree{
};
//gb
int n, m, k;
int a[mn];
int b[mn];
int mxa[mn][mn];
int mxb[mn][mn];
vector<int> va, vb, c, d;
vector<vector<int> > g;
//functions here
void input(){
}
void prep(){
  memset(mxa, -1, sizeof mxa);
  memset(mxb, -1, sizeof mxb);
  mxa[1][n] = n;
  for(int i=n-1; i>= 1; --i){
    if(a[mxa[1][i+1]] < a[i]) mxa[1][i] = mxa[1][i+1];
    else mxa[1][i] = i;
  }
  for(int t = 1; t <= n; ++t){
    mxa[t][n-t+1] = n-t+1;
    for(int i= n-t; i >= 1; --i){
      if(a[mxa[t][i+1]] < a[i]) mxa[t][i] = mxa[t][i+1];
      else mxa[t][i] = i;
    } 
  }
  mxb[1][m] = m;
  for(int i=m-1; i>= 1; --i){
    if(b[mxb[1][i+1]] < b[i]) mxb[1][i] = mxb[1][i+1];
    else mxb[1][i] = i;
  }
  for(int t = 1; t <= m; ++t){
    mxb[t][m-t+1] = m-t+1;
    for(int i= m-t; i >= 1; --i){
      if(b[mxb[t][i+1]] < b[i]) mxb[t][i] = mxb[t][i+1];
      else mxb[t][i] = i;
    } 
  }
}
void takeA(int i, int j){
  if(mxa[j][i] == -1) return;
  va.push_back(a[mxa[j][i]]);
  takeA(mxa[j][i]+1, j-1);
}
void takeB(int i, int j){
  if(mxb[j][i] == -1) return;
  vb.push_back(b[mxb[j][i]]);
  takeB(mxb[j][i]+1, j-1);
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
  cin >> n >> m >> k;
  for(int i=1; i<= n; ++i) cin >> a[i];
  for(int i=1;i<= n; ++i) cin >> b[i];
  prep(); 
  for(int i= min(k, n); i>=max(k-m, 0LL); --i){
    int j = k-i;
    //cerr << i << " "<< j << "\n";
    c.clear();
    d.clear();
    va.clear();
    vb.clear();
    takeA(1, i);
    takeB(1, j);
    d.assign(j, 0);
    c.assign(i, -1);
    if(i > 0 && j > 0){
      c[0] = va[i-1];
      for(int t = 1; t < i; ++t){
        c[t] = max(c[t-1], va[i-t-1]);
      }
      int u;
      if(c.back() >  vb[0]) u = upper_bound(c.begin(), c.end(), vb[0])-c.begin(); 
      else u = i;
      if(u==i){
        d[0]  =  i;
      }  
      else d[0] = i-1-u;  
      for(int t = 1; t < vb.size(); ++t){
        int r = vb[t];
        u = upper_bound(c.begin(), c.begin()+max(0LL, i-d[t-1]-1), r) - c.begin();
        if(u== max(0LL, i-d[t-1]-1)) d[t] = i;
        else d[t] = i-1- u;
      }
      g.push_back(vector<int>());
      reverse(d.begin(), d.end());
      reverse(vb.begin(), vb.end());
      for(int t =0; t < i; ++t){
        while(!d.empty() && d.back() == t){
          g.back().push_back(vb.back());
          d.pop_back();
          vb.pop_back();
        }
        g.back().push_back(va[t]);
      }
      while(!vb.empty()){
        g.back().push_back(vb.back());
        vb.pop_back();
      }
    }
    else{
      while(!vb.empty()){
        g.back().push_back(vb.back());
        vb.pop_back();
      }
      while(!va.empty()){
        g.back().push_back(va.back());
        va.pop_back();
      }
    }
  }
  sort(g.begin(), g.end(), [&](vector<int> x, vector<int> y){
    for(int i=0; i< k; ++i){
      if(x[i] > y[i]) return false;
      if(x[i] < y[i]) return true;
    }
    return false;
  });
  for(int x : g[0]) cout << x << " ";
	return 0;
}

